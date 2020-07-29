#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"


#define JUMP_ANGLE_STEP 4
#define JUMP_HEIGHT 160
#define FALL_STEP 2


enum PlayerAnims
{
	STAND_LEFT_UP, STAND_RIGHT_UP, MOVE_LEFT_UP, MOVE_RIGHT_UP, STAND_LEFT_DOWN, STAND_RIGHT_DOWN, MOVE_LEFT_DOWN, MOVE_RIGHT_DOWN, DEADBR, DEADBL, DEADTR, DEADTL
};


void Player::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, bool character)
{
	ground = true;
	if (character) {
		spritesheet.loadFromFile("images/spritesheet3.png", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.125, 0.2), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(12);

		sprite->setAnimationSpeed(STAND_LEFT_UP, 12);
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.625f, 0.4f));

		sprite->setAnimationSpeed(STAND_RIGHT_UP, 12);
		sprite->addKeyframe(STAND_RIGHT_UP, glm::vec2(0.75f, 0.f));

		sprite->setAnimationSpeed(MOVE_LEFT_UP, 12);
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.75f, 0.2f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.625f, 0.8f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.5f, 0.f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.5f, 0.2f));

		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.625f, 0.f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.625f, 0.2f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.5f, 0.4f));
		sprite->addKeyframe(MOVE_LEFT_UP, glm::vec2(0.5f, 0.8f));

		sprite->setAnimationSpeed(MOVE_RIGHT_UP, 12);
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.75f, 0.4f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.5f, 0.6f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.625f, 0.6f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.75f, 0.6f));

		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.875f, 0.f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.875f, 0.2f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.875f, 0.4f));
		sprite->addKeyframe(MOVE_RIGHT_UP, glm::vec2(0.875f, 0.6f));

		sprite->setAnimationSpeed(STAND_LEFT_DOWN, 12);
		sprite->addKeyframe(STAND_LEFT_DOWN, glm::vec2(0.125f, 0.4f));

		sprite->setAnimationSpeed(STAND_RIGHT_DOWN, 12);
		sprite->addKeyframe(STAND_RIGHT_DOWN, glm::vec2(0.25f, 0.8f));

		sprite->setAnimationSpeed(MOVE_LEFT_DOWN, 12);
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.25f, 0.6f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.125f, 0.f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.f, 0.8f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.f, 0.6f));

		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.125f, 0.8f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.125f, 0.6f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.f, 0.4f));
		sprite->addKeyframe(MOVE_LEFT_DOWN, glm::vec2(0.f, 0.f));

		sprite->setAnimationSpeed(MOVE_RIGHT_DOWN, 12);
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.25f, 0.4f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.f, 0.2f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.125f, 0.2f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.25f, 0.2f));

		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.375f, 0.8f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.375f, 0.6f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.375f, 0.4f));
		sprite->addKeyframe(MOVE_RIGHT_DOWN, glm::vec2(0.375f, 0.2f));

		sprite->setAnimationSpeed(DEADBR, 8);
		sprite->addKeyframe(DEADBR, glm::vec2(0.375f, 0.f));
		sprite->addKeyframe(DEADBR, glm::vec2(0.75f, 0.f));
		sprite->setAnimationSpeed(DEADBL, 8);
		sprite->addKeyframe(DEADBL, glm::vec2(0.375f, 0.f));
		sprite->addKeyframe(DEADBL, glm::vec2(0.625f, 0.4f));
		sprite->setAnimationSpeed(DEADTR, 8);
		sprite->addKeyframe(DEADTR, glm::vec2(0.375f, 0.f));
		sprite->addKeyframe(DEADTR, glm::vec2(0.25f, 0.8f));
		sprite->setAnimationSpeed(DEADTL, 8);
		sprite->addKeyframe(DEADTL, glm::vec2(0.375f, 0.f));
		sprite->addKeyframe(DEADTL, glm::vec2(0.125f, 0.4f));
	}
	else {
		spritesheet.loadFromFile("images/Weapon.png", TEXTURE_PIXEL_FORMAT_RGBA);
		sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.166666666667, 1), &spritesheet, &shaderProgram);
		sprite->setNumberAnimations(2);

		sprite->setAnimationSpeed(STAND_LEFT_UP, 15);
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.666666666667f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.333333333333f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.166666666667f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.5f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.833333333333f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.833333333333f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.5f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.166666666667f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.333333333333f, 0.f));
		sprite->addKeyframe(STAND_LEFT_UP, glm::vec2(0.666666666667f, 0.f));
	}
	
		

	ini_pos = { 16,10 };
	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));

	
}

void Player::morir()
{
	mort = true;
}

