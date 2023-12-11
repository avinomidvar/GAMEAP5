#ifndef KEY
#define KEY
#include <iostream>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
class Key
{
	public:
	Key(int x,int y,std::string address);
	void draw(sf::RenderWindow& window);
    sf::FloatRect get_global_bounds();

	private:
	bool is_found;
	int x;
	int y;
	std::string texture_address;	
};
#endif