#include "editor.h"
#include "saving.h"

void editor::Init()
{	
	m_backgroundSprite.setTexture(*kage::TextureManager::getTexture("data/sky.jpg"));
	spriteID = 1;
	tileWidth = screenSize.x / CELL_COUNT_X;
	tileHeight = (screenSize.y * 0.5) / CELL_COUNT_Y;

	ChangeGUITexture(1);

	for (size_t i = 0; i < CELL_COUNT_X - 1; i++)
	{
		line[i] = sf::RectangleShape(sf::Vector2f(3, tileHeight * (CELL_COUNT_Y - 1)));
		//line[i].setPosition(sf::Vector2f(100 + i * 64, 100));
		line[i].setPosition(tileWidth + i * tileWidth, tileHeight);
		line[i].setFillColor(sf::Color::Green);
	}


	//horizontal
	for (size_t i = 0; i < CELL_COUNT_Y; i++)
	{
		line2[i] = sf::RectangleShape(sf::Vector2f((tileWidth * (CELL_COUNT_X - 2) + 3), 3));
		//line2[i].setPosition(sf::Vector2f(100, 100 + i * 64));
		line2[i].setPosition(tileWidth, tileHeight + (i * tileHeight));
		line2[i].setFillColor(sf::Color::Green);
	}
	
}

void editor::Draw()
{
	
	for (size_t i = 0; i < CellCount; i++)
	{
		
			if (tileArray[i].draw)
			{
				App::m_window.draw(tileArray[i].tileSprite);
			}
			
		
	}
	for (size_t i = 0; i < CELL_COUNT_X; i++)
	{
		App::m_window.draw(line[i]);
	}

	for (size_t i = 0; i < CELL_COUNT_Y; i++)
	{
		App::m_window.draw(line2[i]);
	}

	for (size_t i = 0; i < (CELL_TOTAL_COUNT); i++)
	{
		App::m_window.draw(tiles[i]);
	}
	App::m_window.draw(guiSprite);
	
}

void editor::Run()
{
	
		bool m_running;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && App::m_window.hasFocus())
		{
			m_running = false;
		}
		bool menuCheck = false;
		ImGui::Begin("Kage2D");
		if (ImGui::Button("Exit"))
		{
			m_running = false;
		}
		else if (ImGui::Button("Dirt"))
		{
			menuCheck = true;
			spriteID = 1;
			ChangeGUITexture(spriteID);
		}
		else if (ImGui::Button("Grass"))
		{
			menuCheck = true;
			spriteID = 2;
			ChangeGUITexture(spriteID);
		}
		else if (ImGui::Button("Water"))
		{
			menuCheck = true;
			spriteID = 3;
			ChangeGUITexture(spriteID);
		}
		else if (ImGui::Button("Clear"))
		{
			menuCheck = true;
			spriteID = 0;
			ChangeGUITexture(spriteID);
		}
		else if (ImGui::Button("Save"))
		{
			std::ostringstream os;
			menuCheck = true;
			for (int i : map) {
				os << i << std::endl;
			}
			std::string str(os.str());
			saving::Saved("savefile.txt", str);
		}
		else if (ImGui::Button("Load"))
		{
			menuCheck = true;
			saving::Load("savefile.txt",map,tileArray);
		}
		ImGui::End();

		if (menuCheck == false && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			mousePos = sf::Mouse::getPosition(App::m_window);
			int x = mousePos.x / tileWidth;
			int y = mousePos.y / tileHeight;
			int xx = (x) * tileWidth;
			int yy = (y) * tileHeight;
			int i = (y - 1) * 13 + (x - 1);

			if (x > 13 || x < 1) return;

			if (i > -1 && i < CellCount)
			{
				tileArray[i].setTileType(spriteID);
				tileArray[i].placeTile(sf::Vector2i(xx, yy));
				map[i] = spriteID;
				tileArray[i].draw = true;
			}

		}
		sf::Vector2f mousePosition = (sf::Vector2f)sf::Mouse::getPosition(App::m_window);
		guiSprite.setPosition(mousePosition.x, mousePosition.y);
		
}


/*void editor::LoadTiles(int* map)
{
	for (size_t i = 0; i < CELL_TOTAL_COUNT; i++)
	{
		if (map[i] == 0)
		{
			std::cout << "this is 0" << std::endl;
	//		tileArray[i].draw = true;
		}
		else if (map[i] == 1) {
			std::cout << "this is 1" << std::endl;
	//		tileArray[i].draw = true;
		}
		else if (map[i] == 2) {
			std::cout << "this is 2" << std::endl;
	//		tileArray[i].draw = true;
		}
		else if (map[i] == 3) {
			std::cout << "this is 3" << std::endl;
	//		tileArray[i].draw = true;
		}
		else {
			std::cout << "nothing" << std::endl;
		}
	}
}
*/
void editor::Close()
{
	
}


void editor::ChangeGUITexture(int spriteID)
{
	
	switch (spriteID)
	{
	case 0: {
		guiSprite.setTexture(*kage::TextureManager::getTexture("data/null.png"));
		break;
	}
	case 1: {
		guiSprite.setTexture(*kage::TextureManager::getTexture("data/dirt.png"));
		break;
	}
	case 2: {
		guiSprite.setTexture(*kage::TextureManager::getTexture("data/grass.png"));
		break;
	}
	case 3: {
		guiSprite.setTexture(*kage::TextureManager::getTexture("data/water.png"));
		break;
	}

	default:
		break;
	}
	
}

