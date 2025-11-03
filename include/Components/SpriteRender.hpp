#pragma once
#include "Core/Component.hpp"
#include <SFML/Graphics.hpp>

class SpriteRender : public Component {
public:
	sf::Sprite sprite;
	sf::Texture* texture = nullptr;
};