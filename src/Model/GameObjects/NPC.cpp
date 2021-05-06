#include "NPC.hpp"

#include <iostream>
NPC::NPC(std::string modelName)
	: GameObject(), PhysicsComponent(), AutomatedBehaviours(&m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    setPosition(glm::vec3(0,0,0));
    setScale(glm::vec3(0,0,0));

	glm::mat4 transform2 = glm::mat4(1.0f);
	glm::vec3 positionGLM;
	Transform transform;
	//transform.setPosition(100, 100, 100);
	transform.translate(100, 100, 100);
	transform2 = glm::translate(transform2, glm::vec3(100, 100, 100));

	transform.rotate(glm::radians(90.0f), glm::vec3(0, 1, 0));
	transform2 = glm::rotate(transform2, glm::radians(90.0f), glm::vec3(0, 1, 0));

	positionGLM = transform2[3];
	std::cout << "Position GLM:\t" << positionGLM.x << ", " << positionGLM.y << ", " << positionGLM.z << "\n";
	std::cout << "Position:\t" << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << "\n";
	
	transform.translate(100, 100, 100);
	transform2 = glm::translate(transform2, glm::vec3(100, 100, 100));

	positionGLM = transform2[3];
	std::cout << "Position GLM:\t" << positionGLM.x << ", " << positionGLM.y << ", " << positionGLM.z << "\n";
	std::cout << "Position:\t" << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << "\n";

	transform.rotate(glm::radians(-90.0f), glm::vec3(0, 1, 0));
	transform2 = glm::rotate(transform2, glm::radians(-90.0f), glm::vec3(0, 1, 0));

	positionGLM = transform2[3];
	std::cout << "Position GLM:\t" << positionGLM.x << ", " << positionGLM.y << ", " << positionGLM.z << "\n";
	std::cout << "Position:\t" << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << "\n";

	transform.translate(100, 100, 100);
	transform2 = glm::translate(transform2, glm::vec3(100, 100, 100));

	positionGLM = transform2[3];
	std::cout << "Position GLM:\t" << positionGLM.x << ", " << positionGLM.y << ", " << positionGLM.z << "\n";
	std::cout << "Position:\t" << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << "\n\n";

}

void NPC::draw() 
{
	// SUDO STATE MACHINE
	glm::vec3 targetPosition = EMS::getInstance().fire(ReturnVec3Event::getPlayerPosition);

	seek(targetPosition);
	if(glm::distance(getPosition(), targetPosition) > 10)
		accelerate(0.25f);
	else
		decelerate();

	// END SUDO STATE MACHINE

	// TODO: should come up with a better solution for this
	// (Physics uses m_position address so can't use getPosition for that)
	// Idealy I will make a transform
	m_position = getPosition();
	setPosition(glm::vec3(m_position.x, PhysicsManager::getInstance().checkTerrainHeight(m_position), m_position.z));

	ModelManager::getInstance().DrawModel(modelID, m_transform);
}

void NPC::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}

