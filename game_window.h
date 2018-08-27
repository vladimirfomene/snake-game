/*********************************
* game_window.h
* ================================
* Copyright Vladimir Fomene 2018
* Defines an object for the game 
* window and define function prototypes
* to define its behaviour.
*
**********************************/


typedef struct game_window{

	int height;

	int width;

	int num_squares;

	int level;
};


//Functions for game window behaviour
void draw_game_screen();

void drop_square(game_window* win);

void is_level_completed(game_window* win);

void update_screen(game_window* win);

void exit_game_screen(game_window* win);

