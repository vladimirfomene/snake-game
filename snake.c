/*********************************
* snake.c
* ================================
* Copyright Vladimir Fomene 2018
* Implements all the functions prototypes
* for a snake's behaviour
**********************************/

#include "snake.h"

void grow(Snake* sn, Snake_part new_part){
	sn->length += 1;
	sn->parts[sn->length] = new_part;
}

void move_snake(Snake* sn, char dir){
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

		mvaddch(next_y, next_x, snake->parts[i].part_symbol);
		mvdelch(sn->parts[i].y, sn->parts[i].x);
		next_x = sn->parts[i].x;
		next_y = sn->parts[i].y;
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

void draw_snake(Snake* snake){
	for(int i = 0; i < snake->length; i++){
		mvaddch(snake->parts[i].y, snake->parts[i].x, snake->parts[i].part_symbol);
	}
}

void turn_left(Snake* sn, char* dir){
	*dir = 'l';
	move_snake(sn);
}

void turn_right(Snake* sn, char* dir){
	*dir = 'r';
	move_snake(sn);
}

void turn_up(Snake* sn, char* dir){
	*dir = 'u';
	move_snake(sn);
}

void turn_down(Snake* sn, char* dir){
	*dir = 'd';
	move_snake(sn);
}

void eat(Snake* sn);

