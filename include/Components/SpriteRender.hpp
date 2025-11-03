#pragma once
#include "Core/Component.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

class SpriteRender : public Component {
public:
    std::optional<sf::Sprite> sprite;
    sf::Texture* texture = nullptr;
};