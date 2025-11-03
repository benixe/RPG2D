#pragma once
#include <vector>

class Entity;

class System {
public:
    virtual ~System() = default;
    virtual void update(std::vector<Entity*>& entities, float deltaTime) = 0;
};