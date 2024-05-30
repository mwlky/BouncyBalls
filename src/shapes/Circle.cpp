#include "Circle.h"

namespace Application {

    Circle::Circle(int radius) {
        m_Shape = sf::CircleShape(radius);
        m_Shape.setPosition(640 - radius * 0.5, 360);
        m_Velocity.y = 10;
    }

    void Circle::Tick(float deltaTime) {

        sf::Vector2f newPos = m_Shape.getPosition();
        m_Velocity.y += G * deltaTime;

        if (CollidesScreenVertically()) {
            BounceVertically();
        }

        sf::Vector2f displacement =
                sf::Vector2f(m_Velocity.x * deltaTime, m_Velocity.y * deltaTime);

        sf::Vector2f targetPosition = newPos + displacement;
        m_Shape.setPosition(targetPosition);
    }

    bool Circle::CollidesScreenVertically() {
        sf::Vector2f position = m_Shape.getPosition();
        float radius = m_Shape.getRadius();

        return position.y <= 0 || position.y + 2 * radius >= SCREEN_HEIGHT;
    }

    void Circle::BounceVertically() {

        m_Velocity.y = -m_Velocity.y;

        sf::Vector2f position = m_Shape.getPosition();
        float radius = m_Shape.getRadius();

        if (position.y <= 0) {
            position.y = 0;
        } else {
            position.y = SCREEN_HEIGHT - 2 * radius;
        }

        m_Shape.setPosition(position);
    }

} // namespace Application
