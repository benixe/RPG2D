#include "Core/Entity.hpp"

size_t Entity::nextId = 1;

Entity::Entity() {
    m_id = nextId;
    nextId++;
}

Entity::~Entity() {
    for (auto comp : components) {
        delete comp;
    }
}

void Entity::addComponent(Component* component) {
    components.push_back(component);
}
