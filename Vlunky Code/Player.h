#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"


// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Player
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, bool character);
	void update(int deltaTime, bool coop);
	void render();
	void morir();
	void ret_pos(int &x,int &y);
	void setTileMap(TileMap *tileMap);
	void setPosition(const glm::vec2 &pos);
	glm::ivec2 ret_ini_pos();

	
private:
	float timer = 1;
	bool mort = false;;
	bool ground = 1;
	bool jump = 0;
	glm::ivec2 tileMapDispl, posPlayer;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;
	int v = 1;
	float ACC = 1;
	glm::ivec2 ini_pos;

};


#endif // _PLAYER_INCLUDE


