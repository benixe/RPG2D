#pragma once
#include "Core/System.hpp"
#include <SFML/Graphics.hpp>

class RenderSystem : public System {
private:
    sf::RenderWindow* window;

public:
    RenderSystem(sf::RenderWindow* win);
    void update(float deltaTime) override;
};