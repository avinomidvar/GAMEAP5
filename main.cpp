#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
using namespace sf;
int main()
{
    int windowWidth = 800;
    int windowHeight = 600;
    Enemy enemy_1(200,150,'H');
    Enemy enemy_2(300,250,'V');
    Game game(2);
    game.add_enemies(enemy_1);
    game.add_enemies(enemy_2);
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Playing with fire");
    Clock clock_pass_time;
    Clock clock_escape_time;
    Clock time_since_start;
     while(window.isOpen())
     {
     	Event event;
     	while(window.pollEvent(event))
     	{
     		if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::W))
     			game.move_player('U');
     		if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::S))
     			game.move_player('D');
     		if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::D))
     			game.move_player('R');
     		if((event.type==Event::KeyPressed)&&(event.key.code==Keyboard::A))
     			game.move_player('L');
            if (event.type == Event::Closed)
                window.close();
     	}
        if (clock_pass_time.getElapsedTime() >= milliseconds(50))
        {
            game.pass_time();
            clock_pass_time.restart();
        }

        if (clock_escape_time.getElapsedTime() >= milliseconds(300))
        {
             game.does_player_intersect_enemies();
             clock_escape_time.restart();
         }
        game.update_player();
        game.show_time(to_string(time_since_start.getElapsedTime().asSeconds()));
        game.draw(window);
        if (game.is_over(time_since_start.getElapsedTime().asSeconds()))
        {
            cout<<"GAME OVER!"<<endl;
            break;
        }
    }

}