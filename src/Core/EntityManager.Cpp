#include "Core/EntityManager.hpp"

EntityManager::~EntityManager() {
	for (auto entity : entities) {
		delete entity;
	}
}

void EntityManager::removeEntity(Entity* entity) {
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		if (*it == entity) {
			delete* it;
			entities.erase(it);
			return;
		}
	}
}

std::vector<Entity*>& EntityManager::getEntities() {
	return entities;
}

Entity* EntityManager::createEntity(){
	Entity* ent = new Entity;
	entities.push_back(ent);
	return ent;
}