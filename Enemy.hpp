#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.hpp"
#ifndef ENEMY
#define ENEMY
class Enemy
{
public: 
	void update();
	Enemy(int init_x,int init_y,char dir_2,std::string address,Map* m);
	sf::FloatRect get_global_bounds();
	void draw(sf::RenderWindow& window);


private:
	int direction_1;
	int x;
	int y;
	char direction_2;
	void change_direction_1();
	void check_borders_and_walls();
	std::string texture_address;
	Map* map;
};
#endif