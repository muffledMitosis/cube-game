#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "../Components/Component.hpp"

namespace World {
class Camera
{
public:
	glm::vec3 position = glm::vec3(0, 0, 3);
	glm::vec3 front = glm::vec3(0, 0, -1);
	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::vec3 direction;

	glm::mat4 projection;
	const float movementSpeed = 0.05f;

	float yaw = -90.0;
	float pitch = 0.0;

	std::vector<Component> components;

	Camera(unsigned int width, unsigned int height);
	~Camera();
	void update();
	glm::mat4 getView();

	glm::mat4 getProj();
};
}
