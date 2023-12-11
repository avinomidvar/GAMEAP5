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
   is_destroy=false;
}
void Block_1::draw(RenderWindow& window)
{
    if (is_destroy)
    {
        return;
    }
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
void Block_1::destroy(int destruct_x, int destruct_y)
{
    if(is_destroy)
        return;

    if ((x==destruct_x)&&(y==destruct_y))
        {
            is_destroy=true;
        }
    else 
        is_destroy=false;
}

