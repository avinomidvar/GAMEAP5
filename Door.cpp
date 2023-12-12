#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Door.hpp"
using namespace std;
using namespace sf;

Door::Door(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
	texture_address=address;
    found=false;
}
void Door::draw(RenderWindow& window)
{
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);
}

FloatRect Door::get_global_bounds() 
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}