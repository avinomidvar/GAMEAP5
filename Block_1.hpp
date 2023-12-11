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
    sf::FloatRect get_global_bounds();
    void destroy(int destruct_x, int destruct_y);
    bool is_destroyed(){return is_destroy;};
    
    private:
	int x;
	int y;
	std::string texture_address;
    bool is_destroy;
};
#endif
