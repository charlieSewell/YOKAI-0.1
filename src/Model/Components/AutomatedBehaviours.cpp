#include "AutomatedBehaviours.hpp"

AutomatedBehaviours::AutomatedBehaviours(glm::mat4* transform)
	: m_heading(glm::vec3(0)), m_angle(0), m_acceleration(0), m_topSpeed(0.005),
	m_pTransform(transform), m_rotationSpeed(0.05)
{

}

void AutomatedBehaviours::accelerate(float topSpeed)
{
	if (topSpeed > 0 && m_acceleration < topSpeed)
		m_acceleration += 0.01;

	if (topSpeed < 0 && m_acceleration > topSpeed)
		m_acceleration -= 0.01;

	glm::mat4 translation = glm::translate(glm::mat4(1.f), glm::normalize(m_heading) * m_acceleration);
	*m_pTransform = translation * *m_pTransform;
}

void AutomatedBehaviours::decelerate()
{
	if (m_acceleration > 0)
		m_acceleration -= 0.01;

	if (m_acceleration < 0)
		m_acceleration += 0.01;

	glm::mat4 translation = glm::translate(glm::mat4(1.f), glm::normalize(m_heading) * m_acceleration);
	*m_pTransform = translation * *m_pTransform;
}

void AutomatedBehaviours::seek(glm::vec3 targetPosition)
{
	glm::mat4 transform = *m_pTransform;			// dereference
	glm::vec3 position = glm::vec3(transform[3]);	//get position		//this won't need to happen once transform class is made

	glm::vec3 targetHeading = (targetPosition - position);

	if (angle_XZ(m_heading) < angle_XZ(targetHeading))  
	{
		if(angle_XZ(targetHeading) - angle_XZ(m_heading) > m_rotationSpeed)		// greater than rotation speed as a buffer to stop unecesary rotation
		{
			if(angle_XZ(m_heading) - angle_XZ(targetHeading) > (glm::pi<float>()))		// if difference is greater than pi, it's quicker to turn the other way
			{
				m_angle -= m_rotationSpeed;
				*m_pTransform = glm::rotate(*m_pTransform, m_rotationSpeed, glm::vec3(0, 1, 0));		// turn left
			}
			else
			{
				m_angle += m_rotationSpeed;
				*m_pTransform = glm::rotate(*m_pTransform, -m_rotationSpeed, glm::vec3(0, 1, 0));		// turn right
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
				*m_pTransform = glm::rotate(*m_pTransform, -m_rotationSpeed, glm::vec3(0, 1, 0));		// turn right
			}
			else
			{
				m_angle -= m_rotationSpeed;
				*m_pTransform = glm::rotate(*m_pTransform, m_rotationSpeed, glm::vec3(0, 1, 0));		// turn left
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