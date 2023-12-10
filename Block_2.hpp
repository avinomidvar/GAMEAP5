# include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#ifndef BLOCK_2
#define BLOCK_2
class Block_2
{
    public:
    Block_2(int init_x,int init_y,std::string s);
    void draw(sf::RenderWindow& window);
    sf::FloatRect get_global_bounds();

    private:
	int x;
	int y;
	std::string texture_address;
};
#endif
