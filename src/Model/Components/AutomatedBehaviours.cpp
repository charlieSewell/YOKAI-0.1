#include "AutomatedBehaviours.hpp"

AutomatedBehaviours::AutomatedBehaviours(Transform& transform)
	: m_heading(glm::vec3(0)), m_angle(0), m_acceleration(0), m_topSpeed(0.005),		
	m_transformPtr(&transform), m_rotationSpeed(0.05)
{

}

void AutomatedBehaviours::accelerate(float topSpeed)
{
	if (topSpeed > 0 && m_acceleration < topSpeed)
		m_acceleration += 0.01;

	if (topSpeed < 0 && m_acceleration > topSpeed)
		m_acceleration -= 0.01;

	m_transformPtr->translatePostMultiply(glm::normalize(m_heading) * m_acceleration);
}

void AutomatedBehaviours::decelerate()
{
	if (m_acceleration > 0)
		m_acceleration -= 0.01;

	if (m_acceleration < 0)
		m_acceleration += 0.01;

	m_transformPtr->translatePostMultiply(glm::normalize(m_heading) * m_acceleration);
}

void AutomatedBehaviours::seek(glm::vec3 targetPosition)
{
	glm::vec3 targetHeading = (targetPosition - m_transformPtr->getPosition());

	if (angle_XZ(m_heading) < angle_XZ(targetHeading))  
	{
		if(angle_XZ(targetHeading) - angle_XZ(m_heading) > m_rotationSpeed)		// greater than rotation speed as a buffer to stop unecesary rotation
		{
			if(angle_XZ(m_heading) - angle_XZ(targetHeading) > (glm::pi<float>()))		// if difference is greater than pi, it's quicker to turn the other way
			{
				m_angle -= m_rotationSpeed;
				m_transformPtr->rotate(m_rotationSpeed, glm::vec3(0, 1, 0));			// turn left
			}
			else
			{
				m_angle += m_rotationSpeed;
				m_transformPtr->rotate(-m_rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
		}
	}
	else
	{
		if(angle_XZ(m_heading) - angle_XZ(targetHeading) > m_rotationSpeed)		// greater than rotation speed as a buffer to stop unecesary rotation
		{
			if (angle_XZ(m_heading) - angle_XZ(targetHeading) > (glm::pi<float>()))	// if difference is greater than pi, it's quicker to turn the other way
			{
				m_angle += m_rotationSpeed;
				m_transformPtr->rotate(-m_rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
			else
			{
				m_angle -= m_rotationSpeed;
				//*m_transformPtr = glm::rotate(*m_transformPtr, m_rotationSpeed, glm::vec3(0, 1, 0));		// turn left
				m_transformPtr->rotate(m_rotationSpeed, glm::vec3(0, 1, 0));			// turn right
			}
		}
	}

	updateHeading();
}

void AutomatedBehaviours::updateHeading()
{
	if (m_angle > glm::pi<float>())
		m_angle = -glm::pi<float>();
	if (m_angle < -glm::pi<float>())
		m_angle = glm::pi<float>();

	m_heading = glm::vec3(cos(m_angle), 0, sin(m_angle));
}


// UTILITY FUNCTIONS SHOULD GO IN SEPERATE CLASS //

float AutomatedBehaviours::angle_XZ(const glm::vec3 vector)
{
		return(std::atan2f(vector.z, vector.x));
}