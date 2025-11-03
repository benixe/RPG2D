#include "Systems/RenderSystem.hpp"
#include "Core/Entity.hpp"
#include "Components/Transform.hpp"
#include "Components/SpriteRender.hpp"

RenderSystem::RenderSystem(sf::RenderWindow* win) : window(win) {}

void RenderSystem::update(std::vector<Entity*>& entities, float deltaTime) {
    for (auto* entity : entities) {
        Transform* transform = entity->getComponent<Transform>();
        SpriteRender* spriteRender = entity->getComponent<SpriteRender>();

        if (transform != nullptr && spriteRender != nullptr && spriteRender->sprite.has_value()) {
            spriteRender->sprite->setPosition(transform->position);
            spriteRender->sprite->setRotation(sf::degrees(transform->rotation));
            spriteRender->sprite->setScale(transform->scale);
            window->draw(*spriteRender->sprite);
        }
    }
}