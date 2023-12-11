# include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Map.hpp"
#include "Block_1.hpp"
#include "Block_2.hpp"
using namespace std;
using namespace sf;
const int width=45;
const int height=50;

Map::Map(string file_name)
{
	ifstream file;
    file.open(file_name);
    string line;
   // float game_time=stof(line)*60.f;
	int row=0;    
    while (getline(file, line))
    {
       create_elements(line,row);
       row++;
    }
    file.close();
}

void Map::create_elements(string line,int row)
{
	for (int i=0; i<line.length();i++)
	{
		int x_position=i*width;
		int y_position=row*height;
		if (line[i]=='B')
				blocks_1.push_back(Block_1(x_position,y_position,"Block_1.png"));
		if(line[i]=='P')
				blocks_2.push_back(Block_2(x_position,y_position,"Block_2.png"));	
	}	
}

void Map::draw(RenderWindow& window)
{
	for (int i=0;i<blocks_1.size();i++)
	    (blocks_1[i].draw(window));
    for(int i=0;i<blocks_2.size();i++)
		(blocks_2[i].draw(window));
}
 bool Map::does_intersect_blocks(FloatRect bounds)
 {
 	for (int i=0;i<blocks_1.size();i++)
 	{
 		if(bounds.intersects(blocks_1[i].get_global_bounds()))
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
