CC=g++
CFLAGS=-W -Wall -ansi -pedantic -g -std=c++1
LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11
EXEC=sfml-app
SRC= Source/terrain.cc Source/joueur.cc Source/CarteMonstre.cc Source/CarteSpeciale.cc Source/Game.cc Source/Menu.cc Source/Jeu.cc 
OBJ= $(SRC:.c=.o)

all: $(EXEC) 

sfml-app: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c  $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
