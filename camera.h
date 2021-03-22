#pragma once

#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iomanip>


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


	// 处理键盘案件后方向移动
	void handleKeyPress(Camera_Movement direction, GLfloat deltaTime) {
		GLfloat velocity = this->moveSpeed * deltaTime;

		switch (direction) {

		case FORWARD:
			this->position += this->forward * velocity;
			break;
		case BACKEND:
			this->position -= this->forward * velocity;
			break;
		case LEFT:
			this->position -= this->side * velocity;
			break;
		case RIGHT:
			this->position += this->side * velocity;
			break;
		default:
			break;
		}
	}

	// 处理鼠标移动
	void handleMouseMove(GLfloat xoffset, GLfloat yoffset) {
		xoffset *= this->mouse_sensitivity;
		yoffset *= this->mouse_sensitivity;

		this->pitchAngle += yoffset;
		this->yawAngle += xoffset;
	}


	// 处理鼠标滚轮缩放 1.0, MOUSE_ZOOM之间
	void handleMouseScroll(GLfloat yoffset) {
		if (this->mouse_zoom >= 1.0f && this->mouse_zoom <= MOUSE_ZOOM)
			this->mouse_zoom -= this->mouse_sensitivity * yoffset;
		if (this->mouse_zoom <= 1.0f)
			this->mouse_zoom = 1.0f;
		if (this->mouse_zoom >= 45.0f)
			this->mouse_zoom = 45.0f;
	}

	void normalizeAngle() {
	
	}

public:
	glm::vec3 forward, up, side, viewUp, position; // 相机属性

	GLfloat yawAngle, pitchAngle; // 欧拉角

	GLfloat moveSpeed, mouse_sensitivity, mouse_zoom; // 相机选项
};
