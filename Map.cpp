# include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Map.hpp"
#include "Block_1.hpp"
#include "Block_2.hpp"
#include "Key.hpp"
#include "Door.hpp"
#include "Shoes.hpp"

using namespace std;
using namespace sf;

const int width=25;
const int height=40;
const int window_height=600;
const int window_width=800;
const int n_vertical=32;
const int n_horizontal=15;
const int num_of_keys=3;
const int num_of_powerups=2;
const string block_1_address="Block_1.png";
const string block_2_address="Block_2.png";
const string Door_address="Door.png";

Map::Map(string file_name)
{
	ifstream file;
    file.open(file_name);
    string line;
    getline(file, line);
	int row=0;    
    while (getline(file, line))
    {
       create_elements(line,row);
       row++;
    }
    file.close();
    create_keys_and_powerups();
}

void Map::create_elements(string line,int row)
{
	for (int i=0; i<line.length();i++)
	{
		int x_position=i*width;
		int y_position=row*height;
		if ((line[i]=='B')||(line[i]=='D'))
				blocks_1.push_back(Block_1(x_position,y_position,block_1_address));
		if(line[i]=='P')
				blocks_2.push_back(Block_2(x_position,y_position,block_2_address));
		if(line[i]=='D')
				doors.push_back(Door(x_position,y_position,Door_address));
	}	
}

void Map::draw(RenderWindow& window)
{
	for(int i=0;i<shoes.size();i++)
			shoes[i].draw(window);
	for (int i=0;i<hearts.size();i++)
			hearts[i].draw(window);
	for (int i=0;i<keys.size();i++)
			keys[i].draw(window);
	for (int i=0;i<doors.size();i++)
			doors[i].draw(window);
	for (int i=0;i<blocks_1.size();i++)
	    (blocks_1[i].draw(window));
    for(int i=0;i<blocks_2.size();i++)
		(blocks_2[i].draw(window));
}


 bool Map::does_intersect_blocks(FloatRect bounds)
 {
 	for (int i=0;i<blocks_1.size();i++)
 	{
 		if(bounds.intersects(blocks_1[i].get_global_bounds())&&(!(blocks_1[i].is_destroyed())))
 		{
 			return true;
 		}
 	}
 	for (int i=0;i<blocks_2.size();i++)
 	{
 		if(blocks_2[i].get_global_bounds().intersects(bounds))
 		{
 			return true;
 		}
 	}
 		return false;
 }


 void Map::destroy_blocks(int x,int y)
 {
 	for(int i=0;i<blocks_1.size();i++)
 	{
 		blocks_1[i].destroy(x+width,y);
 		blocks_1[i].destroy(x-width,y);
 		blocks_1[i].destroy(x,y+height);
 		blocks_1[i].destroy(x,y-height);
 	}
 }

class Point 
{
  public: 
  	 Point(int init_x, int init_y)
  	 { x=init_x;
  	 	y=init_y;
	}
	int get_x(){return x;};
	int get_y(){return y;};
 private:
    int x;
    int y;
};

void Map::create_keys_and_powerups()
{
	srand(time(0));
	vector<Block_1> temp_blocks=blocks_1;
	random_shuffle(temp_blocks.begin(),temp_blocks.end());
	for (int i=0;i<(num_of_keys); i++)
	{
		keys.push_back(temp_blocks[i].put_key_under());
	}
	hearts.push_back(temp_blocks[num_of_keys].put_heart_under());
	shoes.push_back(temp_blocks[num_of_keys+1].put_shoes_under());

}

bool Map::does_player_intersect_keys(FloatRect bounds)
{
	for (int i=0;i<keys.size();i++)
 	{
 		if(keys[i].get_global_bounds().intersects(bounds)&&(!keys[i].is_found()))
 		{
 			keys[i].key_got();
 			return true;
 		}
 	}
}

bool Map::does_player_intersect_door(FloatRect bounds)
{
	for (int i=0;i<doors.size();i++)
 	{
 		if(doors[i].get_global_bounds().intersects(bounds))
 		{
 			return true;
 		}
 	}
 	return false;
}

bool Map::does_player_intersect_heart(FloatRect bounds)
{
	for (int i=0;i<hearts.size();i++)
 	{
 		if(hearts[i].get_global_bounds().intersects(bounds)&&(!hearts[i].is_found()))
 		{
 			hearts[i].heart_got();
 			return true;
 		}
 	}
 	return false;
}

bool Map::does_player_intersect_shoes(FloatRect bounds)
{
	for (int i=0;i<hearts.size();i++)
 	{
 		if(shoes[i].get_global_bounds().intersects(bounds)&&(!shoes[i].is_found()))
 		{
 			shoes[i].shoes_got();
 			return true;
 		}
 	}
 	return false;
}
