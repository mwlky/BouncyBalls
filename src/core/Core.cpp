#include "Core.h"

namespace Core {

Core::Core() {

  m_Window = new sf::RenderWindow(sf::RenderWindow(
      sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bouncy Balls"));

  m_Window->setFramerateLimit(60);
}

Core::~Core() { delete m_Window; }

void Core::Init() {

  while (m_Window->isOpen()) {

    sf::Event outEvent;

    while (m_Window->pollEvent(outEvent)) {
      if (outEvent.type == sf::Event::Closed)
        m_Window->close();
    }
  }
}

} // namespace Core
