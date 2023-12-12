#include <iostream>
#include <ctime>
#include "Enemy.hpp"
#include "Bomb.hpp"
#include "Map.hpp"
using namespace std;
using namespace sf;
const int width=25;
const int height=40;
const int window_height=600;
const int window_width=800;
const int n_vertical=15;
const int n_horizontal=32;
const int num_of_keys=3;
const int total_lives=2;
const int bomb_time=3000;
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
		map->destroy_blocks(x,y);
		state=false;		
	}
}

bool Bomb::does_player_intersect_bomb(int player_x,int player_y)
{
	if (state&&(explosion.getElapsedTime()>=milliseconds(bomb_time)))
	return ((abs(player_x-x)<10&&(abs(player_y-y)<10))||(abs(player_x-x+width)<10&&(abs(player_y-y)<10))||
		(abs(player_x-x-width)<10&&(abs(player_y-y)<10))||(abs(player_x-x)<10&&(abs(player_y-y-height)<10))
		||(abs(player_x-x)<10&&(abs(player_y-y+height)<10)));
	else
		return false;

}
