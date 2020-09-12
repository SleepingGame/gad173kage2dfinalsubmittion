#include "saving.h"
#include "editor.h"
using namespace std;

void saving::Saved(std::string fileName, std::string Filecontents)
{
	ofstream myfile;
	myfile.open(fileName);
	myfile << Filecontents;
	myfile.close();


}


void saving::Load(std::string fileName, int map[], Tile tileArray[])
{
	std::string line;
	std::ifstream myfile(fileName);
	

	if (myfile.is_open())
	{
		std::stringstream buffer;
		buffer << myfile.rdbuf();
		std::string stringData = buffer.str();
		myfile.close();
		std::cout << stringData << std::endl;

		for (size_t i = 0; i < INNER_CELL_TOTAL_COUNT; i++)// find and fix the cell count
		{
			int yStep = i / INNER_CELL_COUNT_X;
			int xStep = i - (yStep * INNER_CELL_COUNT_X);
	
			float tileWidth = screenSize.x / CELL_COUNT_X;
			float tileHeight = (screenSize.y * 0.5) / CELL_COUNT_Y;

			tileArray[i].setTileType((int)stringData[i] - 48);
			tileArray[i].placeTile(sf::Vector2i(tileWidth + (xStep * tileWidth), tileHeight + (yStep * tileHeight)));
			tileArray[i].draw = true;
			
			/*
			tileArray[i].tileSprite.setPosition(xx, yy);
			tileArray[i].placeTile(sf::Vector2i());
			tileArray[i].draw = true;
			*/
		}

	}
	/*
	if (myfile.is_open())
	{
		editor edit;
		while (getline(myfile, line))
		{
			
			int xx = screenSize.x / CELL_COUNT_X; 
			int yy = screenSize.y / CELL_COUNT_Y; 

			int elementOne = std::stoi(line);
			map[index] = elementOne;
			std::cout << map[index] << std::endl;

			
			tileArray[index].setTileType(elementOne);
			tileArray[index].tileSprite.setPosition(xx, yy);
			tileArray[index].placeTile(sf::Vector2i());
			tileArray[index].draw = true;

			index++;
		}
	}

	*/
}