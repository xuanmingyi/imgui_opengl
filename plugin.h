#pragma once
#include <GL/gl3w.h>
#include <stdio.h>


class Plugin
{
public:
	// 初始化 只调用一次
	virtual void Init() = 0;

	// 显示界面
	virtual void Window() = 0;

	// 内核逻辑
	virtual void Run() = 0;

	unsigned int CompileShader(const char* source, int type) {
		unsigned int shader;
		int success;
		char infoLog[512];

		shader = glCreateShader(type);
	
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			fprintf(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);
			return -1;
		}
		
		return shader;
	};
};

