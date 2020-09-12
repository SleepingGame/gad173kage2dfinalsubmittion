#pragma once
#include "scene.h"

class editor : public scene
{
public:
	virtual void Init();
	virtual void Run();
	virtual void Draw();
	virtual void Close();

	void ChangeGUITexture(int spriteID);
	

	Tile tileArray[INNER_CELL_TOTAL_COUNT];
	int CellCount = (CELL_COUNT_X - 2) * (CELL_COUNT_Y - 1);
	sf::Vector2i mousePos;
	sf::Vector2i tileid;
	sf::RectangleShape line[CELL_COUNT_X];
	sf::RectangleShape line2[CELL_COUNT_Y];
	sf::Sprite tiles[CELL_TOTAL_COUNT];
	float tileWidth;
	float tileHeight;

	//cell size defenition

	int currenttile;
	int spriteID;

	sf::Sprite m_backgroundSprite;
	sf::Sprite guiSprite;

	
	
	
	int map[INNER_CELL_TOTAL_COUNT] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	
	Tile water;
	Tile dirt;
	Tile grass;
	

};

