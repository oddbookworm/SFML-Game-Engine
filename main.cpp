#include "UI.h"
#include "utility.h"
#include "ResourceManager.h"

int main() {
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 500), "Hello");

    UI ui(window);
    ResourceManager manager;
    auto tex = manager.getTexture("bad.png");

    UIElement elem1(sf::Vector2i(100, 100), sf::Vector2u(50, 50));
    elem1.loadTexture("assets/images/missing_texture.png");

    UIElement elem2(sf::Vector2i(100, 250), sf::Vector2u(100, 50));
    elem2.loadTexture("cowcar.png");

    std::cout << (tex == nullptr) << std::endl;
    UIElement elem3(sf::Vector2i(400, 400), sf::Vector2u(75, 20), *tex);
    // elem3.loadTexture("cowcar.png");
    
    ui.addElement(elem1);
    ui.addElement(elem2);
    ui.addElement(elem3);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
        ui.draw();
        window->display();
    }
}