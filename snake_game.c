/*********************************
* snake_game.c
* ================================
* Copyright Vladimir Fomene 2018
* This program is my own version of the
* classical snake game program. This
* file directs the whole process of 
* of playing the game.
**********************************/

#include "snake.h"
#include "game_window.h"



int main(void){


	draw_game_screen();

	int usr_option;

	while((usr_option = getchar()) != EOF){
		
		switch(usr_option){
			
			default:
		}

	}
	
	return 0;
}
