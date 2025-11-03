#include "Core/Scene.hpp"


Scene::Scene(sf::RenderWindow* window){
	renderSystem = new RenderSystem(window);
	physicsSystem = new PhysicsSystem();
}

EntityManager& Scene::getEntityManager(){
	return entityManager;
}

void Scene::update(float deltaTime) {
	physicsSystem->update(entityManager.getEntities(), deltaTime);
	renderSystem->update(entityManager.getEntities(), deltaTime);
}

Scene::~Scene() {
	delete renderSystem;
	delete physicsSystem;
}
