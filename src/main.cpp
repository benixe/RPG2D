#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/Scene.hpp"
#include "Core/Entity.hpp"
#include "Components/Transform.hpp"
#include "Components/SpriteRender.hpp"
#include "Components/Velocity.hpp"
#include "Components/PlayerInput.hpp"

int main() {
    unsigned int width = 640;
    unsigned int height = 360;

    sf::RenderWindow window(sf::VideoMode({ width, height }), "RPG 2D - ECS");
    window.setFramerateLimit(60);

    // Créer la scène
    Scene scene(&window);

    // Charger la texture
    sf::Texture texture;
    if (!texture.loadFromFile("../../../assets/images/Sprite.png")) {
        std::cerr << "Erreur texture" << std::endl;
        return -1;
    }

    // Créer le joueur avec ECS
    Entity* player = scene.getEntityManager().createEntity();
    player->setTag("player");

    Transform* transform = new Transform();
    PlayerInput* playerInput = new PlayerInput();
    transform->position = { width / 2.0f, height / 2.0f };
    player->addComponent(transform);
    player->addComponent(playerInput);

    SpriteRender* spriteComp = new SpriteRender();
    spriteComp->texture = &texture;
    spriteComp->sprite = sf::Sprite(texture);
    spriteComp->sprite->setTextureRect(sf::IntRect({ {0, 0}, {32, 32} }));
    spriteComp->sprite->setOrigin({ 16, 16 });
    player->addComponent(spriteComp);

    Velocity* velocity = new Velocity();
    player->addComponent(velocity);

    // Boucle de jeu
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Render
        window.clear(sf::Color::Black);

        // Update ECS (inclut le rendering via RenderSystem)
        scene.update(deltaTime);

        window.display();
    }
}