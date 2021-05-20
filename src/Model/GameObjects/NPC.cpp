#include "NPC.hpp"

NPC::NPC(std::string modelName)
	: GameObject(), m_behaviours(AutomatedBehaviours(m_transform))//, (m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    m_transform.setPosition(glm::vec3(0,0,0));
    m_transform.setScale(glm::vec3(0,0,0));
    animator.addModel(ModelManager::getInstance().GetModel(modelID));
    animator.setAnimation("ZombieIdle");

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
	m_transform.setPosition(glm::vec3(m_transform.getPosition().x, TerrainFactory::getInstance().heightAt(m_transform.getPosition().x,m_transform.getPosition().z), m_transform.getPosition().z));

	
	ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix(),animator.finalTransforms);
}
void NPC::setCollider(float x, float y, float z)
{

}
void NPC::update(float dt)
{
    animator.BoneTransform(dt);
}
