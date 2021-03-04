#include "hello_triangle_plugin.h"
#include "imgui.h"
#include <stdio.h>


void HelloTrianglePlugin::Init()
{
	printf("init");
	this->window = true;
}

void HelloTrianglePlugin::Run()
{
	printf("run");
}

void HelloTrianglePlugin::Window() 
{
	ImVec4 color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

	ImGui::Begin("Hello Triangle", &this->window);	

	ImGui::ColorEdit4("MyColor##2f", (float*)&color, ImGuiColorEditFlags_Float);

	ImGui::End();
}