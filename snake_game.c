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

	int player_option;

	while(1){
		if ((player_option = getch()) == ERR) {
        	//move if user has not press key
        } else {
			switch(player_option){
				case 'q':
					//quit game
				case 'n':
					//continue
				case 'c':
					//cancel
				case 'p':
					//pause
				default:
					printf("Please enter a valid option.\n");
			}
        }
	}


	//print game results
	//print_game_result();

	//quit game after a few seconds
	//quit_game();
	getch();

	endwin();
	
	
	return 0;
}
