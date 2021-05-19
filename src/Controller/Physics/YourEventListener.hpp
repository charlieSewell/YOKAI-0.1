//
// Created by Charlie Sewell on 13/05/2021.
//
#pragma once
#include <reactphysics3d/reactphysics3d.h>

class YourEventListener : public reactphysics3d::EventListener {
  public:
    YourEventListener() = default;
    void onContact(const reactphysics3d::CollisionCallback::CallbackData &callbackData) override;
};

