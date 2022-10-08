.PHONY: all clean

WARN_OPTS = -Wall -Wextra -Wpedantic -Wunused
GL_OPTS = -lGL -lGLU -lglut

CC = gcc ## --std= -O2 -g

BLD_DIR = build

all: clean mk_bld start

start: mk_bld gl_wrapp.o game.o main.o
	$(CC) $(GL_OPTS) $(BLD_DIR)/gl_wrapp.o $(BLD_DIR)/game_life.o $(BLD_DIR)/main.o -o $(BLD_DIR)/start
	
clean:
	rm -rf $(BLD_DIR)

mk_bld:
	mkdir -p $(BLD_DIR)

gl_wrapp.o:
	$(CC) $(GL_OPTS) $(WARN_OPTS) -c -o $(BLD_DIR)/gl_wrapp.o gl_wrapp.c

game.o:
	$(CC) $(GL_OPTS) $(WARN_OPTS) -c -o $(BLD_DIR)/game_life.o game_life.c

main.o:
	$(CC) $(GL_OPTS) $(WARN_OPTS) -c -o $(BLD_DIR)/main.o main.c

