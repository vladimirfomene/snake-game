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




int main(void){

	GameWindow* win = draw_game_screen();
	Snake* snake = init_snake(win);
	draw_snake(snake);
	update_screen();
	
	int player_option;
	char dir = 'l';
	while(1){
		move_snake(snake, dir);
		/*if ((player_option = getch()) == ERR) {
        	move_snake(snake, dir);
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
				case KEY_DOWN:
					turn_down(snake, &dir);
					break;
				case KEY_UP:
					turn_up(snake, &dir);
					break;
				case KEY_LEFT:
					turn_left(snake, &dir);
					break;
				case KEY_RIGHT:
					turn_right(snake, &dir);
					break;
				default:
					printf("Please enter a valid option.\n");
			}
        }*/

		update_screen();
		
		//pause DELAY * win->level
		usleep(300000);
	}


	endwin();
	
	
	return 0;
}
