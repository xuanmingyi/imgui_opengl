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
	// 初始化 只调用一次
	virtual void Init() = 0;

	// 显示界面
	virtual void Window() = 0;

	// 内核逻辑
	virtual void Run() = 0;

	Program *P;
};

