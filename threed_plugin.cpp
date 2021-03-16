#include "threed_plugin.h"
#include "stb_image.h"


void ThreeDPlugin::Init() {

    // https://github.com/wangdingqiao/noteForOpenGL/blob/master/modelLoading/simpleObjLoader

	LoadModel("cube.txt");

	SetupMesh();

	LoadTexture("images/a.jpg");

	P = new Program("shaders/3d/vertex.txt", "shaders/3d/fragment.txt");
}

void ThreeDPlugin::Window() {
}

void ThreeDPlugin::Run() {
	glUseProgram(P->GetProgram());
	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(P->GetProgram(), "tex"), 0);
	glDrawArrays(GL_TRIANGLES, 0, vertData.size());
	glBindVertexArray(0);
}

void ThreeDPlugin::LoadModel(const char *filepath) {
	std::ifstream file(filepath);
	string line;
	while (getline(file, line)) {
		if (line.substr(0, 2) == "vt") {
			// 顶点纹理坐标数据
			istringstream s(line.substr(2));
			glm::vec2 p;
			s >> p.x >> p.y;
			texCoords.push_back(p);
		}
		else if (line.substr(0, 2) == "vn") {
			// 顶点法向量数据
			istringstream s(line.substr(2));
			glm::vec3 p;
			s >> p.x >> p.y >> p.z;
			normals.push_back(p);
		}
		else if (line.substr(0, 1) == "v") {
			// 顶点数据
			istringstream s(line.substr(1));
			glm::vec3 p;
			s >> p.x >> p.y >> p.z;
			positions.push_back(p);
		}
		else if (line.substr(0, 1) == "f") {
			// 面数据
			istringstream s(line.substr(1));
			string s1, s2, s3;
			s >> s1 >> s2 >> s3;
			faces.push_back(s1);
			faces.push_back(s2);
			faces.push_back(s3);
		}
		else if (line.substr(0, 1) == "#") {
			// 注释
		}
		else {
			cout << line << endl;
		}
	}

	for (auto i = faces.begin(); i != faces.end(); i++) {
		istringstream s(*i);
		char c;
		int i1, i2, i3;
		s >> i1 >> c >> i2 >> c >> i3;

		Vertex vertex;
		vertex.position = positions.at(i1 - 1);
		vertex.texCoords = texCoords.at(i2 - 1);
		vertex.normal = normals.at(i3 - 1);

		vertData.push_back(vertex);
	}
}

void ThreeDPlugin::SetupMesh() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertData.size(),
		&vertData[0], GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// texcoord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);

	// normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)(5 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void ThreeDPlugin::LoadTexture(const char *filepath) {
	int width, height, nr;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	unsigned char* data = stbi_load(filepath, &width, &height, &nr, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		cerr << "failed to load texture" << endl;
	}
	stbi_image_free(data);
}