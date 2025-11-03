#include <iostream>
#include <SFML/Graphics.hpp>
#include "Components/Transform.hpp"
#include "Core/Entity.hpp"

enum directions { down, right, up, left };

int main() {

    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Tuto");
    window->setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("../../../assets/images/Sprite.png")) {
        std::cerr << "ERROR::COULD NOT LOAD FILE::assets/images/Sprite.png" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture);
    sf::IntRect dir[4];
    for (int i = 0; i < 4; i++) {
        dir[i] = sf::IntRect({ {32 * i, 0 }, { 32,32 } });
    }

    sprite.setTextureRect(dir[down]);
    sprite.setOrigin({ 16, 16 });
    sprite.setPosition({ width / 2.0f, height / 2.0f });

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window->close();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))) {
            sprite.move({ 0.0f, 1.0f });
            sprite.setTextureRect(dir[down]);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))) {
            sprite.move({ 0.0f, -1.0f });
            sprite.setTextureRect(dir[up]);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))) {
            sprite.move({ 1.0f, 0.0f });
            sprite.setTextureRect(dir[right]);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))) {
            sprite.move({ -1.0f, 0.0f });
            sprite.setTextureRect(dir[left]);
        }

        window->clear(sf::Color::Black);
        window->draw(sprite);
        window->display();
    }

    delete window;
    return 0;
}