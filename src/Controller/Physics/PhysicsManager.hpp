//
// Created by Charlie Sewell on 18/03/2021.
//

#ifndef ICT397_GAME_ENGINE_PHYSICSMANAGER_HPP
#define ICT397_GAME_ENGINE_PHYSICSMANAGER_HPP

#include <reactphysics3d/reactphysics3d.h>

class PhysicsManager {
  public:
    PhysicsManager();
    ~PhysicsManager();
    void Update(float timeStep);
  private:
    reactphysics3d::PhysicsCommon* physicsCommon;
    reactphysics3d::PhysicsWorld* physicsWorld;
};

#endif // ICT397_GAME_ENGINE_PHYSICSMANAGER_HPP
