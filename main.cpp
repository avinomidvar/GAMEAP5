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
 const string map_address="map.txt";
int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Playing with fire");
    Map new_map(map_address);
    Game game(&new_map,map_address);
    game.create_enemies();
     while(window.isOpen())
     {
     	Event event;
        window.clear(Color(255,127,39));
     	while(window.pollEvent(event))
     		game.handle_events(event,window);
        game.pass_time();
        game.does_player_intersect_enemies();
        game.update_player(window);
        game.draw(window);
        new_map.draw(window);
        window.display();
        if(game.is_over())
           break;
    }

}