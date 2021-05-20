#pragma once

#include "Model/Components/Transform.hpp"
#include "Controller/EventManager.hpp"
#include "Controller/LuaManager.hpp"
#include <glm/gtc/random.hpp>

class AutomatedBehaviours
{
public:
	
//protected:
	AutomatedBehaviours(Transform& transform);

	void accelerate(float topSpeed);
	void decelerate();
	void seek(glm::vec3 tartgetPosition);
	void wander();
	

	static void registerClass();

	glm::vec3 heading;
	float angle;
	float topSpeed;
	float acceleration;
	float rotationSpeed;
	int state;

private:
	Transform *m_transformPtr;
	float m_wanderAngle;
	void updateHeading();
	float angle_XZ(glm::vec3 vector);
};