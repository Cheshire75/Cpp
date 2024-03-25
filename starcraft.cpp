#include <iostream>

class Marine
{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool isDead;

public:
    Marine();
    Marine(int x, int y);

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
}

Marine::Marine(int x, int y)
{
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    isDead = false;
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
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main()
{
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.showStatus();
    // HP(50), location(2,3)
    marine2.showStatus();
    // HP(50), loaction(3,5)

    std::cout << "!!!marine1 attacked marine2!!!" << std::endl;
    marine2.damaged(marine1.attack());

    marine1.showStatus();
    // HP(50), location(2,3)
    marine2.showStatus();
    // HP(45), loaction(3,5)

    Marine *squad[10];
    for (int i = 0; i < 10; i++)
    {
        squad[i] = new Marine();
        std::cout << "No. " << i << " Marine" << std::endl;
        squad[i]->showStatus();
    }
}