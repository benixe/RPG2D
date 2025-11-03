#pragma once
#include "Core/System.hpp"

class PhysicsSystem : public System {
public:
	PhysicsSystem();
	void update(std::vector<Entity*>& entities, float deltaTime) override;
};