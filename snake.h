/*********************************
* snake.h
* ================================
* Copyright Vladimir Fomene 2018
* Defines an object for the snake
* and define function prototypes
* to define its behaviour.
*
**********************************/

typedef struct snake{

	int length;

	

};

//Function prototypes for the snake's behaviour

void grow(snake* sn);
void move(snake* sn);
void turnLeft(snake* sn);
void turnRight(snake* sn);
void turnUp(snake* sn);
void turnDown(snake* sn);
void eat(snake* sn);

