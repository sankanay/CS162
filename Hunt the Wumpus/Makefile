#makefile

CC = g++ -g -std=c++11

exe_file = prog4

$(exe_file): bats.o prog.o event.o gold.o pit.o room.o wumpus.o cave.o
	$(CC) bats.o prog.o event.o gold.o pit.o room.o wumpus.o cave.o -o $(exe_file)

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

cave.o: cave.cpp cave.h
	$(CC) -c cave.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)