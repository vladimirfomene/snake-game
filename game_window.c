/*********************************
* game_window.c
* ================================
* Copyright Vladimir Fomene 2018
* Implement all the functions defined
* in game_window.h. 
*
**********************************/

#include "game_window.h"


void draw_game_screen(){

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE); 
	start_color(); //enable color attributes
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	GameWindow* game_window = setup_game_screen();
	print_header(game_window);
	print_footer(game_window);
	update_screen();

}

GameWindow* setup_game_screen(){
	GameWindow* game_window = (GameWindow*) malloc(sizeof(GameWindow));
	game_window->height = LINES;
	game_window->width = COLS;
	game_window->level = 1;
	game_window->player_points = 0;
	game_window->num_squares_per_level = NUM_SQUARES_PER_LEVEL;

	return game_window;
}

void print_header(GameWindow* game_window){

	attron(COLOR_PAIR(1));
	printw("SNAKE GAME");
	attroff(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(1));
	mvprintw(0, (game_window->width / 2) - (strlen("LEVEL 12") / 2), "LEVEL %d", game_window->level);
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(1));
	mvprintw(0, (game_window->width - 1) - (strlen("POINTS 185") + PADDING), "POINTS %d", game_window->player_points);
	attroff(COLOR_PAIR(1));

	//Draw horizontal line
	move(1, 0);
	hline('='| COLOR_PAIR(1), game_window->width);
}

void print_footer(GameWindow* game_window){
	//Draw horizontal line
	move(game_window->height - 2, 0);
	hline('='| COLOR_PAIR(1), game_window->width);

	
	//Print footer instructions
	attron(COLOR_PAIR(1));
	mvprintw(game_window->height - 1, 0, "Press P to pause,  ");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(1));
	printw("Press Q to quit,  ");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(1));
	printw("Press R to resume  ");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(1));
	printw("Play with arrow keys");
	attroff(COLOR_PAIR(1));

}

void drop_square(GameWindow* win){

	int random_x = (int) (win->width * (rand() / (double) RAND_MAX));
	int random_y = (int) (win->height * (rand() / (double) RAND_MAX));

	mvaddch(random_y, random_x, ACS_BLOCK);

}

void update_screen(){
	refresh();
}
