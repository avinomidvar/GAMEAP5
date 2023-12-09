#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
using namespace std;
using namespace sf;

Player::Player(int init_x,int init_y)
{
	x_position=init_x;
	y_position=init_y;
    if (!texture.loadFromFile("Player.png"))
            abort();
    sprite.setTexture(texture);
    sprite.setPosition(x_position, y_position);
    lives=6;
 
}

void Player::move_up()
{
    y_position-=10;	
    if (y_position<=0)
        y_position=0;
}

void Player::move_down()
{
    y_position+=10;	
}

void Player::move_right()
{
    x_position+=10;	
}

void Player::move_left()
{
    x_position-=10;	
}

Sprite Player::get_shape()
{
    return sprite;
}
void Player::check_borders()
{
    if (y_position>=580)
        y_position=580;
    if (y_position<=0)
        y_position=0;
    if(x_position>=780)
        x_position=780;
    if(x_position<=0)
       x_position=0;
}

void Player::update()
{
    check_borders();
    sprite.setPosition(x_position,y_position);
}

void Player::loose_lives()
{
    lives--;
    cout<<lives<<endl;
}

FloatRect Player::get_global_bounds() 
{
        return sprite.getGlobalBounds();
}

bool Player::is_dead()
{
    if(lives==0)
        return true;
    else 
        return false;
}


