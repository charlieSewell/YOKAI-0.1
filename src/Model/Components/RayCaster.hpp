//
// Created by charl on 20/05/2021.
//
#include "Controller/Physics/PhysicsSystem.hpp"
#pragma once
class RayCaster : public rp3d::RaycastCallback {

public:
    RayCaster() = default;
    int CastRay(glm::vec3 startPosition,glm::vec3 direction,float distance);
    virtual rp3d::decimal notifyRaycastHit(const rp3d::RaycastInfo &info);
    int lastHit = -1;
    void setOwnColliderID(int ownColliderID);
	void setExcludedColliderID(int id);

    int ownColliderID;
	int excludedColliderID = -1;
};


