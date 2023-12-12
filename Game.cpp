#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;
const int width=25;
const int height=40;
const int window_height=600;
const int window_width=800;


void Game::pass_time()
{
	if (clock_pass_time.getElapsedTime() >= milliseconds(50))
	{
	  for (int i=0;i<enemies.size();i++)
	 {
		enemies[i].update();
	 }
	   clock_pass_time.restart();
    }
}

void Game::draw(RenderWindow& window)
{
	show_time(time_since_start.getElapsedTime().asSeconds());
	window.draw(player.get_shape());
	for (int i=0;i<enemies.size();i++)
	{
		enemies[i].draw(window);
    }
    window.draw(timer);
}

void Game::update_player(RenderWindow& window)
{
		player.update();
		player.update_player_bombs(window);
		player.catch_keys();
		player.catch_hearts();
}

void Game::move_player(char direction)
{
	switch(direction)
	{
	case 'U':
		player.move_up();
		break;
	case 'D':
		player.move_down();
		break;
	case 'L':
		player.move_left();
		break;
	case 'R':
		player.move_right();
		break;
	}
}

void Game::does_player_intersect_enemies()
{
	if(clock_escape_time.getElapsedTime() >= milliseconds(400))
	{
	for (int i=0;i<enemies.size();i++)
	{
		if(player.get_global_bounds().intersects(enemies[i].get_global_bounds()))
			player.loose_lives();
	}
	 clock_escape_time.restart();
   }
}

void Game::handle_events(Event event,RenderWindow& window)
{
	if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::W))
     	move_player('U');
    if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::S))
     	move_player('D');
     if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::D))
     	move_player('R');
     if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::A))
     	move_player('L');
     if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::X))
     	player.drop_bomb();
     if (event.type == Event::Closed)
         window.close();
}

bool Game::is_over()
{
	float time=time_since_start.getElapsedTime().asSeconds();
	if(player.is_dead()||(time>=game_time*60.0))
	{
		cout<<"GAME OVER!"<<endl;
		return true;
	}

	if(player.does_win())
	{
		cout<<"YOU WON!"<<endl;
		return true;
	}
	else 
	return false;
}
void Game::show_time(float time)
{
	 string remaining_time=(to_string(int(floor(time/60))).append(":")).append(to_string(int(time-floor(time/60)*60)));
	 font.loadFromFile("arial.ttf");
     timer.setFont(font);
     timer.setFillColor(Color::White);
     timer.setPosition(window_width-70,window_height-50);
     timer.setString(remaining_time);
}

void Game::create_enemies()
{
	ifstream file;
    file.open("map.txt");
	int row=0;  
	string line;  
    while (getline(file, line))
    {
       for (int i=0; i<line.length();i++)
	  {
		int x_position=i*width+2;
		int y_position=row*height+2;
	    if (line[i]=='V')
	    {
			enemies.push_back(Enemy(x_position,y_position,'V',"Enemy.png",map));
	    }
		if (line[i]=='H')
			enemies.push_back(Enemy(x_position,y_position,'H',"Enemy.png",map));
	  }
       row++;
    }
    file.close();
}
