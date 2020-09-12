#include "button.h"
#include "scene.h"

button::button(std::string buttonName)
{
	buttonText = new sf::Text(buttonName, scene::sceneFont);
	buttonBound = buttonText->getGlobalBounds();
}

bool button::checkPointer(sf::Vector2f MousePosition)
{
	return buttonBound.contains(MousePosition);
}