#pragma once
#include "plugin.h"


class TexturePlugin: public Plugin
{
public:
	void Init();
	void Window();
	void Run();

private:
	bool window;
	void* color;

	float vertices[12] = {
		0.15f, -0.75f, 0.0f,
		0.95f, -0.75f, 0.0f,
		0.95f,  0.75f, 0.0f,
		0.15f,  0.75f, 0.0f,
	};

	unsigned int VAO;
	unsigned int VBO;

	unsigned int vertexShader;
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n\0";

	unsigned int fragmentShader;
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"    FragColor = vec4(0.5, 0.5, 0.5, 1.0);\n"
		"}\n\0";

	unsigned int colorLocation;

	unsigned int shaderProgram;
};

