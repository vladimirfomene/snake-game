/*********************************
* game_window.c
* ================================
* Copyright Vladimir Fomene 2018
* Implement all the functions defined
* in game_window.h. 
*
**********************************/

#include <stdbool.h>

#include "snake.h"



GameWindow* draw_game_screen(){

	initscr();
	cbreak();
	noecho();
	curs_set(FALSE); 
	start_color(); //enable color attributes
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	
	return setup_game_screen();
}

GameWindow* setup_game_screen(){
	GameWindow* game_window = (GameWindow*) malloc(sizeof(GameWindow));
	game_window->height = LINES - 4;
	game_window->width = COLS;
	game_window->level = 1;
	game_window->player_points = 0;
	game_window->num_squares_per_level = NUM_SQUARES_PER_LEVEL;
	game_window->canvas = newwin(game_window->height, game_window->width, 2, 0);


	return game_window;
}

WINDOW* setup_header(GameWindow* game_window){
	//Create a window for the header
	WINDOW* header = newwin(LINES - (LINES - 2), game_window->width, 0, 0);

	//Get new screen dimensions
	int header_height, header_width;
	getmaxyx(header, header_height, header_width);
	
	wmove(header, 0, 0);

	attron(COLOR_PAIR(1));
	wprintw(header, " SNAKE GAME");
	
	wmove(header, 0, (header_width / 2) - (strlen("LEVEL 12") / 2));
	wprintw(header, "LEVEL %d", game_window->level);

	wmove(header, 0, (header_width - 1) - (strlen("POINTS 185") + PADDING));
	wprintw(header, "POINTS %d", game_window->player_points);
	attroff(COLOR_PAIR(1));

	//Draw horizontal line
	wmove(header, 1, 0);
	whline(header, '='| COLOR_PAIR(1), header_width);


	return header;
}

WINDOW* setup_footer(GameWindow* game_window){
	//create a window for the footer
	WINDOW* footer = newwin(LINES - (LINES - 2), game_window->width, LINES - 2, 0);


	//Get new screen dimensions
	int footer_height, footer_width;
	getmaxyx(footer, footer_height, footer_width);

	whline(footer, '='| COLOR_PAIR(1), footer_width);

	wmove(footer, 1, 0);

	
	//Print footer instructions
	attron(COLOR_PAIR(1));
	
	wprintw(footer, " Press P to pause and unpause,  ");

	wprintw(footer, "Press Q to quit,  ");

	wprintw(footer, "Play with arrow keys");

	attroff(COLOR_PAIR(1));


	return footer;

}


void update_screen(WINDOW* screen){
	wrefresh(screen);
}

void discard_screen(WINDOW* screen){
	delwin(screen);
}

void print_message(GameWindow* win, char* str){
	wprintw(win->canvas, str);
}
