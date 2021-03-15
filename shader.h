#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <GL/gl3w.h>
using namespace std;


class Program
{
public:
	Program(const char* vertex_filepath, const char *fragment_filepath);

	unsigned int GetProgram() {
		return program;
	}

private:
	string vertex_source;
	string fragment_source;

	void ReadFile(const char* filepath, string& source);
	unsigned int CompileShader(const string& source, int type);
	unsigned int LinkProgram(unsigned int shader1, unsigned int shader2);

	unsigned int vertex_shader;
	unsigned int fragment_shader;

	unsigned int program;
};