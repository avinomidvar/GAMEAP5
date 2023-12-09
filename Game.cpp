#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;

void Game::add_enemies(Enemy new_enemy)
{
	enemies.push_back(new_enemy);
}

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
		window.draw(enemies[i].get_shape());
    }
     window.display();
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

bool Game::is_over()
{
	if(player.is_dead())
		return true;
	else 
	if(getElapsedTime().time_remaining)
		return false;
}