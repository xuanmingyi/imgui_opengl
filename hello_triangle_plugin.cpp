#include <iostream>
#include <fstream>
#include <stdio.h>
#include <GL/gl3w.h>

#include "hello_triangle_plugin.h"
#include "imgui.h"
#include "shader.h"


void HelloTrianglePlugin::Init()
{
	P = new Program("shaders/hello_triangle/vertex.txt", "shaders/hello_triangle/fragment.txt");

	this->color = (void *)(new ImVec4(0.3f, 0.8f, 0.1f, 1.0f));

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

	this->colorLocation = glGetUniformLocation(P->GetProgram(), "color");
}

void HelloTrianglePlugin::Run()
{
	glUseProgram(P->GetProgram());

	glUniform4f(this->colorLocation,
		((ImVec4*)this->color)->x, ((ImVec4*)this->color)->y,
		((ImVec4*)this->color)->z, ((ImVec4*)this->color)->w);

	glBindVertexArray(this->VAO);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void HelloTrianglePlugin::Window() 
{
	ImGui::ColorEdit4("MyColor##2f", (float*)this->color, ImGuiColorEditFlags_Float);
}