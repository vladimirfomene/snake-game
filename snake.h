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
#include "game_window.h"


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

void grow(Snake* sn, Snake_part new_part);

Snake* init_snake(GameWindow* win);

void draw_snake(Snake* snake, WINDOW* screen);

void move_snake(Snake* sn, char dir, WINDOW* screen);

void turn_left(Snake* sn, char* dir);

void turn_right(Snake* sn, char* dir);

void turn_up(Snake* sn, char* dir);

void turn_down(Snake* sn, char* dir);

void eat(Snake* sn);

