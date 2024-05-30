#include "SFML/Graphics.hpp"

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

    float CalculateDeltaTime(float& lastTime, sf::Clock& clock);
    void DisplayFPS(const sf::Font& Font, sf::Clock& clock);

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    sf::RenderWindow* m_Window = nullptr;

};
} // namespace Core