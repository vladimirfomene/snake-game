/*********************************
* snake_game.c
* ================================
* This program is my own version of the
* classical snake game program. This
* file directs the whole process of 
* of playing the game.
* Copyright Vladimir Fomene 2018
**********************************/

#include <unistd.h>


#include "snake.h"


void drop_diamond(GameWindow* win, Snake_part* diamond, point pt);
bool is_diamond_on_snake(Snake* snake, int ptx, int pty);
point generate_point(GameWindow* win, Snake* snake);
bool has_collided_with_self(Snake* snake);
bool has_collided_with_walls(Snake* snake, GameWindow* win);
bool has_collided_with_diamond(Snake* snake, Snake_part* diamond);
void free_game_resources(WINDOW* footer, WINDOW* header, GameWindow* win, Snake_part* diamond);
void handle_exit(GameWindow* win, char* msg);
Snake_part* init_diamond();
void quit();
void game_pause();



int main(void){

	GameWindow* win = draw_game_canvas();
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
	
	bool has_eaten = false;

	int tail_part_x, tail_part_y;
	
	while(true){
		wclear(win->canvas);
		
		drop_diamond(win, diamond, pt);

		player_option = wgetch(win->canvas);

		switch(player_option){
				case 'q':
					quit();
					free_game_resources(footer, header, win, diamond);
					return 0;
				case 'p':
					game_pause();
					break;
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


		move_snake(snake, dir, win->canvas);

		if(has_eaten){
			
			Snake_part new_part = {ACS_DIAMOND, tail_part_y, tail_part_x};

			//grow the snake
			grow(snake, new_part);

			
			//relocate a diamond
			point new_point = generate_point(win, snake);
			pt.x = new_point.x;
			pt.y = new_point.y;
			
			has_eaten = false;

		}

		if(has_collided_with_diamond(snake, diamond)){

			win->num_squares_per_level = win->num_squares_per_level - 1;
			
			has_eaten = true;

			tail_part_x = snake->parts[snake->length - 1].x;
			tail_part_y = snake->parts[snake->length - 1].y;

			//increment player points
			win->player_points++;


			
			
			if(win->num_squares_per_level == 0){
				if(win->level == NUMBER_OF_LEVELS){
					handle_exit(win, "You Won!!!!!, Press q to quit the game");
					free_game_resources(footer, header, win, diamond);
					quit();
					return 0;
				}else{
					win->level++;
					win->num_squares_per_level = NUM_SQUARES_PER_LEVEL;
				}

			}

			//Update header
			WINDOW* tmp = header;
			header = setup_header(win);
			update_screen(header);
			discard_screen(tmp);
			
		}

		if(has_collided_with_walls(snake, win) || has_collided_with_self(snake)){
			handle_exit(win, "You Loose!!, Press q to quit the game");
			free_game_resources(footer, header, win, diamond);
			quit();
			return 0;
		}
		
		update_screen(win->canvas);
		
		
		usleep(DELAY * (win->level));
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

void quit(){
	endwin();
}

void free_game_resources(WINDOW* footer, WINDOW* header, GameWindow* win, Snake_part* diamond){
	discard_screen(footer);
	discard_screen(header);
	discard_screen(win->canvas);
	free(win);
	free(diamond);
}

void game_pause(){
	int ch;
	do{
		ch = getchar();
	}while((char) ch != 'p');

}

bool has_collided_with_self(Snake* snake){

	Snake_part head = snake->parts[0];
	
	for(int i = 1; i < snake->length; i++){
		if(snake->parts[i].x == head.x && snake->parts[i].y == head.y)
			return true;
	}
	return false;
}

void handle_exit(GameWindow* win, char* msg){
	int endch;
	do{	
		wclear(win->canvas);
		print_message(win, msg);
		update_screen(win->canvas);
		endch = getchar();
	}while((char) endch == 'q');
}
