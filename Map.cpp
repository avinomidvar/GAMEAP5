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
const int width=25;
const int height=40;

Map::Map(string file_name)
{
	ifstream file;
    file.open(file_name);
    string line;
    getline(file,line);
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
		{
			cout<<x_position<<" "<<y_position<<endl;
				blocks_1.push_back(Block_1(x_position,y_position,"Block_1.png"));
				cout<<"i detected a B"<<endl;
		}
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
