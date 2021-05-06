#pragma once

#include "Model/Transform.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Controller/EventManager.hpp"

class AutomatedBehaviours
{
public:
	
protected:
	AutomatedBehaviours(glm::mat4* transform);

	void accelerate(float topSpeed);
	void decelerate();
	void seek(glm::vec3 tartgetPosition);


	glm::vec3 m_heading;
	float m_angle;
	float m_topSpeed;
	float m_acceleration;
	float m_rotationSpeed;

private:
	glm::mat4* m_pTransform;
	void updateHeading();
	float angle_XZ(glm::vec3 vector);
};