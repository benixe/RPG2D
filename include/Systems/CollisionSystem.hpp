#pragma once
#include "Core/System.hpp"

class CollisionSystem : public System {
public:
	CollisionSystem();
	void update(std::vector<Entity*>& entities, float deltaTime) override;

};