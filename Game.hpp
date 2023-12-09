#ifndef GAME
#define GAME
#include <iostream>
#include <ctime>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;
class Game
{
	public: 
	Game(float time): player(2,2)
	{
		Clock time_remaining;
	};
	void draw(RenderWindow& window);
	void move_player();
	void pass_time();
	void add_enemies(Enemy new_enemy);
	void update_player();
	void move_player(char direction);
	void does_player_intersect_enemies();
	bool is_over();

	private:
	Player player;
	vector<Enemy> enemies;
};
#endif

