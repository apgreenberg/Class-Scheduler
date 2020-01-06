output: main.o
	g++ main.o -o scheduler
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o scheduler
