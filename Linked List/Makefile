#makefile

CC = g++ -g -std=c++11

exe_file = prog5

$(exe_file): node.o prog.o linked_list.o
	$(CC) node.o prog.o linked_list.o -o $(exe_file)

linked_list.o: linked_list.cpp linked_list.h
	$(CC) -c linked_list.cpp

node.o: node.cpp node.h
	$(CC) -c node.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)