#include "Mario.h"

Mario::Mario()
{
	speed = 200;
	MarioSprite.loadFromFile("gfx/MarioSheetT.png");
	setTexture(&MarioSprite);
	setSize(sf::Vector2f(15*4, 21*4));
	setPosition(100, 100);

	//Walk
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	//Swim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	//Duck
	duck.addFrame(sf::IntRect(0, 44, 17, 17));
	//duck.addFrame(sf::IntRect(17, 44, 17, 17));
	duck.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
}

void Mario::handleInput(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());

	//Left
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
	}
	//Right
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
	}
	//Duck
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation = &duck;
	}
	else
	{
		currentAnimation->reset();
		currentAnimation = &walk;
	}
	//Jump
	if (input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(200.f);
		audio->playSoundbyName("jump");
	}

	currentAnimation->animate(dt);
}
