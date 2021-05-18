//
// Created by Charlie Sewell on 13/05/2021.
//
#include <reactphysics3d/reactphysics3d.h>
#pragma once
class YourEventListener : public reactphysics3d::EventListener {
  public:
    YourEventListener() = default;
    virtual void onContact(const reactphysics3d::CollisionCallback::CallbackData &callbackData) override;
};

