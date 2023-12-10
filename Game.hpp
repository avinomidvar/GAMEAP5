#ifndef GAME
#define GAME
#include <iostream>
#include <ctime>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Map.hpp"
using namespace std;
using namespace sf;
const int init_x=0;
const int init_y=0;
class Game
{
	public: 
	Game(float time,Map* m): player(init_x,init_y,m)
	{
		game_time=time;
	};
	void draw(RenderWindow& window);
	void pass_time();
	void add_enemies(Enemy new_enemy);
	void update_player();
	void does_player_intersect_enemies();
	bool is_over(float time);
	void show_time(string remaining_time);
	void handle_events(sf::Event event,sf::RenderWindow& window);

	private:
	Player player;
	vector<Enemy> enemies;
	float game_time;
	Font font;
	Text timer;	
	void move_player(char direction);
	Map* map;
};
#endif

