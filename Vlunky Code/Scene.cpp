#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Game.h"


#define SCREEN_X 0
#define SCREEN_Y 0

#define INIT_PLAYER_X_TILES 14
#define INIT_PLAYER_Y_TILES 8


Scene::Scene()
{
	map1 = NULL;
	map2 = NULL;
	player = NULL;
	enemy1 = NULL;
	enemy2 = NULL;
}

Scene::~Scene()
{
	if(map1 != NULL)
		delete map1;
	if (map2 != NULL)
		delete map2;
	if(player != NULL)
		delete player;
	if (enemy1 != NULL)
		delete enemy1;
	if (enemy2 != NULL)
		delete enemy2;
}


void Scene::init()
{
	initShaders();
	map1 = TileMap::createTileMap("levels/L1.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	map2 = TileMap::createTileMap("levels/L2.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, true);
	player->setPosition(glm::vec2(player->ret_ini_pos().x * map2->getTileSize(), player->ret_ini_pos().y * map2->getTileSize()));
	player->setTileMap(map2);
	enemy1 = new Enemy();
	enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, 0);
	enemy1->setPosition(glm::vec2(6 * map2->getTileSize(), 5 * map2->getTileSize()));
	enemy1->setTileMap(map2);
	enemy2 = new Enemy();
	enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, 3);
	enemy2->setPosition(glm::vec2(9 * map2->getTileSize(), 5 * map2->getTileSize()));
	enemy2->setTileMap(map2);
	end = { 18,5 };


	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
	player->update(deltaTime, false);
	bool next = false;
	int xP, yP;
	player->ret_pos(xP, yP);
	xP = (xP / 64) + 1;
	yP = (yP / 64) + 1;
	if (xP == end.x && yP == end.y) next = true;

	if (Game::instance().getKey('z')) {
		next = true;
	}

	if (next) {
		initShaders();
		map1 = TileMap::createTileMap("levels/L3.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
		map2 = TileMap::createTileMap("levels/L4.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
		player = new Player();
		player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, true);
		player->setPosition(glm::vec2(player->ret_ini_pos().x * map2->getTileSize(), player->ret_ini_pos().y * map2->getTileSize()));
		player->setTileMap(map2);
		enemy1 = new Enemy();
		enemy1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, 2);
		enemy1->setPosition(glm::vec2(6 * map2->getTileSize(), 5 * map2->getTileSize()));
		enemy1->setTileMap(map2);
		enemy2 = new Enemy();
		enemy2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, 3);
		enemy2->setPosition(glm::vec2(9 * map2->getTileSize(), 5 * map2->getTileSize()));
		enemy2->setTileMap(map2);
		end = { 18,5 };


		projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
		currentTime = 0.0f;
	}
	enemy1->update(deltaTime, 0,player);
	enemy2->update(deltaTime, 1,player);
}

void Scene::render()
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);
	map1->render();
	map2->render();
	player->render();
	enemy1->render();
	enemy2->render();
}

void Scene::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}





