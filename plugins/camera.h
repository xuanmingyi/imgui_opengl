#pragma once

#include <GLFW/glfw3.h>

#include "glm/glm.hpp"

#include <iostream>
using namespace std;

enum Camera_Movement {
	FORWARD,
	BACKEND,
	LEFT,
	RIGHT
};

const GLfloat YAW = 0.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat MOUSE_SENSITIVTY = 0.05f;
const GLfloat MOUSE_ZOOM = 45.0f;
const float MAX_PITCH_ANGLE = 89.0f;


class Camera {
public:

	// 处理鼠标移动
	void hanldeMouseMove(GLfloat xoffset, GLfloat yoffset) {
		
	}

	// 处理鼠标滚轮缩放 1.0, MOUSE_ZOOM之间
	void handleMouseScroll(GLfloat yoffset) {
		cout << yoffset << endl;
	}

	// 使pitch yaw角度保持在合理范围内
	void normalizeAngle(){
	}

	// 计算forward side向量
	void updateCameraVectors() {
	}

public:
	glm::vec3 forward, up, side, viewUp, position; // 相机属性
	GLfloat yawAngle, pitchAngle; // 欧拉角
	GLfloat moveSpeed, mouse_sensitivity, mouse_zoom; // 相机选项
};
