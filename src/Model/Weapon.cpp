#include "Model/Weapon.hpp"

Weapon::Weapon() 
{
    maxAmmo = 30;
    maxReserveAmmo = 150;
    ammo = 30;
    reserveAmmo = 150;
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
    if (ammo > 0) 
    {
        ammo--;
    }
}

void Weapon::setAmmo(int a) 
{
    ammo = a;
}

int Weapon::getAmmo() 
{
    return ammo;
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
    reserveAmmo += ammo;
    ammo = 0;
    reserveAmmo -= 30;

    if (reserveAmmo <= 0) 
    {
        ammo = 30 + reserveAmmo;
        reserveAmmo = 0;
    } 
    else 
    {
        ammo = 30;
    }
}
