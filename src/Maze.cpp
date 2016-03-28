#include "StdAfx.h"
#include <GL/glut.h>
#include "Maze.h"
#include "Sphere.h"
#include "Pacman.h"
#include "Cube.h"


Cube * wall = new Cube();
Sphere * ball = new Sphere();
Sphere * superBall = new Sphere();


// Criar labirinto na matriz

MazeMatrix maze = 
{
	
						  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
						  1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1,
						  1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,
						  1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,
						  1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
						  1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,
						  1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
						  1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 0, 0, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1,
						  1, 2, 2, 2, 2, 2, 3, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 2, 2, 2, 2, 2, 1,
						  1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1,
						  1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
						  1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1,
						  1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1,
						  1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
						  1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,
						  1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,
						  1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1,
						  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

};


int Maze::getMaze(int x, int y)
{
	return maze[y][x];
}

void Maze::setMaze(int x, int y, int k)
{

	maze[y][x] = k;
}

/********************
* draws functions   *
*********************/

void Maze::draw(bool darkSide){

	int line, column;

	for(line = 0; line < 24; line++)

		for(column = 0; column < 24; column++)
		
			if(maze[line][column] == 1)
				wall->draw(column + 0.5, 24 - (line + 0.5), 1, 0.6, 0.0, 0.0);

			else if(maze[line][column] == 2)
				ball->draw(column + 0.5, 24 - (line + 0.5), 0.1, 0.6, 0.6, 0.0, darkSide);

			else if(maze[line][column] == 3)
				superBall->draw(column + 0.5, 24 - (line + 0.5), 0.2, 0.6, 0.6, 0.0, darkSide);
}

/********************
*   constructor     *
*********************/

Maze::Maze(void)
{}


/********************
*    destructor     *
*********************/

Maze::~Maze(void)
{}