#include "AutomatedBehaviours.hpp"

AutomatedBehaviours::AutomatedBehaviours(glm::mat4* transform)
	: m_heading(glm::vec3(0,0,0)), m_angle(0), m_acceleration(0), m_topSpeed(0.05),		// REMEMBER TO CHANGE HEADING BACK TO 0,0,0 AFTER TESTING
	m_pTransform(transform), m_rotationSpeed(0.05)
{

}

void AutomatedBehaviours::accelerate(float topSpeed)
{
	if (topSpeed > 0 && m_acceleration < topSpeed)
		m_acceleration += 0.001;

	if (topSpeed < 0 && m_acceleration > topSpeed)
		m_acceleration -= 0.001;

	*m_pTransform = glm::translate(*m_pTransform, glm::normalize(m_heading) * m_acceleration);
}

#include <iostream>
void AutomatedBehaviours::seek(glm::vec3 targetPosition)
{
	glm::mat4 transform = *m_pTransform;			// dereference
	glm::vec3 position = glm::vec3(transform[3]);	//get position


	glm::vec3 newHeading = glm::normalize(targetPosition - position);
	//std::cout << newHeading.x << ", " << newHeading.y << ", " << newHeading.z << "\n";
	//std::cout << "Target: " << targetPosition.x << ", " << targetPosition.y << ", " << targetPosition.z << " position:  " << position.x << ", " << position.y << ", " << position.z << "\n";
	//std::cout << "angle: " << m_angle << " || " << angle_XZ(m_heading) << " - " << angle_XZ(newHeading) << " = " << angle_XZ(m_heading) - angle_XZ(newHeading) << "\n";

	if (angle_XZ(m_heading) < angle_XZ(newHeading))       //turn left
	{
		if (angle_XZ(m_heading) - angle_XZ(newHeading) > glm::pi<float>())        // makes it smooth if angle goes from 360 - 0 degreees
		{
			m_angle -= m_rotationSpeed;
			*m_pTransform = glm::rotate(*m_pTransform, -m_rotationSpeed, glm::vec3(0, 1, 0));
		}
		else
		{
			m_angle += m_rotationSpeed;
			*m_pTransform = glm::rotate(*m_pTransform, m_rotationSpeed, glm::vec3(0, 1, 0));
		}
	}

	if (angle_XZ(m_heading) > angle_XZ(newHeading))       //turn right
	{
		if (angle_XZ(m_heading) - angle_XZ(newHeading) < -glm::pi<float>())       //  makes it smooth if angle goes from 360 - 0 degreees
		{
			m_angle += m_rotationSpeed;
			*m_pTransform = glm::rotate(*m_pTransform, m_rotationSpeed, glm::vec3(0, 1, 0));
		}
		else
		{
			m_angle -= m_rotationSpeed;
			*m_pTransform = glm::rotate(*m_pTransform, -m_rotationSpeed, glm::vec3(0, 1, 0));
		}
	}

	//updateHeading();
	m_heading = newHeading;
}

void AutomatedBehaviours::updateHeading()
{
	if (m_angle > glm::pi<float>())
		m_angle = -glm::pi<float>();
	if (m_angle < -glm::pi<float>())
		m_angle = glm::pi<float>();

	m_heading = glm::normalize(glm::vec3(cos(glm::radians(m_angle)), 0, sin(glm::radians(m_angle))));
}


// UTILITY FUNCTIONS SHOULD GO IN SEPERATE CLASS //

float AutomatedBehaviours::angle_XZ(glm::vec3 vector)
{
	if(vector.x == 0 && vector.z == 0)
		return 0;
	else if (vector.z < 0 || (vector.x < 0 && vector.z < 0))     // adding 180 or 360 deg keeps the result between 0 and 360 deg 
		return(atan(vector.x / vector.z) + 180 * (glm::pi<float>() / 180));
	else if (vector.x < 0)
		return(atan(vector.x / vector.z) + 360 * (glm::pi<float>() / 180));
	else
		return(atan(vector.x / vector.z));
}