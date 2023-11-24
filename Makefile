CC = g++
FLAGS =  -pedantic-errors -std=c++11
objects = main.o menu.o startgame.o obstacle.o bird.o interactive.o 

interactive.o : interactive.cpp interactive.h
	$(CC) $(FLAGS) -c interactive.cpp

bird.o : bird.cpp bird.h
	$(CC) $(FLAGS) -c bird.cpp

obstacle.o : obstacle.cpp obstacle.h bird.h
	$(CC) $(FLAGS) -c obstacle.cpp

startgame.o: startgame.cpp startgame.h obstacle.h bird.h interactive.h
	$(CC) $(FLAGS) -c startgame.cpp

menu.o: menu.cpp menu.h
	$(CC) $(FLAGS) -c menu.cpp

main.o: main.cpp menu.h startgame.h
	$(CC) $(FLAGS) -c main.cpp

main: $(objects)
	$(CC) $(FLAGS) $(objects) -o main

clean:
	rm -f $(objects) main main.tgz

tar:
	tar -cvzf main.tgz *.cpp *.h 

.POHNY: clean tar
