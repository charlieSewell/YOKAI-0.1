#pragma once

#include <iostream>
#include "Controller/KeyframeAnimation.hpp"
#include "Model/GameObjects/GameObject.hpp"

class Weapon : public GameObject
{
  public:
    Weapon();

    void reload();

    void setAmmo(int a);
    int getAmmo();

    void setReserveAmmo(int r);
    int getReserveAmmo();

    void incrementAmmo();
    void decrementAmmo();

    void setMaxAmmo(int a);
    int getMaxAmmo();

    void setMaxReserveAmmo(int r);
    int getMaxReserveAmmo();

    void initialiseAnimations();
    KeyframeAnimation *getWeaponAnimation();

    void update(Transform playerTransform, glm::vec3 frontDirection);
    void draw() override;

  private:
    KeyframeAnimation *weaponAnimation;
      
    int maxAmmo;
    int m_ammo;

    int maxReserveAmmo;
    int reserveAmmo;
};