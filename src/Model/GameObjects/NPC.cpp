#include "NPC.hpp"

NPC::NPC(std::string modelName)
	: GameObject(), m_behaviours(AutomatedBehaviours(m_transform)), m_physicsComponent(m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    m_transform.setPosition(glm::vec3(0,0,0));
    m_transform.setScale(glm::vec3(0,0,0));
    animator.addModel(ModelManager::getInstance().GetModel(modelID));
    animator.setAnimation("ZombieIdle");
}
NPC::~NPC(){
    m_physicsComponent.deleteCollider();
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
void NPC::setCollider(float width, float height, float length)
{
    m_physicsComponent.registerAABB(ID,width, height, length);
    m_physicsComponent.getCollider()->SetBodyType(rp3d::BodyType::STATIC);
    m_physicsComponent.getCollider()->SetBounciness(0.0);
}
void NPC::update(float dt)
{
    m_physicsComponent.getCollider()->SetPosition(m_transform.getPosition());
    animator.BoneTransform(dt);
}
