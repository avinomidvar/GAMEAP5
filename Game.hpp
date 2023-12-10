#ifndef GAME
#define GAME
#include <iostream>
#include <ctime>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Map.hpp"
const int init_x=0;
const int init_y=0;
class Game
{
	public: 
	Game(float time,Map* m): player(init_x,init_y,m)
	{
		game_time=time;
		enemies=m->get_enemies();

	};
	void draw(sf::RenderWindow& window);
	void pass_time();
	void add_enemies(Enemy new_enemy);
	void update_player();
	void does_player_intersect_enemies();
	bool is_over(float time);
	void show_time(std::string remaining_time);
	void handle_events(sf::Event event,sf::RenderWindow& window);

	private:
	Player player;
	std::vector<Enemy> enemies;
	float game_time;
	sf::Font font;
	sf::Text timer;	
	void move_player(char direction);
	Map* map;
};
#endif

