#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Key.hpp"
using namespace std;
using namespace sf;

Key::Key(int init_x,int init_y,string address)
{
	x=init_x;
	y=init_y;
	texture_address=address;
    is_got=false;
}
void Key::draw(RenderWindow& window)
{
    if(is_got)
        return;
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);
}

FloatRect Key::get_global_bounds() 
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   return sprite.getGlobalBounds();
}
void Key::key_got()
{
    is_got=true;
}
bool Key::is_found()
{
    return is_got;
}