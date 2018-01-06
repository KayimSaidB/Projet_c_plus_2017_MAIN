CC=g++
CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=
EXEC=exec sfml-app
SRC= terrain.cc joueur.cc CarteMonstre.cc main.cc Game.cc Menu.cc 
OBJ= $(SRC:.c=.o)

all: $(EXEC) 

exec: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
sfml-app: test.cc
	 g++ -o sfml-app Jeu.cc -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.c
	$(CC) -o $@ -c  $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)