#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
using namespace std;

enum class WeaponType: int
{
    Pistol, //пистолет
    Rifle, //винтовка
    ShotGun, //дробовик
    MachineGun, // автомат
    UnknownType = -1
};

enum class WeaponCaliber: int
{
    Cal_9mm = 0,
    Cal_7_62mm = 1,
    Cal_5_45mm = 2,
    Cal_5_56mm = 3,
    Cal_12mm = 4,
    UnknownCaliber = -1
};

enum class WeaponCountry: int
{
    Russia = 0,
    USA = 1,
    Austria = 2,
    Germany = 3,
    UnknownCountry = -1
};

class Weapon
{
protected:
    WeaponCaliber Caliber; // калибр
    WeaponCountry Country; // страна производства
    double Weight; // масса оружия
    double BulletSpeed; //начальная скорость пули
    int MagazineCapacity; //патронов в магазине
    bool WeaponIsGood; //оружие исправно

    Weapon();

public:
    bool IsGood() const { return WeaponIsGood; }
    int MagCap() const { return MagazineCapacity; }
    double WeaponWeight() const { return Weight; }
    double Speed() const { return BulletSpeed; }
    WeaponCaliber GetCaliber() const { return Caliber; }
    WeaponCountry GetCountry() const { return Country; }

    virtual WeaponType GetType() const = 0;

    virtual void Shoot() = 0; //выстрелить
    virtual void EquipMag() = 0; //снарядить магазин
    virtual void Cleaning() = 0; //чистка оружия
    virtual void Buy() = 0; //покупка оружия
    virtual void Sell() = 0; //продажа оружия
};

class Pistol : public Weapon
{
public:
    Pistol(WeaponCaliber caliber) : Weapon() { Caliber = caliber; }
    Pistol(WeaponCountry country) : Weapon() { Country = country; }

    WeaponType GetType() const { return WeaponType::Pistol; }

    void Shoot() { wcout<< L"Вы выстрелили из пистолета"; }
    void EquipMag() { wcout<< L"Вы снарядили магазин пистолета"; }
    void Cleaning() { wcout<< L"Вы почистили пистолет"; }
    void Sell() { wcout<< L"Вы продали пистолет"; }
    void Buy() { wcout<< L"Вы купили пистолет"; }

};

class Rifle : public Weapon
{
public:
    Rifle(WeaponCaliber caliber) : Weapon() { Caliber = caliber; }
    Rifle(WeaponCountry country) : Weapon() { Country = country; }

    WeaponType GetType() const { return WeaponType::Rifle; }

    void Shoot() { wcout<< L"Вы выстрелили из винтовки"; }
    void EquipMag() { wcout<< L"Вы снарядили магазин винтовки"; }
    void Cleaning() { wcout<< L"Вы почистили винтовку"; }
    void Sell() { wcout<< L"Вы продали винтовку"; }
    void Buy() { wcout<< L"Вы купили винтовку"; }

};

class ShotGun : public Weapon
{
public:
    ShotGun(WeaponCaliber caliber) : Weapon() { Caliber = caliber; }
    ShotGun(WeaponCountry country) : Weapon() { Country = country; }

    WeaponType GetType() const { return WeaponType::ShotGun; }

    void Shoot() { wcout<< L"Вы выстрелили из дробовика"; }
    void EquipMag() { wcout<< L"Вы снарядили дробовик"; }
    void Cleaning() { wcout<< L"Вы почистили дробовик"; }
    void Sell() { wcout<< L"Вы продали дробовик"; }
    void Buy() { wcout<< L"Вы купили дробовик"; }

};

class MachineGun : public Weapon
{
public:
    MachineGun(WeaponCaliber caliber) : Weapon() { Caliber = caliber; }
    MachineGun(WeaponCountry country) : Weapon() { Country = country; }

    WeaponType GetType() const { return WeaponType::MachineGun; }

    void Shoot() { wcout<< L"Вы выстрелили из автомата"; }
    void EquipMag() { wcout<< L"Вы снарядили магазин автомата"; }
    void Cleaning() { wcout<< L"Вы почистили автомат"; }
    void Sell() { wcout<< L"Вы продали автомат"; }
    void Buy() { wcout<< L"Вы купили автомат"; }

};

#endif // WEAPON_H_INCLUDED
