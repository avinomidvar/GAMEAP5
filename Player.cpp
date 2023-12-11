#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Bomb.hpp"
using namespace std;
using namespace sf;
const int speed=3;
const int maximum_bombs=3;

Player::Player(int init_x,int init_y,Map* m)
{
    map=m;
	x_position=init_x;
	y_position=init_y;
    if (!texture.loadFromFile("Player.png"))
            abort();
    sprite.setTexture(texture);
    sprite.setPosition(x_position, y_position);
    lives=6;
    create_bombs();
 
}

void Player::move_up()
{
    y_position-=speed;	
    update();
    if(can_player_move())
        return;
    else 
    y_position+=2*speed;
      update();
    if(can_player_move())
        return;
    else 
     y_position-=4*speed;
     return;


}

void Player::move_down()
{
    y_position+=speed;  
      update();
    if(can_player_move())
        return;
    else 
     y_position-=2*speed;
     update();
    if(can_player_move())
        return;
    else 
     y_position+=4*speed;
     return;	
}

void Player::move_right()
{
    x_position+=speed;  
    update();
    if(can_player_move())
        return;
    else 
       x_position-=2*speed;
     update();
    if(can_player_move())
        return;
    else 
     x_position+=4*speed;
     return;
}

void Player::move_left()
{

    x_position-=speed;  
    update();
    if(can_player_move())
        return;
    else 
     x_position+=2*speed;
    update();
    if(can_player_move())
        return;
    else 
    {
      x_position-=4*speed;
       return;    
    }
}

Sprite Player::get_shape()
{
    return sprite;
}

void Player::update()
{
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
bool Player::can_player_move()
{
    if(map->does_intersect_blocks(get_global_bounds()))
        return false;
    else
        return true;
}
void Player::create_bombs()
{
    for (int i=0;i<maximum_bombs;i++)
    {
        bombs.push_back(Bomb(0,0,false,map,"Bomb.png"));
    }
}

void Player::drop_bomb()
{
    for (int i=0;i<maximum_bombs;i++)
    {
        if(!bombs[i].is_on())
        {
             bombs[i].put_bomb(x_position,y_position);
             break;
        }
    }
}

void Player::update_player_bombs(RenderWindow& window)
{
    for(int i=0;i<maximum_bombs;i++)
    {
        bombs[i].check_end_of_bombs();
        if(bombs[i].is_on())
        {
            bombs[i].draw(window);
        }
    }
}


