#include "NPC.hpp"

NPC::NPC(std::string modelName)
	: GameObject(), m_behaviours(AutomatedBehaviours(m_transform))//, PhysicsComponent()
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}

void NPC::draw() 
{
	
	// SUDO STATE MACHINE
	glm::vec3 targetPosition = EMS::getInstance().fire(ReturnVec3Event::getPlayerPosition);

	m_behaviours.seek(targetPosition);
	if(glm::distance(m_transform.getPosition(), targetPosition) > 10)
		m_behaviours.accelerate(0.25f);
	else
		m_behaviours.decelerate();

	// END SUDO STATE MACHINE
	//m_transform.setPosition(m_transform.getPosition());
	m_transform.setPosition(glm::vec3(m_transform.getPosition().x, PhysicsManager::getInstance().checkTerrainHeight(m_transform.getPosition()), m_transform.getPosition().z));
	
	ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix());
}

void NPC::setCollider(float width, float length, float height)
{
	//registerAABB(&m_position, width, length, height);
}

