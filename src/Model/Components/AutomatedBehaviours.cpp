#include "AutomatedBehaviours.hpp"

AutomatedBehaviours::AutomatedBehaviours(Transform& transform)
	: heading(glm::vec3(0)), angle(0), acceleration(0), topSpeed(0.005),		
	m_transformPtr(&transform), rotationSpeed(0.05)
{

}

void AutomatedBehaviours::accelerate(float topSpeed)
{
	if (topSpeed > 0 && acceleration < topSpeed)
		acceleration += 0.01;

	if (topSpeed < 0 && acceleration > topSpeed)
		acceleration -= 0.01;

	m_transformPtr->translatePostMultiply(glm::normalize(heading) * acceleration);
}

void AutomatedBehaviours::decelerate()
{
	if (acceleration > 0)
		acceleration -= 0.01;

	if (acceleration < 0)
		acceleration += 0.01;

	m_transformPtr->translatePostMultiply(glm::normalize(heading) * acceleration);
}

void AutomatedBehaviours::seek(glm::vec3 targetPosition)
{
	glm::vec3 targetHeading = (targetPosition - m_transformPtr->getPosition());

	if (angle_XZ(heading) < angle_XZ(targetHeading))  
	{
		if(angle_XZ(targetHeading) - angle_XZ(heading) > rotationSpeed)		// greater than rotation speed as a buffer to stop unecesary rotation
		{
			if(angle_XZ(heading) - angle_XZ(targetHeading) > (glm::pi<float>()))		// if difference is greater than pi, it's quicker to turn the other way
			{
				angle -= rotationSpeed;
				m_transformPtr->rotate(rotationSpeed, glm::vec3(0, 1, 0));			// turn left
			}
			else
			{
				angle += rotationSpeed;
				m_transformPtr->rotate(-rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
		}
	}
	else
	{
		if(angle_XZ(heading) - angle_XZ(targetHeading) > rotationSpeed)		// greater than rotation speed as a buffer to stop unecesary rotation
		{
			if (angle_XZ(heading) - angle_XZ(targetHeading) > (glm::pi<float>()))	// if difference is greater than pi, it's quicker to turn the other way
			{
				angle += rotationSpeed;
				m_transformPtr->rotate(-rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
			else
			{
				angle -= rotationSpeed;
				//*m_transformPtr = glm::rotate(*m_transformPtr, m_rotationSpeed, glm::vec3(0, 1, 0));		// turn left
				m_transformPtr->rotate(rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
		}
	}

	updateHeading();
}

void AutomatedBehaviours::updateHeading()
{
	if (angle > glm::pi<float>())
		angle = -glm::pi<float>();
	if (angle < -glm::pi<float>())
		angle = glm::pi<float>();

	heading = glm::vec3(cos(angle), 0, sin(angle));
}


// UTILITY FUNCTIONS SHOULD GO IN SEPERATE CLASS //

float AutomatedBehaviours::angle_XZ(const glm::vec3 vector)
{
		return(std::atan2f(vector.z, vector.x));
}