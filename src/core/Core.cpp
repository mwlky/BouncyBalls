#include "Core.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
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

            DisplayFPS(font, deltaClock);
            float deltaTime = CalculateDeltaTime(lastTime, deltaClock);

            Tick(deltaTime);
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

    void Core::Tick(float deltaTime) {}

    float Core::CalculateDeltaTime(float& lastTime, sf::Clock& clock) {

        float currentTime = clock.restart().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        return deltaTime;
    }

    void Core::DisplayFPS(const sf::Font &Font, sf::Clock &clock) {
        float fps = 1.f / clock.getElapsedTime().asSeconds();
        std::string text = "FPS: " + std::to_string(fps);

        sf::Text textToDraw(text, Font);
        m_Window->draw(textToDraw);
    }

} // namespace Core
