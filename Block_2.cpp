#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Block_2.hpp"
using namespace std;
using namespace sf;
Block_2::Block_2(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
    texture_address=address;	
}
void Block_2::draw(RenderWindow& window)
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);

}
FloatRect Block_2::get_global_bounds() 
{
     Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}
