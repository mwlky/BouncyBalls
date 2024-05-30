#include "Circle.h"
#include <SFML/System/Vector2.hpp>

namespace Application {

Circle::Circle(int radius){

    m_Shape = sf::CircleShape(radius);
}

void Circle::Tick(float deltaTime){

    float targetX = m_Position.x + m_Velocity.x;
    float targetY = m_Position.y + m_Velocity.y;

    sf::Vector2f newPos(sf::Vector2f(targetX, targetY));

    m_Shape.setPosition(newPos);
}

}