#makefile

CC = g++ -std=c++11

exe_file = prog3

$(exe_file): animal.o prog.o sealions.o tigers.o bears.o zoo.o player.o
	$(CC) animal.o prog.o sealions.o tigers.o bears.o zoo.o player.o -o $(exe_file)

animal.o: animal.cpp animal.h
	$(CC) -c animal.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

sealions.o: sealions.cpp sealions.h
	$(CC) -c sealions.cpp

tigers.o: tigers.cpp tigers.h
	$(CC) -c tigers.cpp

player.o: player.cpp player.h
	$(CC) -c player.cpp

bears.o: bears.cpp bears.h
	$(CC) -c bears.cpp

zoo.o: zoo.cpp zoo.h
	$(CC) -c zoo.cpp

clean: 
	rm -f *.out *.o $(exe_file)