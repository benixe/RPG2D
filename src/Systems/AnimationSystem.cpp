#include "Systems/AnimationSystem.hpp"
#include "Core/Entity.hpp"
#include "Components/Transform.hpp"
#include "Components/Velocity.hpp"
#include "Components/SpriteRender.hpp"

AnimationSystem::AnimationSystem() {

}

void AnimationSystem::update(std::vector<Entity*>& entities, float deltaTime) {
	for (auto* ent : entities) {
		if (ent->hasComponent<Velocity>() &&
			ent->hasComponent<SpriteRender>()) {

			Velocity* velocity = ent->getComponent<Velocity>();
			SpriteRender* spriteComp = ent->getComponent<SpriteRender>();

			if (velocity->velocity.y < 0) {
				spriteComp->sprite->setTextureRect(sf::IntRect({ {64, 0}, {32, 32} })); 
			}
			else if (velocity->velocity.y > 0) {
				spriteComp->sprite->setTextureRect(sf::IntRect({ {0, 0}, {32, 32} }));
			}
			else if (velocity->velocity.x > 0) {
				spriteComp->sprite->setTextureRect(sf::IntRect({ {32, 0}, {32, 32} }));
			}
			else if (velocity->velocity.x < 0) {
				spriteComp->sprite->setTextureRect(sf::IntRect({ {96, 0}, {32, 32} }));
			}

		}
	}
}