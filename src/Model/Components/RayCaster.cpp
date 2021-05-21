//
// Created by charl on 20/05/2021.
//

#include "RayCaster.hpp"
int RayCaster::CastRay(glm::vec3 startPosition,glm::vec3 direction,float distance)
{
    glm::vec3 extrapolatedVec = direction * distance + startPosition;
    glm::vec3 start = startPosition;
    rp3d::Ray testRay(ReactMath::glmVecToRP3d(start), ReactMath::glmVecToRP3d(extrapolatedVec));
    PhysicsSystem::getInstance().physicsWorld->raycast(testRay,this);
    if(lastHit != -1)
    {
        unsigned int gameObjID = PhysicsSystem::getInstance().getRigidBody(lastHit)->getGameObjectID();
        lastHit = -1;
        return  gameObjID;
    }
    lastHit = -1;
    return -1;
}

rp3d::decimal RayCaster::notifyRaycastHit(const rp3d::RaycastInfo& info)
{
    if(info.collider != nullptr){
        if(info.collider->getCollisionShape()->getType() == rp3d::CollisionShapeType::CONCAVE_SHAPE)
        {
            lastHit = -1;
            return rp3d::decimal(0.0);
        }
		else if (info.collider->getEntity().id == excludedColliderID)
		{
			lastHit = -1;
			return rp3d::decimal(1.0);
		}
        else if(info.collider->getEntity().id == ownColliderID)
		{
            lastHit = -1;
            return rp3d::decimal(1.0);
        }
        else
		{
            lastHit = info.collider->getEntity().id;
            return rp3d::decimal(0.0);
        }
    }
    lastHit = -1;
    // Return a fraction of 1.0 to gather all hits
    return rp3d::decimal(1.0);
}

void RayCaster::setOwnColliderID(int ownColliderID)
{ 
	this->ownColliderID = ownColliderID;
}

void RayCaster::setExcludedColliderID(int id)
{
	excludedColliderID = id;
}