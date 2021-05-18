#include <iostream>

class Weapon 
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

  private:
    int maxAmmo;
    int ammo;

    int maxReserveAmmo;
    int reserveAmmo;
};