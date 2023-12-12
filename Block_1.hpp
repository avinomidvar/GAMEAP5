# include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "Key.hpp"
#include "Heart.hpp"
#include "Shoes.hpp"
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
    Key put_key_under();
    Heart put_heart_under();
    Shoes put_shoes_under();
    
    private:
	int x;
	int y;
	std::string texture_address;
    bool is_destroy;
};
#endif
