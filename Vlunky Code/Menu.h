#ifndef _MENU_INCLUDE
#define _MENU_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Imatge.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Menu
{

public:
	Menu();
	~Menu();

	void init();
	void update(int deltaTime, int op);
	void render(int opcio);

private:
	void initShaders();


private:
	TileMap *map;
	Imatge *fons0, *fons1, *pic;
	glm::ivec2 end;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
};


#endif // _MENU_INCLUDE