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
    void key_got();
    bool is_found();

	private:
	int x;
	int y;
	std::string texture_address;
	bool is_got;	
};
#endif