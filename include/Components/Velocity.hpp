#pragma once
#include "Core/Component.hpp"
#include <SFML/System/Vector2.hpp>

class Velocity : public Component {
public:
    sf::Vector2f velocity = { 0.0f, 0.0f };
};