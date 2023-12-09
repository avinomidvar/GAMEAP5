#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef ENEMY
#define ENEMY
class Enemy
{
public: 
	void update();
	sf::Sprite get_shape();
	Enemy(int init_x,int init_y,char dir_2);
	sf::FloatRect get_global_bounds();


private:
	int direction_1;
	int x;
	int y;
	char direction_2;
	void change_direction_1();
	void check_borders();
	sf::Sprite sprite;
	sf::Texture texture;
};
#endif