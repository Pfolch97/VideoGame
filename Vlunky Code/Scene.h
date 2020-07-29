#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "Enemy.h"
#include "Imatge.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	//glm::ivec2 get_pos();

private:
	void initShaders();
	

private:
	TileMap *map1,*map2;
	Player *player;
	Enemy *enemy1, *enemy2, *enemy3;
	glm::ivec2 end;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;

	Imatge *ima;
};


#endif // _SCENE_INCLUDE

