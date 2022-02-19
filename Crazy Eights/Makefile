#makefile

CC = g++ -std=c++11

exe_file = lab3_prog

$(exe_file): deck.o prog.o card.o hand.o player.o game.o
	$(CC) deck.o prog.o card.o hand.o player.o game.o -o $(exe_file)

deck.o: deck.cpp deck.h
	$(CC) -c deck.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

card.o: card.cpp card.h
	$(CC) -c card.cpp

hand.o: hand.cpp hand.h
	$(CC) -c hand.cpp

player.o: player.cpp player.h
	$(CC) -c player.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

clean: 
	rm -f *.out *.o $(exe_file)