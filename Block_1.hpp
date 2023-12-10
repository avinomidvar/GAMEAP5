# include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#ifndef BLOCK_1
#define BLOCK_1
class Block_1
{
    public:
    Block_1(int init_x,int init_y,std::string s);
    void draw(sf::RenderWindow& window);
    private:
	int x;
	int y;
	std::string texture_address;
};
#endif
