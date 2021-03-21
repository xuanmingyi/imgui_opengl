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

	// ��������ƶ�
	void hanldeMouseMove(GLfloat xoffset, GLfloat yoffset) {
		
	}

	// �������������� 1.0, MOUSE_ZOOM֮��
	void handleMouseScroll(GLfloat yoffset) {
		cout << yoffset << endl;
	}

	// ʹpitch yaw�Ƕȱ����ں���Χ��
	void normalizeAngle(){
	}

	// ����forward side����
	void updateCameraVectors() {
	}

public:
	glm::vec3 forward, up, side, viewUp, position; // �������
	GLfloat yawAngle, pitchAngle; // ŷ����
	GLfloat moveSpeed, mouse_sensitivity, mouse_zoom; // ���ѡ��
};
