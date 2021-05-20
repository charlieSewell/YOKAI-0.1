#pragma once

#include <iostream>
#include "Controller/KeyframeAnimation.hpp"
#include "Model/GameObjects/GameObject.hpp"
#include "Controller/LuaManager.hpp"

class Weapon : public GameObject
{
  public:
    Weapon();

    void reload();

    void setAmmo(int a);
    int getAmmo() const;

    void setReserveAmmo(int r);
    int getReserveAmmo() const;

    void incrementAmmo();
    void decrementAmmo();

    void setMaxAmmo(int a);
    int getMaxAmmo() const;

    void setMaxReserveAmmo(int r);
    int getMaxReserveAmmo() const;

    KeyframeAnimation *getWeaponAnimation();

    void update(Transform playerTransform, glm::vec3 frontDirection);
    void draw() override;
    void setCollider(float width, float length, float height) override;

    static void registerClass();

    void registerFire();

    bool getIsFiring() const;

  private:
    KeyframeAnimation *weaponAnimation;
      
    int maxAmmo;
    int m_ammo;

    int maxReserveAmmo;
    int reserveAmmo;

    bool isFiring;
    bool isReloading;
};