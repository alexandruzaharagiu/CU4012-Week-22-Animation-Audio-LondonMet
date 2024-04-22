#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie :
    public GameObject
{
public:
    Zombie();
    void update(float dt) override;
    void handleInput(float dt);
private:
    Animation Walk;
    sf::Texture ZombieSpriteSheet;
    int speed;
};