void Player::update(int deltaTime, bool coop)
{
	if (!coop) {
		sprite->update(deltaTime);
		if (!mort) {
			bool aux;
			if (Game::instance().getSpecialKey(GLUT_KEY_LEFT))
			{
				if (v == 1) {
					if (!jump) {
						if (sprite->animation() != MOVE_LEFT_UP)
							sprite->changeAnimation(MOVE_LEFT_UP);
					}
					posPlayer.x -= 5;
					if (map->collisionMoveLeftP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x += 5;
						if (!jump)sprite->changeAnimation(STAND_LEFT_UP);
						if (aux) mort = true;
					}
				}
				else {
					if (!jump) {
						if (sprite->animation() != MOVE_LEFT_DOWN)
							sprite->changeAnimation(MOVE_LEFT_DOWN);
					}
					posPlayer.x -= 5;
					if (map->collisionMoveLeftP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x += 5;
						if (!jump)sprite->changeAnimation(STAND_LEFT_DOWN);
						if (aux) mort = true;
					}

				}


			}
			else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
			{
				if (v == 1) {
					if (!jump) {
						if (sprite->animation() != MOVE_RIGHT_UP)
							sprite->changeAnimation(MOVE_RIGHT_UP);
					}
					posPlayer.x += 5;
					if (map->collisionMoveRightP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x -= 5;
						if (!jump)sprite->changeAnimation(STAND_RIGHT_UP);
						if (aux) mort = true;
					}
				}
				else {
					if (!jump) {
						if (sprite->animation() != MOVE_RIGHT_DOWN)
							sprite->changeAnimation(MOVE_RIGHT_DOWN);
					}
					posPlayer.x += 5;
					if (map->collisionMoveRightP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x -= 5;
						if (!jump)sprite->changeAnimation(STAND_RIGHT_DOWN);
						if (aux) mort = true;
					}

				}

			}
			else
			{
				if (sprite->animation() == MOVE_LEFT_UP)
					sprite->changeAnimation(STAND_LEFT_UP);
				else if (sprite->animation() == MOVE_RIGHT_UP)
					sprite->changeAnimation(STAND_RIGHT_UP);
				else if (sprite->animation() == MOVE_LEFT_DOWN)
					sprite->changeAnimation(STAND_LEFT_DOWN);
				else if (sprite->animation() == MOVE_RIGHT_DOWN)
					sprite->changeAnimation(STAND_RIGHT_DOWN);
			}



			if (ground) posPlayer.y += (v * FALL_STEP);
			else {
				if (abs((v * FALL_STEP)*ACC) <= 10) posPlayer.y += (v * FALL_STEP)*ACC;
				else posPlayer.y += v * 10;
			}

			bool nextg;
			if ((sprite->animation() == STAND_LEFT_UP || sprite->animation() == MOVE_LEFT_UP)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == -1) sprite->changeAnimation(STAND_LEFT_DOWN);
				}
				ground = nextg;
			}
			else if ((sprite->animation() == STAND_RIGHT_UP || sprite->animation() == MOVE_RIGHT_UP)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == -1)  sprite->changeAnimation(STAND_RIGHT_DOWN);
				}
				ground = nextg;
			}
			else if ((sprite->animation() == STAND_LEFT_DOWN || sprite->animation() == MOVE_LEFT_DOWN)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {

					if (aux) mort = true;
					else if (v == 1)sprite->changeAnimation(STAND_LEFT_UP);
				}
				ground = nextg;
			}

			else if ((sprite->animation() == STAND_RIGHT_DOWN || sprite->animation() == MOVE_RIGHT_DOWN)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == 1)sprite->changeAnimation(STAND_RIGHT_UP);
				}
				ground = nextg;
			}

			if (ground) {
				ACC = 1;
				jump = false;
				if (Game::instance().getSpecialKey(GLUT_KEY_UP) || Game::instance().getSpecialKey(GLUT_KEY_DOWN))
				{
					jump = true;
					v = v * -1;

				}

			}
			else (ACC += 0.075f);
			sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
		}



		else if (mort) {
			if (timer < 2) {
				if (sprite->animation() == MOVE_LEFT_UP || sprite->animation() == STAND_LEFT_UP) sprite->changeAnimation(DEADBL);
				else if (sprite->animation() == MOVE_RIGHT_UP || sprite->animation() == STAND_RIGHT_UP)sprite->changeAnimation(DEADBR);
				else if (sprite->animation() == MOVE_LEFT_DOWN || sprite->animation() == STAND_LEFT_DOWN)sprite->changeAnimation(DEADTL);
				else if (sprite->animation() == MOVE_RIGHT_DOWN || sprite->animation() == STAND_RIGHT_DOWN)sprite->changeAnimation(DEADTR);
				timer += 0.02f;

			}
			else {

				sprite->setPosition(glm::vec2(float(64 * ini_pos.x), float(64 * ini_pos.y)));
				sprite->changeAnimation(MOVE_LEFT_UP);
				posPlayer.x = ini_pos.x * 64;
				posPlayer.y = ini_pos.y * 64;
				mort = false;
				timer = 1;
				v = 1;
			}
		}
	}
	else {
		sprite->update(deltaTime);
		if (!mort) {
			bool aux;
			if (Game::instance().getSpecialKey('a'))
			{
				if (v == 1) {
					if (!jump) {
						if (sprite->animation() != MOVE_LEFT_UP)
							sprite->changeAnimation(MOVE_LEFT_UP);
					}
					posPlayer.x -= 5;
					if (map->collisionMoveLeftP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x += 5;
						if (!jump)sprite->changeAnimation(STAND_LEFT_UP);
						if (aux) mort = true;
					}
				}
				else {
					if (!jump) {
						if (sprite->animation() != MOVE_LEFT_DOWN)
							sprite->changeAnimation(MOVE_LEFT_DOWN);
					}
					posPlayer.x -= 5;
					if (map->collisionMoveLeftP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x += 5;
						if (!jump)sprite->changeAnimation(STAND_LEFT_DOWN);
						if (aux) mort = true;
					}

				}


			}
			else if (Game::instance().getKey('d'))
			{
				if (v == 1) {
					if (!jump) {
						if (sprite->animation() != MOVE_RIGHT_UP)
							sprite->changeAnimation(MOVE_RIGHT_UP);
					}
					posPlayer.x += 5;
					if (map->collisionMoveRightP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x -= 5;
						if (!jump)sprite->changeAnimation(STAND_RIGHT_UP);
						if (aux) mort = true;
					}
				}
				else {
					if (!jump) {
						if (sprite->animation() != MOVE_RIGHT_DOWN)
							sprite->changeAnimation(MOVE_RIGHT_DOWN);
					}
					posPlayer.x += 5;
					if (map->collisionMoveRightP1(posPlayer, glm::ivec2(64, 64), aux))
					{
						posPlayer.x -= 5;
						if (!jump)sprite->changeAnimation(STAND_RIGHT_DOWN);
						if (aux) mort = true;
					}

				}

			}
			else
			{
				if (sprite->animation() == MOVE_LEFT_UP)
					sprite->changeAnimation(STAND_LEFT_UP);
				else if (sprite->animation() == MOVE_RIGHT_UP)
					sprite->changeAnimation(STAND_RIGHT_UP);
				else if (sprite->animation() == MOVE_LEFT_DOWN)
					sprite->changeAnimation(STAND_LEFT_DOWN);
				else if (sprite->animation() == MOVE_RIGHT_DOWN)
					sprite->changeAnimation(STAND_RIGHT_DOWN);
			}



			if (ground) posPlayer.y += (v * FALL_STEP);
			else {
				if (abs((v * FALL_STEP)*ACC) <= 10) posPlayer.y += (v * FALL_STEP)*ACC;
				else posPlayer.y += v * 10;
			}

			bool nextg;
			if ((sprite->animation() == STAND_LEFT_UP || sprite->animation() == MOVE_LEFT_UP)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == -1) sprite->changeAnimation(STAND_LEFT_DOWN);
				}
				ground = nextg;
			}
			else if ((sprite->animation() == STAND_RIGHT_UP || sprite->animation() == MOVE_RIGHT_UP)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == -1)  sprite->changeAnimation(STAND_RIGHT_DOWN);
				}
				ground = nextg;
			}
			else if ((sprite->animation() == STAND_LEFT_DOWN || sprite->animation() == MOVE_LEFT_DOWN)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {

					if (aux) mort = true;
					else if (v == 1)sprite->changeAnimation(STAND_LEFT_UP);
				}
				ground = nextg;
			}

			else if ((sprite->animation() == STAND_RIGHT_DOWN || sprite->animation() == MOVE_RIGHT_DOWN)) {
				nextg = (map->collisionMoveDownP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux) || map->collisionMoveUpP1(posPlayer, glm::ivec2(64, 64), &posPlayer.y, aux));

				if (jump == nextg && nextg == true) {
					if (aux) mort = true;
					else if (v == 1)sprite->changeAnimation(STAND_RIGHT_UP);
				}
				ground = nextg;
			}

			if (ground) {
				ACC = 1;
				jump = false;
				if (Game::instance().getKey('w') || Game::instance().getKey('s'))
				{
					jump = true;
					v = v * -1;

				}

			}
			else (ACC += 0.075f);
			sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
		}



		else if (mort) {
			if (timer < 2) {
				if (sprite->animation() == MOVE_LEFT_UP || sprite->animation() == STAND_LEFT_UP) sprite->changeAnimation(DEADBL);
				else if (sprite->animation() == MOVE_RIGHT_UP || sprite->animation() == STAND_RIGHT_UP)sprite->changeAnimation(DEADBR);
				else if (sprite->animation() == MOVE_LEFT_DOWN || sprite->animation() == STAND_LEFT_DOWN)sprite->changeAnimation(DEADTL);
				else if (sprite->animation() == MOVE_RIGHT_DOWN || sprite->animation() == STAND_RIGHT_DOWN)sprite->changeAnimation(DEADTR);
				timer += 0.02f;

			}
			else {

				sprite->setPosition(glm::vec2(float(64 * ini_pos.x), float(64 * ini_pos.y)));
				sprite->changeAnimation(MOVE_LEFT_UP);
				posPlayer.x = ini_pos.x * 64;
				posPlayer.y = ini_pos.y * 64;
				mort = false;
				timer = 1;
				v = 1;
			}
		}
	}
	
}

void Player::render()
{
	sprite->render();
}

void Player::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Player::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

void Player::ret_pos(int &x, int &y) {
	x = posPlayer.x;
	y = posPlayer.y;
}

glm::ivec2 Player::ret_ini_pos() {
	return ini_pos;
}






