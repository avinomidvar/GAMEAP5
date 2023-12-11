# include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#ifndef MAP
#define MAP
#include "Block_1.hpp"
#include "Block_2.hpp"
#include "Key.hpp"
class Map
{
	private:
	std::vector<Block_1> blocks_1;
	std::vector<Block_2> blocks_2;
	std::vector<Key> keys;
	void create_elements(std::string line, int row);
	void create_keys();
		
	public:
	Map(std::string file_name);
	void draw(sf::RenderWindow& window);
	bool does_intersect_blocks(sf::FloatRect bounds);
	void destroy_blocks(int x, int y);	
};
#endif