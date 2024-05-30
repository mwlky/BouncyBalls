#include "Core.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>

namespace Core {

    Core::Core() {

        m_Window = new sf::RenderWindow(sf::RenderWindow(
                sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Bouncy Balls"));

        m_Window->setFramerateLimit(60);

        m_FpsFont.loadFromFile("../fonts/Coffee Fills.ttf");

        Init();
    }

    Core::~Core() { delete m_Window; }

    void Core::Init() {

        sf::Clock deltaClock;
        double lastTime = 0;

        Application::Circle circle(30);
        m_Circles.push_back(circle);

        while (m_Window->isOpen()) {
            float deltaTime = CalculateDeltaTime(lastTime, deltaClock);

            HandleEvents();
            Tick(deltaTime * 0.001f);

            Render();
        }
    }

    void Core::HandleEvents() {

        sf::Event outEvent;

        while (m_Window->pollEvent(outEvent)) {

            if (outEvent.type == sf::Event::Closed)
                m_Window->close();
        }
    }

    void Core::Render() {

        m_Window->clear();
        m_Window->draw(m_FpsText);

        for (Application::Circle &circle: m_Circles)
            m_Window->draw(circle.GetShape());

        m_Window->display();
    }

    void Core::Tick(float deltaTime) {

        for (Application::Circle &circle: m_Circles)
            circle.Tick(deltaTime);
    }

    float Core::CalculateDeltaTime(double &lastTime, sf::Clock &clock) {

        sf::Time currentTime = clock.restart();
        double deltaTime = currentTime.asMilliseconds() - lastTime;
        lastTime = currentTime.asSeconds();

        DisplayFPS(currentTime.asSeconds());

        return deltaTime * 0.001f;
    }

    void Core::DisplayFPS(float currentTime) {

        m_FpsText.setFont(m_FpsFont);
        m_FpsText.setCharacterSize(40);

        float fps = 1.f / currentTime;
        m_FpsText.setString("FPS: " + std::to_string(fps));
    }

} // namespace Core
