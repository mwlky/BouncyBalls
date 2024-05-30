#include "Core.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Core {

Core::Core() {

  m_Window = new sf::RenderWindow(sf::RenderWindow(
      sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bouncy Balls"));

  m_Window->setFramerateLimit(60);

  Init();
}

Core::~Core() { delete m_Window; }

void Core::Init() {

  sf::Clock deltaClock;
  float lastTime = 0;

  sf::Font font;
  font.loadFromFile("../fonts/Coffee Fills.ttf");

  while (m_Window->isOpen()) {

    HandleEvents();
    Render();
    Tick();


    float currentTime = deltaClock.restart().asSeconds();
    float deltaTime = currentTime - lastTime;
    float fps = 1.f / deltaTime;
    lastTime = currentTime;

    sf::Text Text("Fps " + std::to_string(fps), font);
    m_Window->draw(Text);
    std::cout << fps << std::endl;
  }
}

void Core::HandleEvents() {

  sf::Event outEvent;

  while (m_Window->pollEvent(outEvent)) {
    if (outEvent.type == sf::Event::Closed) {

      m_Window->close();
    }
  }
}

void Core::Render() {

  m_Window->display();
  m_Window->clear();
}

void Core::Tick() {}

} // namespace Core
