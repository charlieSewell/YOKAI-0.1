#include "Model/Components/Weapon.hpp"

Weapon::Weapon() 
{
    maxAmmo = 30;
    maxReserveAmmo = 150;
    m_ammo = maxAmmo;
    reserveAmmo = maxReserveAmmo;
    isFiring = false;
    isReloading = false;

    weaponAnimation = new KeyframeAnimation();
    registerFire();
}

void Weapon::setCollider(float length, float height,float width)
{

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

int Weapon::getAmmo() const 
{
    return m_ammo;
}

void Weapon::setReserveAmmo(int r) 
{
    reserveAmmo = r;
}

int Weapon::getReserveAmmo() const 
{
    return reserveAmmo;
}

void Weapon::setMaxAmmo(int m) 
{
    maxAmmo = m;
}

int Weapon::getMaxAmmo() const 
{
    return maxAmmo;
}

void Weapon::setMaxReserveAmmo(int m) 
{
    maxReserveAmmo = m;
}

int Weapon::getMaxReserveAmmo() const 
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

void Weapon::registerClass() 
{
    KeyframeAnimation::registerClass();
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginClass<Weapon>("Weapon")
        .addProperty("gunAnimation", &Weapon::weaponAnimation, true)
        .addProperty("ammo", &Weapon::getAmmo, &Weapon::setAmmo)
        .addProperty("reserveAmmo", &Weapon::getReserveAmmo, &Weapon::setReserveAmmo)
        .addProperty("maxAmmo", &Weapon::getMaxAmmo, &Weapon::setMaxAmmo)
        .addProperty("maxReserveAmmo", &Weapon::getMaxReserveAmmo, &Weapon::setMaxReserveAmmo)
        .addFunction("reload", &Weapon::reload)
        .addFunction("getIsFiring", &Weapon::getIsFiring)
        .addFunction("incrementAmmo", &Weapon::incrementAmmo)
        .addFunction("decrementAmmo", &Weapon::decrementAmmo)
        .endClass();
}

void Weapon::registerFire() 
{
    auto fire = [&]() 
    { 
        isFiring = true;
    };

    EMS::getInstance().add(NoReturnEvent::mouseClicked, fire);

    auto noFire = [&]() 
    { 
        isFiring = false; 
    };

    EMS::getInstance().add(NoReturnEvent::mouseReleased, noFire);
}

bool Weapon::getIsFiring() const
{
    return isFiring;
}
