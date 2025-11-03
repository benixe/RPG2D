#include "Core/EntityManager.hpp"

EntityManager::~EntityManager() {
	for (auto entity : entities) {
		delete entity;
	}
}
void EntityManager::removeEntity(Entity *entity) {
	entities;
}

std::vector<Entity*>& EntityManager::getEntities() {
	return entities;
}

Entity* EntityManager::createEntity(){
	return nullptr;
}