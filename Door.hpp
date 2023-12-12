#ifndef DOOR
#define DOOR
#include <iostream>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
class Door
{
	public:
	Door(int x,int y,std::string address);
	void draw(sf::RenderWindow& window);
    sf::FloatRect get_global_bounds();
    bool is_found(){return found;};

	private:
	int x;
	int y;
	std::string texture_address;
	bool found;	
};
#endif