#pragma once
#include <SFML/Graphics.hpp>

class button
{
public: 
	//text
	sf::Text* buttonText;
	button(std::string buttonName);
	bool button::checkPointer(sf::Vector2f MousePosition);
	sf::FloatRect buttonBound;

	//check function



};