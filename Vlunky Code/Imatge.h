#ifndef _IMATGE_INCLUDE
#define _IMATGE_INCLUDE

#include <vector>
#include "Sprite.h"
#include "TileMap.h"


// Imatge is basically images that represents the images.
// As such it has all properties it needs to track its movement.


class Imatge
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int imatge);
	void update(int deltaTime, int imatge, int op);
	void render();
	void ret_opcio(int &y);
	void setPosition(const glm::vec2 &pos);
	void setTileMap(TileMap *tileMap);


private:
	glm::ivec2 tileMapDispl, posImatge;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;

	vector<int> ops;
};


#endif // _IMATGE_INCLUDE