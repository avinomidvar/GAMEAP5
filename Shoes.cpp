#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Shoes.hpp"
using namespace std;
using namespace sf;

Shoes::Shoes(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
	texture_address=address;
    found=false;
}
void Shoes::draw(RenderWindow& window)
{
    if(found)
        return;
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);
}

FloatRect Shoes::get_global_bounds() 
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}
void Shoes::shoes_got()
{
    found=true;
}