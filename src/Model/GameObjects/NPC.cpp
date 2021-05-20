#include "NPC.hpp"

NPC::NPC(std::string modelName)
	: GameObject(), m_behaviours(AutomatedBehaviours(m_transform))//, (m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    m_transform.setPosition(glm::vec3(0,0,0));
    m_transform.setScale(glm::vec3(0,0,0));
    animator.addModel(ModelManager::getInstance().GetModel(modelID));
	animator.setAnimation("ZombieWalk");

	LuaManager::getInstance().runScript("content/Scripts/stateMachine.lua");
	luaUpdate = luabridge::getGlobal(LuaManager::getInstance().getState(), "update");
}

void NPC::draw() 
{
	// SUDO STATE MACHINE
	//glm::vec3 targetPosition = EMS::getInstance().fire(ReturnVec3Event::getPlayerPosition);

	//m_behaviours.rotationSpeed = 0.005;
	//m_behaviours.rotationSpeed = 
	//m_behaviours.seek(targetPosition);
	//m_behaviours.wander();
	/*if(glm::distance(m_transform.getPosition(), targetPosition) > 10)
		m_behaviours.accelerate(0.01f);
	else
		m_behaviours.decelerate();
	*/

	// END SUDO STATE MACHINE
	//m_transform.setPosition(m_transform.getPosition());
	m_transform.setPosition(glm::vec3(m_transform.getPosition().x, TerrainFactory::getInstance().heightAt(m_transform.getPosition().x,m_transform.getPosition().z), m_transform.getPosition().z));

	
	ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix(),animator.finalTransforms);
}
void NPC::setCollider(float x, float y, float z)
{

}

void NPC::registerClass()
{
	AutomatedBehaviours::registerClass();
	Animator::registerClass();

	luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
		.deriveClass<NPC, GameObject>("NPC")
		.addProperty("behaviours", &NPC::m_behaviours)
		.addProperty("animator", &NPC::animator)
		.endClass();
}

void NPC::update(float dt)
{
	luaUpdate(this, EMS::getInstance().fire(ReturnVec3Event::getPlayerPosition));
    animator.BoneTransform(dt);
}
