#include "game.h"
#include "scene.h"
#include "saving.h"

sf::Vector2u scene::screenSize;
sf::Font scene::sceneFont;

void game::Init() {
	std::cout << "This is caused by scene::init in game.cpp" << std::endl;

	//std::string data = saving::Load("savefile", editor::map);
	/*for (size_t i = 0; i < 5; i++)
	{
		int y = i / (CELL_COUNT_X - 2);
		int x = i - y * (CELL_COUNT_X - 2);
		tileArray[i] = new Tile();
		tileArray[i]->setTileType(data[i-48]);
		tileArray[i]->placeTile(sf::Vector2i(x * tileWidth, y * tileHeight));
	}*/
	
}


void game::Run() {

}

void game::Draw() {

}


void game::Close() {

}

game::game(int* map):
	m_map(map)
{

}

