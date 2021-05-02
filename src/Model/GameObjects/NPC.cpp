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
	if(glm::distance(m_position, targetPosition) > 10)
	{
		seek(targetPosition);
		accelerate(0.5f);
	}
	// END SUDO STATE MACHINE

    ModelManager::getInstance().DrawModel(modelID, m_transform);
}

void NPC::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}