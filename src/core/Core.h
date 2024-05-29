#include "SFML/Graphics.hpp"

namespace Core {

class Core {

public:
    Core();
    ~Core();

private:

    void Init();
    void Tick();
    void Render();
    void HandleEvents();

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    sf::RenderWindow* m_Window = nullptr;

};
} // namespace Core