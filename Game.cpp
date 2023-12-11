#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;
const int width=45;
const int height=50;


void Game::pass_time()
{
	for (int i=0;i<enemies.size();i++)
	{
		enemies[i].update();
	}
}

void Game::draw(RenderWindow& window)
{
	window.clear(Color(255,127,39));
	window.draw(player.get_shape());
	for (int i=0;i<enemies.size();i++)
	{
		enemies[i].draw(window);
    }
    window.draw(timer);
}

void Game::update_player()
{
		player.update();
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
	for (int i=0;i<enemies.size();i++)
	{
		if(player.get_global_bounds().intersects(enemies[i].get_global_bounds()))
			player.loose_lives();
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
     if (event.type == Event::Closed)
         window.close();
}

bool Game::is_over(float time)
{
	if(player.is_dead())
		return true;
	if(time>=(game_time*60.0))
		return true;
	else 
		return false;
}
void Game::show_time(string remaining_seconds)
{
	 font.loadFromFile("arial.ttf");
     timer.setFont(font);
     timer.setFillColor(Color::White);
     timer.setPosition(650,550);
     timer.setString(remaining_seconds);
}

void Game::create_enemies()
{
	cout<<"in game "<<map<<endl;
	ifstream file;
    file.open("map.txt");
	int row=0;  
	string line;  
    while (getline(file, line))
    {
       for (int i=0; i<line.length();i++)
	  {
		int x_position=i*width;
		int y_position=row*height;
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
