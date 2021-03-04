#include "hello_triangle_plugin.h"
#include "imgui.h"
#include <stdio.h>

#include <GL/gl3w.h>


void HelloTrianglePlugin::Init()
{
	printf("init");
	this->window = true;
	this->color = (void *)(new ImVec4(0.0f, 0.0f, 0.0f, 0.0f));


	// ³õÊ¼»¯ VAO, VBO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);
	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	// ±àÒëshader
	this->vertexShader = this->CompileShader(this->vertexShaderSource, GL_VERTEX_SHADER);
	this->fragmentShader = this->CompileShader(this->fragmentShaderSource, GL_FRAGMENT_SHADER);

	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, this->vertexShader);
	glAttachShader(this->shaderProgram, this->fragmentShader);
	glLinkProgram(this->shaderProgram);

	glDeleteShader(this->vertexShader);
	glDeleteShader(this->fragmentShader);
}

void HelloTrianglePlugin::Run()
{
	printf("run");
}

void HelloTrianglePlugin::Window() 
{
	ImGui::Begin("Hello Triangle", &this->window);	

	ImGui::ColorEdit4("MyColor##2f", (float*)this->color, ImGuiColorEditFlags_Float);

	ImGui::End();
}