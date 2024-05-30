#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace Application {
class Circle {

public:
  Circle(int radius);
  ~Circle() = default;

  void Tick(float deltaTime);

  sf::CircleShape GetShape() const { return m_Shape; }

private:
  sf::CircleShape m_Shape;

  sf::Vector2f m_Velocity;
  sf::Vector2f m_Position;
};
} // namespace Application