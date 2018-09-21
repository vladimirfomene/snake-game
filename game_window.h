/*********************************
* game_window.h
* ================================
* Copyright Vladimir Fomene 2018
* Defines an object for the game 
* window and define function prototypes
* to define its behaviour.
*
**********************************/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"

#define PADDING 5

//Attributes representing the state of the game window.
typedef struct game_window{

	int height;

	int width;

	int num_squares_per_level;

	int player_points;

	int level;
}GameWindow;


//Functions for game window behaviour

void drop_square(GameWindow* win);

void is_level_completed(GameWindow* win);

void update_screen();

void exit_game_screen(GameWindow* win);

void print_header(GameWindow* game_window);

void print_footer(GameWindow* game_window);

GameWindow* draw_game_screen();

GameWindow* setup_game_screen();

