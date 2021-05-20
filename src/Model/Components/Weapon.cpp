#include "Model/Components/Weapon.hpp"

Weapon::Weapon() 
{
    maxAmmo = 30;
    maxReserveAmmo = 150;
    m_ammo = 30;
    reserveAmmo = 150;

    weaponAnimation = new KeyframeAnimation();
    initialiseAnimations();
}

void Weapon::initialiseAnimations() 
{
    weaponAnimation->readFile("content/Models/guntest.txt");
    weaponAnimation->setTPS(20);
    weaponAnimation->addAnimation("fire", 1, 7);
    weaponAnimation->addAnimation("reload", 7, 55);
    weaponAnimation->addAnimation("emptyreload", 55, 108);
    weaponAnimation->addAnimation("idle", 142, 164);
    weaponAnimation->setAnimation("idle");
}

KeyframeAnimation *Weapon::getWeaponAnimation()
{
    return weaponAnimation;
}

void Weapon::incrementAmmo() 
{
    if (reserveAmmo <= (maxReserveAmmo - maxAmmo)) 
    {
        reserveAmmo += maxAmmo;
    } 
    else 
    {
        reserveAmmo = maxReserveAmmo;
    }
}

void Weapon::decrementAmmo() 
{
    if (m_ammo > 0) 
    {
        m_ammo--;
    }
}

void Weapon::setAmmo(int a) 
{
    m_ammo = a;
}

int Weapon::getAmmo() 
{
    return m_ammo;
}

void Weapon::setReserveAmmo(int r) 
{
    reserveAmmo = r;
}

int Weapon::getReserveAmmo() 
{
    return reserveAmmo;
}

void Weapon::setMaxAmmo(int m) 
{
    maxAmmo = m;
}

int Weapon::getMaxAmmo() 
{
    return maxAmmo;
}

void Weapon::setMaxReserveAmmo(int m) 
{
    maxReserveAmmo = m;
}

int Weapon::getMaxReserveAmmo() 
{
    return maxReserveAmmo;
}

void Weapon::reload() 
{
    reserveAmmo += m_ammo;
    m_ammo = 0;
    reserveAmmo -= maxAmmo;

    if (reserveAmmo <= 0) 
    {
        m_ammo = maxAmmo + reserveAmmo;
        reserveAmmo = 0;
    } 
    else 
    {
        m_ammo = maxAmmo;
    }
}

void Weapon::draw() 
{
    weaponAnimation->draw(m_transform);
}

void Weapon::update(Transform playerTransform, glm::vec3 frontDirection) 
{
    m_transform = playerTransform;
    m_transform.translate(glm::normalize(frontDirection) * 10.0f);


}
