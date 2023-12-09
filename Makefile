all: a.out

a.out: main.o Player.o Enemy.o Game.o -lsfml-graphics -lsfml-window -lsfml-system
	   g++ -std=c++20 main.o Player.o Enemy.o Game.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Player.hpp Enemy.hpp
	    g++ -std=c++20 -c main.cpp

Game.o: Game.cpp Game.hpp Player.hpp Enemy.hpp
	g++ -std=c++20 -c Game.cpp

Player.o: Player.cpp Player.hpp
		  g++ -std=c++20 -c Player.cpp

Enemy.o: Enemy.cpp Enemy.hpp
	g++ -std=c++20 -c Enemy.cpp

clean:
	rm*.o
	rm a.out 
