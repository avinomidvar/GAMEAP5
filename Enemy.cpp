#include <iostream>
#include <ctime>
#include "Enemy.hpp"
using namespace std;
using namespace sf;
const int speed=8;

Enemy::Enemy(int init_x,int init_y,char dir_2)
{
	srand(time(0));
	direction_1=rand()%2;
	direction_2=dir_2;
	x=init_x;
	y=init_y;
	if (!texture.loadFromFile("Enemy.png"))
            abort();
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
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
Sprite Enemy::get_shape()
{
    return sprite;
}


void Enemy::update()
{
	check_borders();
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
        return sprite.getGlobalBounds();
}
