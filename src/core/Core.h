#include "SFML/Graphics.hpp"

namespace Core {

class Core {

public:
    Core();
    ~Core();

    void Init();

private:

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    sf::RenderWindow* m_Window = nullptr;

};
} // namespace Core