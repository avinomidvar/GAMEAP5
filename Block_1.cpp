#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Block_1.hpp"
using namespace std;
using namespace sf;
Block_1::Block_1(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
   texture_address=address;
   destroy=false;
}
void Block_1::draw(RenderWindow& window)
{
    if (destroy)
        return;
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);

}

FloatRect Block_1::get_global_bounds() 
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}

