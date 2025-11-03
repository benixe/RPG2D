#include "Entity.hpp"

class EntityManager {
private:
    std::vector<Entity*> entities;

public:
    Entity* createEntity();
    void removeEntity(Entity* entity);
    std::vector<Entity*>& getEntities();
    ~EntityManager(); 
};