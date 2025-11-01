#pragma once
#include <vector>
#include <string>
#include "Component.hpp"

class Entity {
	std::vector<Component*> components;
	bool m_alive = true;
	std::string m_tag = "default";
	static size_t nextId;
	size_t m_id = 0;

public:
	Entity();
	~Entity();

	void addComponent(Component* component);

	template<typename T> T* getComponent() {
		for (auto comp : components){
			T * result = dynamic_cast<T*>(comp);

			if (result != nullptr) {
				return result;
			}
		}
		return nullptr;
	};

	template<typename T> bool hasComponent() {
		return (getComponent<T>() != nullptr);
	
	};

	size_t getId() const {
		return m_id;
	};

	const std::string& tag() const {
		return m_tag;
	}

};