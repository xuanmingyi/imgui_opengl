#pragma once
#include "plugin.h"

class HelloTrianglePlugin: public Plugin
{
public:
	void Init();
	void Window();
	void Run();

private:
	void* color;

	float vertices[12] = {
		0.15f, -0.75f, 0.0f,
		0.95f, -0.75f, 0.0f,
		0.95f,  0.75f, 0.0f,
		0.15f,  0.75f, 0.0f,
	};

	unsigned int VAO;
	unsigned int VBO;

	unsigned int colorLocation;
};

