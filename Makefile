CC = g++
FLAGS =  -pedantic-errors -std=c++11
objects = main.o menu.o startgame.o obstacle.o bird.o interactive.o 

interactive.o : interactive.cpp interactive.h
	$(CC) $(FLAGS) -c $<

bird.o : bird.cpp bird.h
	$(CC) $(FLAGS) -c $<

obstacle.o : obstacle.cpp obstacle.h bird.h
	$(CC) $(FLAGS) -c $<

startgame.o: startgame.cpp startgame.h obstacle.h bird.h interactive.h
	$(CC) $(FLAGS) -c $<

menu.o: menu.cpp menu.h interactive.h
	$(CC) $(FLAGS) -c $<

main.o: main.cpp menu.h startgame.h interactive.h
	$(CC) $(FLAGS) -c $<

game: $(objects)
	$(CC) $(FLAGS) $(objects) -o $@

clean:
	rm -f $(objects) game main.tgz

tar:
	tar -cvzf main.tgz *.cpp *.h 

clear_rank:
	rm -rf ranking.txt
	touch ranking.txt

.POHNY: clean tar clear_rank
