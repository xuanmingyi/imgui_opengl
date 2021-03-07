#include "texture_plugin.h"
#include <stdio.h>
#include <GL/gl3w.h>

#include "imgui.h"

void TexturePlugin::Init()
{
	this->window = true;
	this->color = (void*)(new ImVec4(0.3f, 0.8f, 0.1f, 1.0f));

	// ±àÒëshader
	this->vertexShader = this->CompileShader(this->vertexShaderSource, GL_VERTEX_SHADER);
	this->fragmentShader = this->CompileShader(this->fragmentShaderSource, GL_FRAGMENT_SHADER);
	this->shaderProgram = this->LinkProgram(this->vertexShader, this->fragmentShader);

	// ³õÊ¼»¯ VAO, VBO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	this->colorLocation = glGetUniformLocation(this->shaderProgram, "color");
}

void TexturePlugin::Run()
{
	glUseProgram(this->shaderProgram);
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void TexturePlugin::Window()
{
	ImGui::Begin("Texutre", &this->window);

	ImGui::End();
}