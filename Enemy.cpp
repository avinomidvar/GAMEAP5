#include <iostream>
#include <ctime>
#include "Enemy.hpp"
using namespace std;
using namespace sf;
const int speed=8;

Enemy::Enemy(int init_x,int init_y,char dir_2,string address)
{
	srand(time(0));
	direction_1=rand()%2;
	direction_2=dir_2;
	x=init_x;
	y=init_y;
	texture_address=address;

}
void Enemy::change_direction_1()
{
	switch(direction_1)
	{
	case 1:
		direction_1=0;
		break;
	case 0:
		direction_1=1;
		break;
	}
}

void Enemy::check_borders()
{
	switch (direction_2)
	{
		case 'H':
			if(x<=0||x>=780)
				change_direction_1();
			break;
		case 'V':
			if(y<=0||y>=580)
				change_direction_1();
			break;
	}
}

void Enemy::update()
{
	check_borders();
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
	switch(direction_2)
	{
	case 'H':
		switch(direction_1)
		{
		case 1:
			x+=speed;
			break;
		case 0:
			x-=speed;
			break;
		}
		break;
	case 'V':
		switch(direction_1)
		{
		case 1:
			y+=speed;
			break;
		case 0:
			y-=speed;
			break;
		}
		break;
	}
	sprite.setPosition(x,y);
}

FloatRect Enemy::get_global_bounds() 
{
	Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
     return sprite.getGlobalBounds();
}
void Enemy::draw(RenderWindow& window)
{
    Sprite sprite;
    Texture texture;
    if (!texture.loadFromFile(texture_address))
            abort();
   sprite.setTexture(texture);
   sprite.setPosition(x, y);
   window.draw(sprite);

}
