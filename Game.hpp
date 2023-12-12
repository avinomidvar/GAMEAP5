#ifndef GAME
#define GAME
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Map.hpp"
const int init_x=0;
const int init_y=0;
class Game
{
	public: 
	Game(float time,Map* m,std::string address): player(init_x,init_y,m)
	{
		map_address=address;
		game_time=time;
		map=m;
	};
	void draw(sf::RenderWindow& window);
	void pass_time();
	void add_enemies(Enemy new_enemy);
	void update_player(sf::RenderWindow& window);
	void does_player_intersect_enemies();
	bool is_over();
	void show_time(float time);
	void handle_events(sf::Event event,sf::RenderWindow& window);
	void create_enemies();

	private:
	Player player;
	std::vector<Enemy> enemies;
	float game_time;
	sf::Font font;
	sf::Text timer;	
	void move_player(char direction);
	Map* map;
	std::string map_address;
	sf::Clock clock_pass_time;
	sf::Clock time_since_start;
	sf::Clock clock_escape_time;
};
#endif

