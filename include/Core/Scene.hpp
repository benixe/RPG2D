#include "Core/EntityManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/InputSystem.hpp"
#include "Systems/AnimationSystem.hpp"

class Scene {
private:
    EntityManager entityManager;
    RenderSystem* renderSystem;
    PhysicsSystem* physicsSystem;
    InputSystem* inputSystem;
    AnimationSystem* animationSystem;

public:
    Scene(sf::RenderWindow* window);
    void update(float deltaTime);
    EntityManager& getEntityManager();
    ~Scene();
};