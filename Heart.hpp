#ifndef HEART
#define HEART
#include <iostream>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
class Heart
{
	public:
	Heart(int init_x,int init_y,std::string address);
	void draw(sf::RenderWindow& window);
    sf::FloatRect get_global_bounds();
    bool is_found(){return found;};
    void heart_got();

	private:
	int x;
	int y;
	std::string texture_address;
	bool found;	
};
#endif