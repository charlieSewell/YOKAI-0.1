//
// Created by Charlie Sewell on 18/03/2021.
//

#include "PhysicsManager.hpp"
PhysicsManager::PhysicsManager() {
    physicsWorld = physicsCommon->createPhysicsWorld();

}
PhysicsManager::~PhysicsManager() {
    physicsCommon->destroyPhysicsWorld(physicsWorld);
}
void PhysicsManager::Update(float timeStep) {
    physicsWorld->update(timeStep);
}