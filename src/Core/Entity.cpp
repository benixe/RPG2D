#include "Entity.hpp"

// Initialisation de la variable statique
size_t Entity::nextId = 1;

// Implémentation du constructeur
Entity::Entity() {
    m_id = nextId;
    nextId++;
}

// Implémentation du destructeur
Entity::~Entity() {
    for (auto comp : components) {
        delete comp;
    }
}

// Implémentation de addComponent
void Entity::addComponent(Component* component) {
    components.push_back(component);
}



