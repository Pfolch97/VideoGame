#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Menu.h"
#include "Game.h"


Menu::Menu()
{
	map = NULL;
	fons0 = NULL;
	fons1 = NULL;
	pic = NULL;
}

Menu::~Menu()
{
	if (map != NULL)
		delete map;
	if (fons0 != NULL)
		delete fons0;
	if (fons1 != NULL)
		delete fons1;
	if (pic != NULL)
		delete pic;
}


void Menu::init()
{
	initShaders();
	map = TileMap::createTileMap("levels/L1.txt", glm::vec2(0, 0), texProgram);

	fons0 = new Imatge();
	fons0->init(glm::ivec2(0, 0), texProgram, 0);
	fons0->setPosition(glm::vec2(0, 0));
	fons0->setTileMap(map);


	fons1 = new Imatge();
	fons1->init(glm::ivec2(0, 0), texProgram, 1);
	fons1->setPosition(glm::vec2(0, 0));
	fons1->setTileMap(map);

	pic = new Imatge();
	pic->init(glm::ivec2(0, 0), texProgram, 2);
	pic->setPosition(glm::vec2(50, 50));
	pic->setTileMap(map);

	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Menu::update(int deltaTime, int op)
{
	currentTime += deltaTime;

	pic->update(deltaTime, 2, op);
}

void Menu::render(int opcio)
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);
	
	map->render();

	if (opcio == 0) {
		fons1->render();
		pic->render();
	}
	else if (opcio == 1) 
		fons0->render();
	else 
		fons0->render();
}

void Menu::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if (!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if (!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if (!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}