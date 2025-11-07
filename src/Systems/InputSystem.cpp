#include "Core/Entity.hpp"
#include "Systems/InputSystem.hpp"
#include "Components/Velocity.hpp"
#include "Components//PlayerInput.hpp"
#include "SFML/Graphics.hpp"

InputSystem::InputSystem() {

}

void InputSystem::update(std::vector<Entity*>& entities, float deltaTime){
	for (auto *ent : entities) {
		if (ent->hasComponent<PlayerInput>() &&
			ent->hasComponent<Velocity>()) {

			Velocity* velocity = ent->getComponent<Velocity>();
			velocity->velocity = { 0.0f, 0.0f };

			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Z)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))) {
				velocity->velocity.y = -100.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
				velocity->velocity.y = 100.0f;
			} 
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Q)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))) {
				velocity->velocity.x = -100.0f;
			} 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
				velocity->velocity.x = 100.0f;
			}


		}
	}
}