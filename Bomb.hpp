#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include "Map.hpp"
#ifndef BOMB
#define BOMB
class Bomb
{
	public:
		Bomb(int init_x,int init_y, bool init_state,Map* m,std::string address);
		void put_bomb(int new_x,int new_y);
		void draw(sf::RenderWindow& window);
		bool is_on();
		void check_end_of_bombs();
		bool does_player_intersect_bomb(int player_x, int player_y);
	private:
		sf::Clock explosion;
		bool state;
		Map* map;	
		int x;
		int y;
		std::string texture_address;
};
#endif