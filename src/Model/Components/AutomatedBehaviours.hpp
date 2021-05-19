#pragma once

#include "Model/Components/Transform.hpp"
#include "Controller/EventManager.hpp"

class AutomatedBehaviours
{
public:
	
//protected:
	AutomatedBehaviours(Transform& transform);

	void accelerate(float topSpeed);
	void decelerate();
	void seek(glm::vec3 tartgetPosition);


	glm::vec3 heading;
	float angle;
	float topSpeed;
	float acceleration;
	float rotationSpeed;

private:
	Transform *m_transformPtr;
	void updateHeading();
	float angle_XZ(glm::vec3 vector);
};