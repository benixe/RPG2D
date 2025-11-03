#include "Core/EntityManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/PhysicsSystem.hpp"

class Scene {
private:
    EntityManager entityManager;
    RenderSystem* renderSystem;
    PhysicsSystem* physicsSystem;

public:
    Scene(sf::RenderWindow* window);
    void update(float deltaTime);
    EntityManager& getEntityManager();
    ~Scene();
};