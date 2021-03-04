#pragma once
#include "plugin.h"

class HelloTrianglePlugin: public Plugin
{
public:
	void Init();
	void Window();
	void Run();

private:
	bool window;
};

