/*********************************
* snake.c
* ================================
* Copyright Vladimir Fomene 2018
* Implements all the functions prototypes
* for a snake's behaviour
**********************************/

#include "snake.h"
#include "game_window.h"

void grow(Snake* sn, Snake_part new_part){
	sn->length += 1;
	sn->parts[sn->length] = new_part;
}

void move_snake(Snake* sn){
	
}

Snake init_snake(GameWindow* win){
	Snake* new_snake = malloc(sizeof(Snake));
	new_snake->length = INITIAL_LENGTH;

	for(int i = 0; i < INITIAL_LENGTH; i++){
		new_snake->parts[i] = {ACS_BLOCK, win->height / 2, ((win->width / 2) - (INITIAL_LENGTH / 2)) + i };
	}
	
	return new_snake;
}

void draw_snake(Snake* snake){
	for(int i = 0; i < snake->length; i++){
		mvaddch(stdscr, parts[i]->y, parts[i]->y, parts[i]->part_symbol);
	}
}

void turnLeft(Snake* sn);

void turnRight(Snake* sn);

void turnUp(Snake* sn);

void turnDown(Snake* sn);

void eat(Snake* sn);

