#pragma once
#include "app.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#define CELL_COUNT_X 15
#define CELL_COUNT_Y 5
#define CELL_TOTAL_COUNT  CELL_COUNT_X * CELL_COUNT_Y

#define INNER_CELL_COUNT_X 13
#define INNER_CELL_COUNT_Y 4
#define INNER_CELL_TOTAL_COUNT  INNER_CELL_COUNT_X * INNER_CELL_COUNT_Y

class Tile
{
public:
	int id = 0;
	sf::Sprite tileSprite;
	bool draw = false;
	void Tile::setTileType(int spriteID)
	{
		switch (spriteID)
		{
		case 0: {
			tileSprite = *kage::TextureManager::getSprite("data/null.png");
			break;
		}
		case 1: {
			tileSprite = *kage::TextureManager::getSprite("data/dirt.png");
			break;
		}
		case 2: {
			tileSprite = *kage::TextureManager::getSprite("data/grass.png");
			break;
		}
		case 3: {
			tileSprite = *kage::TextureManager::getSprite("data/water.png");
			break;
		}

		default:
			break;
		}
	}

	void Tile::placeTile(sf::Vector2i mousePosition)
	{
		tileSprite.setPosition(sf::Vector2f(mousePosition));
		std::cout << "this is called example.h" << std::endl;
	}
};


class scene
{
public:

	virtual void Init();
	virtual void Run();
	virtual void Draw();
	virtual void Close();

	std::string sceneName;

	static sf::Vector2u screenSize;
	static sf::Font sceneFont;
	float tileWidth;
	float tileHeight;
};

