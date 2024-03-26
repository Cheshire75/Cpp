#include <string.h>
#include <iostream>

class PhotonCannon
{
    int hp, shield;
    int coordX, coordY;
    int damage;

public:
    PhotonCannon(int x, int y);
    PhotonCannon(const PhotonCannon &pc);

    void showStatus();
};

PhotonCannon::PhotonCannon(int x, int y)
{
    std::cout << "Constructor Call!" << std::endl;
    hp = shield = 100;
    coordX = x;
    coordY = y;
    damage = 20;
}

PhotonCannon::PhotonCannon(const PhotonCannon &pc)
{
    std::cout << "Copy Constructor Call!" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coordX = pc.coordX;
    coordY = pc.coordY;
    damage = pc.damage;
}

void PhotonCannon::showStatus()
{
    std::cout << "Photon Cannon " << std::endl;
    std::cout << "Location: (" << coordX << ", " << coordY << ")" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main()
{
    PhotonCannon pc1(3, 3);
    // PhotonCannon(int x, int y)를 이용해 생성자 호출
    PhotonCannon pc2(pc1);
    // 복사 생성자 호출
    PhotonCannon pc3 = pc2;
    // 복사 생성자 호출

    pc1.showStatus();
    pc2.showStatus();
    pc3.showStatus();

    return 0;
}