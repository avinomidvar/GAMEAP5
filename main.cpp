#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "Map.hpp"
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
using namespace sf;
 const int windowWidth = 800;
 const int windowHeight = 600;
int main()
{
    Enemy enemy_1(200,150,'H');
    Enemy enemy_2(300,250,'V');
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Playing with fire");
    Clock clock_pass_time;
    Clock clock_escape_time;
    Clock time_since_start;
    Map new_map("map.txt");
    Game game(5,&new_map);
     game.add_enemies(enemy_1);
    game.add_enemies(enemy_2);
     while(window.isOpen())
     {
     	Event event;
        Sprite sprite;
        Texture texture;
        window.clear(Color(255,127,39));
     	while(window.pollEvent(event))
     	{
     		game.handle_events(event,window);
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
        new_map.draw(window);
         window.display();
        if (game.is_over(time_since_start.getElapsedTime().asSeconds()))
        {
            cout<<"GAME OVER!"<<endl;
            break;
        }
    }

}