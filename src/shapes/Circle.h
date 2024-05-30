#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "../Macros.h"

namespace Application {
class Circle {

public:
  Circle(int radius);
  ~Circle() = default;

  void BounceVertically();
  void Tick(float deltaTime);


  bool CollidesScreenVertically();

  sf::CircleShape GetShape() const { return m_Shape; }

private:
  sf::CircleShape m_Shape;

  sf::Vector2f m_Velocity;

    sf::Vector2f CalculateNewPosition(float deltaTime);
};
} // namespace Application