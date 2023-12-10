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
 const int total_time=5;
int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Playing with fire");
    Clock clock_pass_time;
    Clock clock_escape_time;
    Clock time_since_start;
    Map new_map("map.txt");
    Game game(total_time,&new_map);
     while(window.isOpen())
     {
     	Event event;
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