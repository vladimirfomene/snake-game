/*********************************
* game_window.h
* ================================
* Defines an object for the game 
* window and defines function prototypes
* for its behaviour.
* Copyright Vladimir Fomene 2018
**********************************/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"


//Attributes representing the state of the game window.
typedef struct game_window{

	WINDOW* canvas;

	int height;

	int width;

	int num_squares_per_level;

	int player_points;

	int level;
}GameWindow;

typedef struct cors{
	int y;
	int x;
}point;

//Functions for game window behaviour

void is_level_completed(GameWindow* win);

void update_screen(WINDOW* screen);

void discard_screen(WINDOW* screen);

void exit_game_screen(GameWindow* win);

WINDOW* setup_header(GameWindow* game_window);

WINDOW* setup_footer(GameWindow* game_window);

GameWindow* draw_game_canvas();

GameWindow* setup_game_canvas();

void print_message(GameWindow* win, char* str);

