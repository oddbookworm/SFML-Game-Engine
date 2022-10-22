#include "UI.h"

UIElement::UIElement() {}

UIElement::UIElement(const sf::Vector2i pos, const sf::Vector2u size) : _pos(pos), _size(size) {}

UIElement::UIElement(const sf::Vector2i pos, const sf::Vector2u size, std::shared_ptr<sf::Texture> tex) : _pos(pos), _size(size), _tex(tex) {
    loadTexture();
}

void UIElement::loadTexture() {
    _tex->setSmooth(_smooth);

    sf::Vector2f texSize = (sf::Vector2f)_tex->getSize();

    _sprite.setTexture(*_tex);
    _sprite.setPosition((sf::Vector2f)_pos);
    
    float scale_x = _size.x / texSize.x;
    float scale_y = _size.y / texSize.y;

    _sprite.setScale(scale_x, scale_y);
}

void UIElement::loadTexture(const std::string& filename) {
    _tex = std::make_shared<sf::Texture>();
    if (filename.length() == 0) {
        throw std::runtime_error("Cannot load texture from empty filename");
    }

    if (!_tex->loadFromFile(filename)) {
        std::cout << filename << " failed to load into a texture!\n";
        return;
    }

    loadTexture();
}

void UIElement::loadTexture(const std::string& filename, bool smooth) {
    _smooth = smooth;
    loadTexture(filename);
}

void UIElement::draw(std::shared_ptr<sf::RenderTexture> _win) {
    _win->draw(_sprite);
}

sf::Vector2i UIElement::getPos() const {
    return _pos;
}

sf::Vector2u UIElement::getSize() const {
    return _size;
}

UIElement::~UIElement() {}

void UI::addElement(const UIElement& elem) {
    _elements.push_back(elem);
}

UI::UI(std::weak_ptr<sf::RenderTarget> win) : _win(win) {
    _surf = std::make_shared<sf::RenderTexture>();
    std::shared_ptr<sf::RenderTarget> winPtr = _win.lock();
    sf::Vector2u size = winPtr->getSize();
    _surf->create(size.x, size.y);    
}

std::vector<UIElement> UI::getElements() const {
    return _elements;
}

void UI::draw() const {
    for (auto elem : _elements) {
        elem.draw(_surf);
        _surf->display();

        auto window = _win.lock();
        window->draw(sf::Sprite(_surf->getTexture()));
    }
}
