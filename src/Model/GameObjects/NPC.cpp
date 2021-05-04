#include "NPC.hpp"

NPC::NPC(std::string modelName)
	: GameObject(), PhysicsComponent(), AutomatedBehaviours(&m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    setPosition(glm::vec3(0,0,0));
    setScale(glm::vec3(0,0,0));
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

