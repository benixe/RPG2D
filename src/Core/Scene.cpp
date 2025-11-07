#include "Core/Scene.hpp"


Scene::Scene(sf::RenderWindow* window){
	renderSystem = new RenderSystem(window);
	physicsSystem = new PhysicsSystem();
	inputSystem = new InputSystem();
	animationSystem = new AnimationSystem();
}

EntityManager& Scene::getEntityManager(){
	return entityManager;
}

void Scene::update(float deltaTime) {
	inputSystem->update(entityManager.getEntities(), deltaTime);
	animationSystem->update(entityManager.getEntities(), deltaTime);
	physicsSystem->update(entityManager.getEntities(), deltaTime);
	renderSystem->update(entityManager.getEntities(), deltaTime);

}

Scene::~Scene() {
	delete renderSystem;
	delete physicsSystem;
	delete inputSystem;
	delete animationSystem;
}
