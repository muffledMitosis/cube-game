#include "../epch.hpp"
#include "Camera.hpp"

namespace World {

	Camera::Camera(unsigned int width, unsigned int height)
	{
		this->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		this->components.push_back(InputCapture(GLFW_KEY_W, [&](){
    	this->position += this->movementSpeed * this->front;
		}));

		this->components.push_back(InputCapture(GLFW_KEY_S, [&](){
        this->position -= this->movementSpeed * this->front;
		}));

		this->components.push_back(InputCapture(GLFW_KEY_A, [&](){
        this->position -= glm::normalize(glm::cross(this->front, this->up)) * this->movementSpeed;
		}));

		this->components.push_back(InputCapture(GLFW_KEY_D, [&](){
        this->position += glm::normalize(glm::cross(this->front, this->up)) * this->movementSpeed;
		}));

		InputCapture::attachMouseFunction([&](GLFWwindow* window, double xpos, double ypos){
			static bool firstTime = true;
			static double px = 0;
			static double py = 0;

			if(firstTime)
			{
				px = xpos;
				py = ypos;
				firstTime = false;
			}

			double dx = xpos - px;
			double dy = ypos - py;
			px = xpos;
			py = ypos;

			double sensitivity = 0.01;
			dx *= sensitivity;
			dy *= sensitivity;

			this->yaw += dx;
			this->pitch -= dy;
		});
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
