#include "Zombie.h"

Zombie::Zombie()
{
	speed = 200;

	ZombieSpriteSheet.loadFromFile("gfx/animZombie.png");
	setSize(sf::Vector2f(55*2, 108*2));
	setPosition(100, 100);
	setTexture(&ZombieSpriteSheet);

	//Walk Animation
	Walk.addFrame(sf::IntRect(0, 0, 55, 108));
	Walk.addFrame(sf::IntRect(55, 0, 55, 108));
	Walk.addFrame(sf::IntRect(110, 0, 55, 108));
	Walk.addFrame(sf::IntRect(165, 0, 55, 108));
	Walk.addFrame(sf::IntRect(220, 0, 55, 108));
	Walk.addFrame(sf::IntRect(275, 0, 55, 108));
	Walk.addFrame(sf::IntRect(330, 0, 55, 108));
	Walk.addFrame(sf::IntRect(385, 0, 55, 108));

	Walk.setFrameSpeed(1.f / 10.f);
}

void Zombie::update(float dt)
{
	//Walk.animate(dt);
	//setTextureRect(Walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	velocity.x = 0;
	setTextureRect(Walk.getCurrentFrame());

	//Right
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		Walk.setFlipped(false);
		Walk.animate(dt);
	}
	//Left
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		Walk.setFlipped(true);
		Walk.animate(dt);
	}
	//Jump
	if (input->isKeyDown(sf::Keyboard::W) && canJump)
	{
		Jump(200.f);
		audio->playSoundbyName("jump");
	}
}
