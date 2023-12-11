#include <iostream>
#include <ctime>
#include "Enemy.hpp"
#include "Bomb.hpp"
#include "Map.hpp"
using namespace std;
using namespace sf;
const int bomb_time=20000;
Bomb::Bomb(int init_x,int init_y, bool init_state,Map* m,string address)
{
	x=init_x;
	y=init_y;
	state=init_state;
	map=m;
	texture_address=address;
}
void Bomb::put_bomb(int new_x,int new_y)
{
	explosion.restart();
	state=true;
	x=new_x;
	y=new_y;
}
bool Bomb::is_on()
{
	return state;

}

void Bomb::draw(RenderWindow& window)
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
    window.draw(sprite);
}
void Bomb::check_end_of_bombs()
{
	if (state&&(explosion.getElapsedTime()>=milliseconds(bomb_time)))
	{
		state=false;		
	}
}
