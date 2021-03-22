#pragma once
#include <GL/gl3w.h>
#include <stdio.h>

#include <map>
#include <string>
#include "shader.h"

using namespace std;


class Plugin
{
public:
	// ��ʼ�� ֻ����һ��
	virtual void Init() = 0;

	// ��ʾ����
	virtual void Window() = 0;

	// �ں��߼�
	virtual void Run() = 0;

	Program *P;
};

