CC=gcc
CFLAGS=-I.
DEPS = game_window.h constants.h snake.h
OBJ = game_window.o snake.o snake_game.o
LIBS = -lncurses

all:

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake_game: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) *.o snake_game
