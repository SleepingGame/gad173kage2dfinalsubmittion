#pragma once
#include "scene.h"
class game : public scene
{
	int* m_map;

public:

	virtual void Init();
	virtual void Run();
	virtual void Draw();
	virtual void Close();

	game(int* map);

	std::string sceneName;

	static sf::RenderWindow* m_window;
	static sf::Vector2u screenSize;
	static sf::Font sceneFont;
};

