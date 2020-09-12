#include "scene.h"
#include "example.h"

Example::Example() : App()
{
}

Example::~Example()
{
}

Example& Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	currentSceneID = sceneID::editor;
	screenSize = m_window.getSize();
	scene::screenSize = screenSize;
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	//scene::sceneFont.loadFromFile("savefile.txt");
	
	editor* e = new editor();
	allScenes[(int)sceneID::editor] =e;
	allScenes[(int)currentSceneID]->Init();

	//vertical

	return true;
}

void Example::update(float deltaT)
{
	allScenes[(int)currentSceneID]->Run();
}


void Example::render()
{
	allScenes[(int)currentSceneID]->Draw();
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}
