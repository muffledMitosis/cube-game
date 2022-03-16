#include "Camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include <glm/glm.hpp>

namespace World {
	Camera::Camera(unsigned int width, unsigned int height)
	{
		this->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	}

	void Camera::update()
	{
		this->direction.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->direction.y = sin(glm::radians(this->pitch));
		this->direction.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->front = glm::normalize(this->direction);
	}

	glm::mat4 Camera::getView()
	{
		return glm::lookAt(this->position, this->position + this->front, this->up);
	}

	Camera::~Camera()
	{
	}

	glm::mat4 Camera::getProj()
	{
		return this->projection;
	}
}
