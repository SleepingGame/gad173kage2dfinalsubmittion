#pragma once
#include "app.h"
#include "scene.h"
#include "editor.h"
#include "game.h"


class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example& inst();
	

	//sprites
	sf::Sprite* m_backgroundSprite;
	sf::Sprite* m_catmyaw;
	sf::Sprite catsprite;
	

	enum class sceneID {
		menu,
		editor,
		options,
		play
	};
	sceneID currentSceneID;

	//textures
	sf::Texture* m_grassTexture;
	sf::Texture* m_dirtTexture;
	sf::Texture* m_waterTexture;

	//screendata
	sf::Vector2u screenSize;
	scene* allScenes[3];
};

