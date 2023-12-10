#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef ENEMY
#define ENEMY
class Enemy
{
public: 
	void update();
	Enemy(int init_x,int init_y,char dir_2,std::string address);
	sf::FloatRect get_global_bounds();
	void draw(sf::RenderWindow& window);


private:
	int direction_1;
	int x;
	int y;
	char direction_2;
	void change_direction_1();
	void check_borders();
	std::string texture_address;
};
#endif