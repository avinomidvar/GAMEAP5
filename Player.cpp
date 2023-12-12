#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Bomb.hpp"
using namespace std;
using namespace sf;
const int speed=3;
const int maximum_bombs=3;
const int width=25;
const int height=40;
const int window_height=600;
const int window_width=800;
const int n_vertical=15;
const int n_horizontal=32;
const int num_of_keys=3;
const int total_lives=5;

Player::Player(int init_x,int init_y,Map* m)
{
    map=m;
	x_position=init_x;
	y_position=init_y;
    if (!texture.loadFromFile("Player.png"))
            abort();
    sprite.setTexture(texture);
    sprite.setPosition(x_position, y_position);
    lives=total_lives;
    total_keys=0;
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
    cout<<"Remaining lives: "<<lives<<endl;
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
    bool is_found=false;
    int near_x;
    int near_y;
    for (int j=0;j<n_vertical;j++)
    {
        if(is_found)
            break;
        for (int i=0;i<n_horizontal;i++)
        {
            near_x=i*width;
            near_y=j*height;
            if((abs(x_position-near_x)<10)&&(abs(y_position-near_y)<10))
                {
                    is_found=true;
                    break;
                }           
        }
    }
    for (int i=0;i<maximum_bombs;i++)
    {
        if(!bombs[i].is_on())
        {
             bombs[i].put_bomb(near_x,near_y);
             break;
        }
    }
}

void Player::update_player_bombs(RenderWindow& window)
{
    for(int i=0;i<maximum_bombs;i++)
    {
        if(bombs[i].does_player_intersect_bomb(x_position,y_position))
            loose_lives();
    }
        
    for(int i=0;i<maximum_bombs;i++)
    {
        bombs[i].check_end_of_bombs();
        if(bombs[i].is_on())
        {
            bombs[i].draw(window);
        }
    }
}

bool Player::got_all_keys()
{
    return(total_keys==num_of_keys);
}

void::Player::catch_keys()
{
    if(map->does_player_intersect_keys(get_global_bounds()))
        {
            total_keys++;
            cout<<"One key found"<<endl; 
        }
}

bool Player::does_win()
{
    if((map->does_player_intersect_door(get_global_bounds()))&&(got_all_keys()))
        return true;
    else
        return false;
}



