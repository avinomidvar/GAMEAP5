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
}
void Key::draw(RenderWindow& window)
{
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);
}


