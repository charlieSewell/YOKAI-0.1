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

	//m_behaviours.rotationSpeed = 0.0025;
	//m_behaviours.rotationSpeed = 
	//m_behaviours.seek(targetPosition);
	m_behaviours.wander();
	if(glm::distance(m_transform.getPosition(), targetPosition) > 10)
		m_behaviours.accelerate(0.1f);
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

void NPC::test()
{
	std::cout << "Cool\n";
}

void NPC::registerClass()
{
	luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
		.deriveClass<NPC, GameObject>("NPC")
		.addFunction("test", &NPC::test)
		.endClass();
	std::cout << "registered\n";
}

