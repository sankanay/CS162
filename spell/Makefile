#makefile

CC = g++ -std=c++11

exe_file = spell_prog

$(exe_file): spell.o prog.o 
	$(CC) spell.o prog.o -o $(exe_file)

spell.o: spell.cpp
	$(CC) -c spell.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

clean: 
	rm -f *.out *.o $(exe_file)