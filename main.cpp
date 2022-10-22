#include "UI.h"
#include "utility.h"
#include "ResourceManager.h"

int main() {
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 500), "Hello");
    auto win = std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 500), "World!");

    UI ui(window);
    UI secondary(window);
    UI ui2(win);
    ResourceManager manager;
    auto tex = manager.getTexture("cowcar");

    auto snd = manager.getSoundBuffer("assets/sounds/sound.mp3");
    sf::Sound sound;
    sound.setBuffer(*snd);
    sound.play();

    auto font = manager.getFont("assets/fonts/FuzzyBubbles-Regular.ttf");
    sf::Text text("Hello World!", *font, 30);
    text.setFillColor(sf::Color::Red);

    auto font2 = manager.getFont("assets/fonts/FuzzyBubbles-Reg.ttf");
    sf::Text text2("Hello World!", *font2, 30);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(30, 30);

    UIElement elem1(sf::Vector2i(100, 100), sf::Vector2u(50, 50));
    elem1.loadTexture("cowcar.png");

    UIElement elem2(sf::Vector2i(100, 250), sf::Vector2u(100, 50));
    elem2.loadTexture("cowcar.png");

    UIElement elem3(sf::Vector2i(400, 400), sf::Vector2u(75, 20), tex);
    
    ui2.addElement(elem1);
    ui2.addElement(elem2);
    ui.addElement(elem2);
    secondary.addElement(elem3);

    while (window->isOpen() || win->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win->close();
            }
        }

        window->clear();
        win->clear();
        ui.draw();
        secondary.draw();
        ui2.draw();
        window->draw(text);
        window->draw(text2);
        window->display();
        win->display();
    }
}