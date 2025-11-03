#pragma once
#include "../Core/Component.hpp"
#include <SFML/System/Vector2.hpp> 


class Transform : public Component{
public :
    sf::Vector2f position = { 0.0f, 0.0f };
    float rotation = 0.0f;  
    sf::Vector2f scale = { 1.0f, 1.0f }; 

};