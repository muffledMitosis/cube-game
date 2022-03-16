#pragma once

#include <glm/glm.hpp>

namespace World {
class Camera
{
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 direction;

	glm::mat4 projection;

	float yaw = -90.0;
	float pitch = 0.0;

	Camera(unsigned int width, unsigned int height);
	~Camera();
	void update();
	glm::mat4 getView();

	glm::mat4 getProj();
};
}
