#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.hpp"
#include "Bomb.hpp"
#ifndef PLAYER
#define PLAYER 
class Player
{
	public:
		Player(int init_x,int init_y,Map* m);
		void move_up();
		void move_down();
		void move_left();
		void move_right();
		void draw();
		void update();
		sf::Sprite get_shape();
		void loose_lives();
		sf::FloatRect get_global_bounds();
		bool is_dead();
		void update_player_bombs(sf::RenderWindow& window);
		void drop_bomb();
		void catch_keys();
		void catch_hearts();
		bool does_win();
	private:
		int x_position;
		int y_position;
		void check_borders();
		int lives;
		sf::Sprite sprite;
		sf::Texture texture;
		Map* map;
		bool can_player_move();
		void create_bombs();
		std::vector<Bomb> bombs;
		int total_keys;
		bool got_all_keys();
		int speed;
};
#endif 