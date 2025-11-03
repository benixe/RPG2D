#include "Systems/PhysicsSystem.hpp"
#include "Core/Entity.hpp"
#include "Components/Transform.hpp"
#include "Components/Velocity.hpp"

PhysicsSystem::PhysicsSystem() {}

void PhysicsSystem::update(std::vector<Entity*>& entities, float deltaTime) {
    for (auto* entity : entities) {
        Transform* transform = entity->getComponent<Transform>();
        Velocity* velocity = entity->getComponent<Velocity>();

        if (transform != nullptr && velocity != nullptr) {
            transform->position += velocity->velocity * deltaTime;
        }
    }
}