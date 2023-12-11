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
using namespace std;
using namespace sf;
const int width=40;
const int height=50;
const int window_height=600;
const int window_width=800;
const int n_vertical=11;
const int n_horizontal=20;
const int num_of_keys=3;

Map::Map(string file_name)
{
	ifstream file;
    file.open(file_name);
    string line;
	int row=0;    
    while (getline(file, line))
    {
       create_elements(line,row);
       row++;
    }
    file.close();
    create_keys();
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
	for (int i=0;i<keys.size();i++)
			keys[i].draw(window);
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
 	bool is_found=false;
 	int near_x;
 	int near_y;
 	for (int j=0;j<n_vertical;j++)
 	{
 		if(is_found)
 			break;
 		for (int i=0;i<n_horizontal;i++)
 		{
 			near_x=i*width;
 			near_y=j*height;
 			if((abs(x-near_x)<10)&&(abs(y-near_y)<10))
 				{
 					is_found=true;
 					break;
 				}
 				
 		}

 	}
 	for(int i=0;i<blocks_1.size();i++)
 	{
 		blocks_1[i].destroy(near_x+width,near_y);
 		blocks_1[i].destroy(near_x-width,near_y);
 		blocks_1[i].destroy(near_x,near_y+height);
 		blocks_1[i].destroy(near_x,near_y-height);
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

void Map::create_keys()
{
	srand(time(0));
	vector<Block_1> temp_blocks=blocks_1;
	random_shuffle(temp_blocks.begin(),temp_blocks.end());
	for (int i=0;i<num_of_keys; i++)
	{
		keys.push_back(temp_blocks[i].put_key_under());
	}
	cout<<keys.size()<<endl;
}
