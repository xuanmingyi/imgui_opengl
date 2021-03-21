#include "shader.h"

Program::Program(const char* vertex_filepath, const char* fragment_filepath){
	ReadFile(vertex_filepath, vertex_source);
	ReadFile(fragment_filepath, fragment_source);

	vertex_shader = CompileShader(vertex_source, GL_VERTEX_SHADER);
	fragment_shader = CompileShader(fragment_source, GL_FRAGMENT_SHADER);

	program = LinkProgram(vertex_shader, fragment_shader);
}

void Program::ReadFile(const char* filepath, string& source) {
	ifstream f(filepath, ios::binary | ios::in);
	if (!f.is_open()) {
		cerr << filepath << " is not opened!" << endl;
		return;
	}
	f.seekg(0, ios::end);
	int length = f.tellg();
	char* buffer = new char[length];
	f.seekg(0, ios::beg);
	f.read(buffer, length);
	f.close();
	source = string(buffer, length);
	delete []buffer;
}

unsigned int Program::CompileShader(const string& source, int type) {
	unsigned int shader = -1;
	int success;
	char info_log[512];

	shader = glCreateShader(type);

	const char* pointer = source.c_str();
	glShaderSource(shader, 1, &pointer, nullptr);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, nullptr, info_log);
		cerr << "ERROR::SHADER::CIMPILATION_FAILED" << endl << info_log << endl;
		return -1;
	}
	return shader;
}

unsigned int Program::LinkProgram(unsigned int shader1, unsigned int shader2) {
	int success;
	char info_log[512];

	program = glCreateProgram();
	glAttachShader(program, shader1);
	glAttachShader(program, shader2);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, nullptr, info_log);
		cerr << "ERROR::PROGRAM::LINK_FAILED" << endl << info_log;
		return -1;
	}
	return program;
}