#include "SFML/Graphics.hpp"
#include "../shapes/Circle.h"

namespace Core {

class Core {

public:
    Core();
    ~Core();

private:

    void Init();
    void Tick(float deltaTime);
    void Render();
    void HandleEvents();

    void SpawnCircle(int xPos, int yPos);

    float CalculateDeltaTime(double &lastTime, sf::Clock &clock);
    void DisplayFPS(float currentTime);

    sf::RenderWindow* m_Window = nullptr;

    sf::Text m_FpsText;
    sf::Font m_FpsFont;

    std::vector<Application::Circle> m_Circles;

};
} // namespace Core