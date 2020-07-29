#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Enemy.h"
#include "Game.h"


#define JUMP_ANGLE_STEP 4
#define JUMP_HEIGHT 96
#define FALL_STEP 4
#define GRANOTA_X 2


enum EnemyAnims
{
	STAND_LEFT, STAND_RIGHT, MOVE_LEFT, MOVE_RIGHT, STAND_LEFT_INVERTED, STAND_RIGHT_INVERTED, MOVE_LEFT_INVERTED, MOVE_RIGHT_INVERTED
};


void Enemy::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int look)
{
	bJumping = false;
	switch (look) {
		case 0:
			spritesheet.loadFromFile("images/Map.png", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(64, 16), glm::vec2(0.03125, 0.2), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(1);
			sprite->setAnimationSpeed(STAND_LEFT, 8);
			sprite->addKeyframe(STAND_LEFT, glm::vec2(0.15625f, 0.1f));
			break;

		case 1:
			spritesheet.loadFromFile("images/En_Snail.png", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.25), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(8);

			sprite->setAnimationSpeed(STAND_LEFT, 8);
			sprite->addKeyframe(STAND_LEFT, glm::vec2(0.75f, 0.f));

			sprite->setAnimationSpeed(STAND_RIGHT, 8);
			sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.5f, 0.f));

			sprite->setAnimationSpeed(MOVE_LEFT, 8);
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.25f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.5f, 0.5f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT, 8);
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.25f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.75f, 0.5f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.25f));

			sprite->setAnimationSpeed(STAND_LEFT_INVERTED, 8);
			sprite->addKeyframe(STAND_LEFT_INVERTED, glm::vec2(0.25f, 0.5f));

			sprite->setAnimationSpeed(STAND_RIGHT_INVERTED, 8);
			sprite->addKeyframe(STAND_RIGHT_INVERTED, glm::vec2(0.25f, 0.f));

			sprite->setAnimationSpeed(MOVE_LEFT_INVERTED, 8);
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.5f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.25f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.f, 0.f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT_INVERTED, 8);
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.25f, 0.f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.5f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.25f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.5f));
			break;

		case (2):
			spritesheet.loadFromFile("images/En_Monkey.png", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.25), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(8);

			sprite->setAnimationSpeed(STAND_LEFT, 8);
			sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.f));

			sprite->setAnimationSpeed(STAND_RIGHT, 8);
			sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.f, 0.25f));

			sprite->setAnimationSpeed(MOVE_LEFT, 8);
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.25f, 0.f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.25f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT, 8);
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.f, 0.25f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.f, 0.f));

			sprite->setAnimationSpeed(STAND_LEFT_INVERTED, 8);
			sprite->addKeyframe(STAND_LEFT_INVERTED, glm::vec2(0.5f, 0.f));

			sprite->setAnimationSpeed(STAND_RIGHT_INVERTED, 8);
			sprite->addKeyframe(STAND_RIGHT_INVERTED, glm::vec2(0.25f, 0.5f));

			sprite->setAnimationSpeed(MOVE_LEFT_INVERTED, 8);
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.5f, 0.f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.5f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT_INVERTED, 8);
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.25f, 0.5f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.5f));
			break;

		case (3):
			spritesheet.loadFromFile("images/En_Snake.png", TEXTURE_PIXEL_FORMAT_RGBA);
			sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.25), &spritesheet, &shaderProgram);
			sprite->setNumberAnimations(8);

			sprite->setAnimationSpeed(STAND_LEFT, 8);
			sprite->addKeyframe(STAND_LEFT, glm::vec2(0.75f, 0.f));

			sprite->setAnimationSpeed(STAND_RIGHT, 8);
			sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.75f, 0.5f));

			sprite->setAnimationSpeed(MOVE_LEFT, 8);
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.25f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.5f, 0.5f));
			sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.75f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT, 8);
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.75f, 0.5f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.25f));
			sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.5f, 0.f));

			sprite->setAnimationSpeed(STAND_LEFT_INVERTED, 8);
			sprite->addKeyframe(STAND_LEFT_INVERTED, glm::vec2(0.25f, 0.5f));

			sprite->setAnimationSpeed(STAND_RIGHT_INVERTED, 8);
			sprite->addKeyframe(STAND_RIGHT_INVERTED, glm::vec2(0.25f, 0.f));

			sprite->setAnimationSpeed(MOVE_LEFT_INVERTED, 8);
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.5f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.25f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.f, 0.f));
			sprite->addKeyframe(MOVE_LEFT_INVERTED, glm::vec2(0.25f, 0.25f));

			sprite->setAnimationSpeed(MOVE_RIGHT_INVERTED, 8);
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.25f, 0.f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.5f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.25f));
			sprite->addKeyframe(MOVE_RIGHT_INVERTED, glm::vec2(0.f, 0.5f));
			break;
		}

	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemy.x), float(tileMapDispl.y + posEnemy.y)));

}
void Enemy::update(int deltaTime, int move, Player *player)
{
	switch (move) {
	case(0):	// PLATAFORMA
		sprite->update(deltaTime);
		sprite->changeAnimation(MOVE_LEFT);
		if (platX == 0) {
			left = !left;
			platX = 100;
		}
		else
			--platX;
		if (left)
			posEnemy.x -= 2;
		else
			posEnemy.x += 2;
		break;

	case 1:		// ENEMIC QUE VA DE BANDA A BANDA
		sprite->update(deltaTime);
		if (left)
		{
			if (sprite->animation() != MOVE_LEFT)
				sprite->changeAnimation(MOVE_LEFT);
			posEnemy.x -= 2;
			if (map->collisionMoveLeft(posEnemy, glm::ivec2(32, 32)))
			{
				posEnemy.x += 2;
				left = !left;
				sprite->changeAnimation(MOVE_LEFT);

			}
		}
		else
		{
			if (sprite->animation() != MOVE_RIGHT)
				sprite->changeAnimation(MOVE_RIGHT);
			posEnemy.x += 2;
			if (map->collisionMoveRight(posEnemy, glm::ivec2(32, 32)))
			{
				posEnemy.x -= 2;
				left = !left;
				sprite->changeAnimation(STAND_RIGHT);
			}
		}
		posEnemy.y += FALL_STEP;
		map->collisionMoveDown(posEnemy, glm::ivec2(32, 32), &posEnemy.y);
		break;

	case 2:		// ENEMIC QUE SEMPRE SALTA
		if (bJumping)
		{
			jumpAngle += JUMP_ANGLE_STEP;
			if (jumpAngle == 180)
			{
				bJumping = false;
				posEnemy.y = startY;
			}
			else
			{
				posEnemy.y = int(startY - 96 * sin(3.14159f * jumpAngle / 180.f));
				if (jumpAngle > 90)
					bJumping = !map->collisionMoveDown(posEnemy, glm::ivec2(32, 32), &posEnemy.y);
			}
		}
		else
		{
			posEnemy.y += FALL_STEP;
			if (map->collisionMoveDown(posEnemy, glm::ivec2(32, 32), &posEnemy.y))
			{
				bJumping = true;
				jumpAngle = 0;
				startY = posEnemy.y;
			}
		}
		break;

	case 3:		// ENEMIC GRANOTA
		if (bJumping)
		{
			jumpAngle += JUMP_ANGLE_STEP;
			posEnemy.y = int(startY - 96 * sin(3.14159f * jumpAngle / 180.f));
			posEnemy.x += GRANOTA_X * anada;
			if (anada < 0)
				sprite->changeAnimation(MOVE_LEFT);
			else
				sprite->changeAnimation(MOVE_RIGHT);
			if (jumpAngle > 90)
				bJumping = !map->collisionMoveDown(posEnemy, glm::ivec2(32, 32), &posEnemy.y);
			if (map->collisionMoveRight(posEnemy, glm::ivec2(32, 32)))
				posEnemy.x -= GRANOTA_X * anada;
			if (map->collisionMoveLeft(posEnemy, glm::ivec2(32, 32)))
				posEnemy.x -= GRANOTA_X * anada;
		}
		else
		{
			posEnemy.y += FALL_STEP;
			anada *= -1;
			startY = posEnemy.y;
			if (map->collisionMoveDown(posEnemy, glm::ivec2(32, 32), &posEnemy.y))
			{
				if (tSalt == 10) {
					if (anada < 0)
						sprite->changeAnimation(STAND_LEFT);
					else
						sprite->changeAnimation(STAND_RIGHT);
				}
				if (tSalt == 0) {
					bJumping = true;
					jumpAngle = 0;
					posEnemy.y = startY;
					tSalt = 20;
				}
				else
					--tSalt;
			}
		}
		break;
	}
	
	int xP, yP;
	player->ret_pos(xP, yP);
	int yE0 = posEnemy.y;
	int yE1 = posEnemy.y + 32;
	int xE0 = posEnemy.x;
	int xE1 = posEnemy.x + 32;
	int yP0 = yP;
	int yP1 = yP + 64;
	int xP0 = xP;
	int xP1 = xP + 64;

	if ((xE0 <= xP0 && xE1 >= xP0) || (xE0 <= xP1 && xE1 >= xP1)) {
		if ((yE0 <= yP0 && yE1 >= yP0) || (yE0 <= yP1 && yE1 >= yP1)) {
			xP = player->ret_ini_pos().x;
			yP = player->ret_ini_pos().y;
			player->morir();
		}
	}
		sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemy.x), float(tileMapDispl.y + posEnemy.y)));
}

void Enemy::render()
{
	sprite->render();
}

void Enemy::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Enemy::setPosition(const glm::vec2 &pos)
{
	posEnemy = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemy.x), float(tileMapDispl.y + posEnemy.y)));
}