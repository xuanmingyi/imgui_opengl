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
			fprintf(stderr, "ERROR::SHADER::COMPILATION_FAILED\n%s\n", infoLog);
			return -1;
		}
		
		return shader;
	};

	unsigned int LinkProgram(unsigned int shader1, unsigned int shader2) {
		unsigned int program;
		int success;
		char infoLog[512];

		program = glCreateProgram();
	
		glAttachShader(program, shader1);
		glAttachShader(program, shader2);
		glLinkProgram(program);

		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(program, 512, nullptr, infoLog);
			fprintf(stderr, "ERROR::PROGRAM::LINK_FAILED\n%s\n", infoLog);
			return -1;
		}

		glDeleteShader(shader1);
		glDeleteShader(shader2);
		return program;
	}
};

