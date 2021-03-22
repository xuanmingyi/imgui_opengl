#pragma once

#include <GLFW/glfw3.h>


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


	// �������������� 1.0, MOUSE_ZOOM֮��
	void handleMouseScrool(GLfloat yoffset) {
		
	}

public:
	GLfloat mouse_zoom;
};
