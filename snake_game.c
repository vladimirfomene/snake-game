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


typedef struct cors{
	int y;
	int x;
}point;

void drop_diamond(GameWindow* win, Snake_part* diamond, point pt);
bool is_diamond_on_snake(Snake* snake, int ptx, int pty);
point generate_point(GameWindow* win, Snake* snake);
bool has_collided_with_walls(Snake* snake, GameWindow* win);
bool has_collided_with_diamond(Snake* snake, Snake_part* diamond);
Snake_part* init_diamond();



int main(void){

	GameWindow* win = draw_game_screen();
	WINDOW* header = setup_header(win);
	WINDOW* footer = setup_footer(win);
	Snake* snake = init_snake(win);
	draw_snake(snake, win->canvas);
	Snake_part* diamond = init_diamond();
	point pt = generate_point(win, snake);
	drop_diamond(win, diamond, pt);

	update_screen(header);
	update_screen(win->canvas);
	update_screen(footer);
	
	int player_option;
	char dir = 'l';

	nodelay(win->canvas, TRUE);
	keypad(win->canvas, TRUE);
	
	
	
	while(true){
		wclear(win->canvas);
		
		drop_diamond(win, diamond, pt);

		player_option = wgetch(win->canvas);

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
					break;
			}

		//check for collision
		check_for_collision(snake, win->canvas);
		move_snake(snake, dir, win->canvas);
		
		if(has_collided_with_diamond(snake, diamond)){

			win->num_squares_per_level = win->num_squares_per_level - 1;
			
			//re-render diamond
			point new_point = generate_point(win, snake);
			
			//drop your a new diamond
			drop_diamond(win, diamond, new_point);

			//grow the snake, and re-render it.
			
			if(win->num_squares_per_level == 0){
				//check if you are at the end of the game
				//if yes, Print congratulations message
				//otherwise, move game to the next level.

			}
			
		}

		if(has_collided_with_walls(Snake* snake, GameWindow* win)){
			//End the game, ask them if they want to continue
			//If so restart the game at that level.
		}
		
		update_screen(win->canvas);
		
		//pause DELAY * win->level
		usleep(300000);
	}


	endwin();
	
	
	return 0;
}

Snake_part* init_diamond(){

	return malloc(sizeof(Snake_part));

}

point generate_point(GameWindow* win, Snake* snake){
	int random_x;
	int random_y;
	
	do{
		random_x = (int) (win->width * (rand() / (double) RAND_MAX));
	    random_y = (int) (win->height * (rand() / (double) RAND_MAX));
	}while(is_diamond_on_snake(snake, random_x, random_y));

	point pt = {random_y, random_x};

	return pt;
}

void drop_diamond(GameWindow* win, Snake_part* diamond, point pt){
	
	diamond->x = pt.x;
	diamond->y = pt.y;
	diamond->part_symbol = ACS_DIAMOND;

	mvwaddch(win->canvas, diamond->y, diamond->x, diamond->part_symbol);

}

bool is_diamond_on_snake(Snake* snake, int ptx, int pty){

	for(int i = 0; i < snake->length; i++){
		if(snake->parts[i].x == ptx && snake->parts[i].y == pty)
			return true;
	}

	return false;
}


bool has_collided_with_diamond(Snake* snake, Snake_part* diamond){

	Snake_part head = snake->parts[0];
	
	return (diamond->x == head.x && diamond->y == head.y);
}


bool has_collided_with_walls(Snake* snake, GameWindow* win){
	
	Snake_part head = snake->parts[0];

	bool has_collided_with_top = head.y < 2;
	bool has_collided_with_bottom = head.y > win->height + 2;
	bool has_collided_with_left = head.x < 0;
	bool has_collided_with_right = head.x > win->width;

	return has_collided_with_top || has_collided_with_bottom || has_collided_with_left || has_collided_with_right;
}
