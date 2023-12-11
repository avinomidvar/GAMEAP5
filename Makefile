all: a.out

a.out: main.o Player.o Enemy.o Game.o Map.o Block_1.o Block_2.o Bomb.o Key.o -lsfml-graphics -lsfml-window -lsfml-system
	   g++ -std=c++20 main.o Player.o Enemy.o Game.o Map.o Block_1.o Block_2.o Bomb.o Key.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Player.hpp Enemy.hpp
	    g++ -std=c++20 -c main.cpp

Game.o: Game.cpp Game.hpp Player.hpp Enemy.hpp
	g++ -std=c++20 -c Game.cpp

Player.o: Player.cpp Player.hpp Bomb.hpp
		  g++ -std=c++20 -c Player.cpp

Enemy.o: Enemy.cpp Enemy.hpp Map.hpp
	g++ -std=c++20 -c Enemy.cpp

Map.o: Map.cpp Map.hpp Block_1.hpp Block_2.hpp Enemy.hpp Key.hpp
	g++ -std=c++20 -c Map.cpp

Block_1.o: Block_1.cpp Block_1.hpp Key.hpp
	g++ -std=c++20 -c Block_1.cpp

Block_2.o: Block_2.cpp Block_2.hpp
	g++ -std=c++20 -c Block_2.cpp

Bomb.o: Bomb.cpp Bomb.hpp
	g++ -std=c++20 -c Bomb.cpp
	
Key.o: Key.cpp Key.hpp
	g++ -std=c++20 -c Key.cpp
clean:
	rm*.o
	rm a.out 
