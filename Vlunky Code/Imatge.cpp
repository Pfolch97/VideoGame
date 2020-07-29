#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"


enum ImatgeAnims
{
	I1, I2, I3, I4
};


void Imatge::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int imatge)
{
	ops.resize(4);
	ops[0] = 254;
	ops[1] = 318;
	ops[2] = 382;
	ops[3] = 446;

	switch (imatge) {
		case 0:
			spritesheet.loadFromFile("images/fons0.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(1152, 704), glm::vec2(1, 1), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(1);

			sprite->setAnimationSpeed(I1, 12);
			sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
			break;

		case 1:
			spritesheet.loadFromFile("images/fons1.jpg", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(1152, 704), glm::vec2(1, 1), &spritesheet, &shaderProgram); //amb 1280 no es veu la firma
			sprite->setNumberAnimations(1);

			sprite->setAnimationSpeed(I1, 12);
			sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
			break;

		case 2:
			spritesheet.loadFromFile("images/Weapon.png", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.166666666667, 1), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(2);

			sprite->setAnimationSpeed(I1, 15);
			sprite->addKeyframe(I1, glm::vec2(0.666666666667f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.333333333333f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.166666666667f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.5f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.833333333333f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.833333333333f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.5f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.166666666667f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.333333333333f, 0.f));
			sprite->addKeyframe(I1, glm::vec2(0.666666666667f, 0.f));
			break;
	}
	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));


}

void Imatge::update(int deltaTime, int imatge, int op)
{
	switch (imatge) {
		case 0:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 1:
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);
			break;

		case 2:
			sprite->update(deltaTime);
			if (sprite->animation() != I1)
				sprite->changeAnimation(I1);

			posImatge.y = ops[op];
			sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));
			break;
	}
}

void Imatge::render()
{
	sprite->render();
}

void Imatge::setPosition(const glm::vec2 &pos)
{
	posImatge = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posImatge.x), float(tileMapDispl.y + posImatge.y)));
}

void Imatge::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Imatge::ret_opcio(int &y) {
	y = posImatge.y;
}