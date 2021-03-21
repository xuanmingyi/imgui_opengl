#pragma once
#include "plugin.h"


class TexturePlugin: public Plugin
{
public:
	void Init();
	void Window();
	void Run();

private:
	unsigned int LoadImage(const char* path);

	bool window;
	void* color;

	float vertices[20] = {
		0.15f, -0.75f, 0.0f, 0.0f, 0.0f,
		0.95f, -0.75f, 0.0f, 1.0f, 0.0f,
		0.95f,  0.75f, 0.0f, 1.0f, 1.0f,
		0.15f,  0.75f, 0.0f, 0.0f, 1.0f,
	};

	unsigned int VAO;
	unsigned int VBO;
	unsigned int texture;

	unsigned int colorLocation;
};