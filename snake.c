/*********************************
* snake.c
* ================================
* Copyright Vladimir Fomene 2018
* Implements all the functions prototypes
* for a snake's behaviour
**********************************/

#include "snake.h"


void grow(Snake* sn, Snake_part new_part){
	sn->parts[sn->length++] = new_part;
}

void move_snake(Snake* sn, char dir, WINDOW* screen){
	int next_x, next_y;

	switch(dir){
		case 'd':
			next_x = sn->parts[0].x;
			next_y = sn->parts[0].y + 1;
			break;
		case 'u':
			next_x = sn->parts[0].x;
			next_y = sn->parts[0].y - 1;
			break;
		case 'l':
			next_x = sn->parts[0].x - 1;
			next_y = sn->parts[0].y;
			break;
		case 'r':
			next_x = sn->parts[0].x + 1;
			next_y = sn->parts[0].y;
			break;
	}

	for(int i = 0; i < sn->length; i++){
		//keep track of previous location
		int prev_y = sn->parts[i].y;
		int prev_x = sn->parts[i].x;

		//Set new location
		sn->parts[i].y = next_y;
		sn->parts[i].x = next_x;
		
		//move a part of the snake
		mvwaddch(screen, sn->parts[i].y, sn->parts[i].x, sn->parts[i].part_symbol);
		
		//set location for the next snake part
		next_x = prev_x;
		next_y = prev_y;
	}
}

Snake* init_snake(GameWindow* win){
	Snake* new_snake = malloc(sizeof(Snake));
	new_snake->length = INITIAL_LENGTH;

	for(int i = 0; i < INITIAL_LENGTH; i++){
		Snake_part new_part = {ACS_DIAMOND, win->height / 2, ((win->width / 2) - (INITIAL_LENGTH / 2)) + i };
		new_snake->parts[i] = new_part;
	}
	
	return new_snake;
}

void draw_snake(Snake* snake, WINDOW* screen){
	for(int i = 0; i < snake->length; i++){
		mvwaddch(screen, snake->parts[i].y, snake->parts[i].x, snake->parts[i].part_symbol);
	}
}

void turn_left(Snake* sn, char* dir){
	*dir = 'l';
}

void turn_right(Snake* sn, char* dir){
	*dir = 'r';
}

void turn_up(Snake* sn, char* dir){
	*dir = 'u';
}

void turn_down(Snake* sn, char* dir){
	*dir = 'd';
}

