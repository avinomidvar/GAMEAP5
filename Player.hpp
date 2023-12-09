#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef PLAYER
#define PLAYER 
class Player
{
	public:
		Player(int init_x,int init_y);
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

	private:
		int x_position;
		int y_position;
		void check_borders();
		int lives;
		sf::Sprite sprite;
		sf::Texture texture;
};
#endif 