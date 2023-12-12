#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Heart.hpp"
using namespace std;
using namespace sf;

Heart::Heart(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
	texture_address=address;
    found=false;
}
void Heart::draw(RenderWindow& window)
{
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);
}

FloatRect Heart::get_global_bounds() 
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}