#pragma once
#include "plugin.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include <vector>
#include <sstream>

#include "shader.h"


struct Vertex {
	glm::vec3 position;
	glm::vec2 texCoords;
	glm::vec3 normal;
};


class ThreeDPlugin: public Plugin
{
public:
	void Init();
	void Window();
	void Run();

private:
	void LoadModel(const char* filepath);
	void SetupMesh();
	void LoadTexture(const char *filepath);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<std::string> faces;

	std::vector<Vertex> vertData;

	unsigned int VAO, VBO;

	unsigned int texture;

	Program* P;
};

