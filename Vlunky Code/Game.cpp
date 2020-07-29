#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init()
{
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	menu.init();
	scene.init();
}

bool Game::update(int deltaTime)
{	
	if (!triat) {
		menu.update(deltaTime, op);
	}
	else {
		if (op == 0)
			if (!pause)
				scene.update(deltaTime);
				
		if (op == 1)
			if (!pause)
				scene.update(deltaTime);
	}
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!triat)
		menu.render(0);
	else {
		if (op == 0)
			scene.render();
		else if (op == 1)
			scene.render();
		else if (op == 2)
			menu.render(1);
		else //op == 3
			menu.render(2);
	}
}

void Game::keyPressed(int key)
{
	if (key == 13 || key == 32)
		triat = true;
	if (key == 'q')
		triat = false;
	if (key == 'p')
		pause = !pause;
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key)
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	if (key == GLUT_KEY_DOWN)
	{
		++op;
		if (op > 3)
			op = 0;
	}
	if (key == GLUT_KEY_UP)
	{
		--op;
		if (op < 0)
			op = 3;
	}
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}