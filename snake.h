/*********************************
* snake.h
* ================================
* Copyright Vladimir Fomene 2018
* Defines an object for the snake
* and define function prototypes
* to define its behaviour.
*
**********************************/

#include <ncurses.h>
#include "constants.h"


#define INITIAL_LENGTH 5

//Attributes which define the state of the snake
typedef struct part{
	chtype part_symbol;

	int y;
	
	int x;

}Snake_part;

typedef struct snake{

	int length;

	Snake_part parts[MAX_NUM_PARTS];

}Snake;



//Function prototypes for the snake's behaviour

void grow(Snake* sn);

Snake init_snake(GameWindow* win);

void move_snake(Snake* sn);

void turnLeft(Snake* sn);

void turnRight(Snake* sn);

void turnUp(Snake* sn);

void turnDown(Snake* sn);

void eat(Snake* sn);

