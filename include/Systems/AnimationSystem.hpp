#pragma once
#include "Core/System.hpp"

class AnimationSystem : public System {
public:
	AnimationSystem();
	void update(std::vector<Entity*>& entities, float deltaTime);
};