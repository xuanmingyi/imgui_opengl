#include "texture_plugin.h"
#include <stdio.h>
#include <GL/gl3w.h>

#include "imgui.h"

#include "shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
	

void TexturePlugin::Init()
{
	P = new Program("shaders/texture/vertex.txt", "shaders/texture/fragment.txt");
	this->texture = LoadImage("images/a.jpg");

	this->window = true;
	this->color = (void*)(new ImVec4(0.3f, 0.8f, 0.1f, 1.0f));

	// 初始化 VAO, VBO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

	// 坐标数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// 纹理数据
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	this->colorLocation = glGetUniformLocation(P->GetProgram(), "color");
}

void TexturePlugin::Run()
{
	glUseProgram(P->GetProgram());
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void TexturePlugin::Window()
{
}

unsigned int TexturePlugin::LoadImage(const char *filepath) {
	unsigned int texture;
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
	}else {
		cerr << "failed to load texture" << endl;
	}
	stbi_image_free(data);
	return texture;
}