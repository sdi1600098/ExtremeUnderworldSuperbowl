CC	 = g++
FLAGS = -O3 -g -std=c++17 -o
OFLAGS = -c -O3 -g -Wall -std=c++17 -o
OBJECTS = Avatar.o Entity.o Gameplay.o Grid.o Tile.o Vampire.o Werewolf.o
SOURCE = Avatar.cpp Entity.cpp Gameplay.cpp Grid.cpp Tile.cpp Vampire.cpp Werewolf.cpp

all:
	$(CC) $(OFLAGS) Entity.o Entity.cpp
	$(CC) $(OFLAGS) Werewolf.o Werewolf.cpp
	$(CC) $(OFLAGS) Avatar.o Avatar.cpp
	$(CC) $(OFLAGS) Vampire.o Vampire.cpp
	$(CC) $(OFLAGS) Tile.o Tile.cpp
	$(CC) $(OFLAGS) Grid.o Grid.cpp
	$(CC) $(OFLAGS) Gameplay.o Gameplay.cpp
	$(CC) $(FLAGS) main $(OBJECTS) main.cpp

clean: 
	rm -f $(OBJECTS)