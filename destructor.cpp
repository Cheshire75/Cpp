#include <iostream>
#include <string.h>

class Marine
{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool isDead;
    char *name;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char *marineName);
    ~Marine();

    int attack();
    void damaged(int damage);
    void move(int x, int y);

    void showStatus();
};

Marine::Marine()
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    isDead = false;
    name = NULL;
}

Marine::Marine(int x, int y)
{
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    isDead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char *name_)
{
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    isDead = false;
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    std::cout << name << " is trained!" << std::endl;
}

Marine::~Marine()
{
    if (name != NULL)
    {
        std::cout << name << " is dead!" << std::endl;
        delete[] name;
    }
}

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::damaged(int damageEarn)
{
    hp -= damageEarn;
    if (hp <= 0)
    {
        isDead = true;
    }
}

void Marine::showStatus()
{
    std::cout << " *** " << name << " *** " << std::endl;
    std::cout << "Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main()
{
    Marine *squad[10];

    squad[0] = new Marine(2, 3, "Marine 1");
    squad[1] = new Marine(3, 5, "Marine 2");

    squad[0]->showStatus();
    squad[1]->showStatus();

    delete squad[0];
    delete squad[1];
}