#include "UI.h"

UIElement::UIElement() {}

UIElement::UIElement(const sf::Vector2i pos, const sf::Vector2u size) : _pos(pos), _size(size) {}

UIElement::UIElement(const sf::Vector2i pos, const sf::Vector2u size, sf::Texture& tex) : _tex(tex) {
    UIElement(pos, size);

    sf::Vector2f texSize = (sf::Vector2f)_tex.getSize();
    std::cout << texSize << std::endl;

    _sprite.setTexture(_tex);
    _sprite.setPosition((sf::Vector2f)_pos);
    
    float scale_x = _size.x / texSize.x;
    float scale_y = _size.y / texSize.y;

    _sprite.setScale(scale_x, scale_y);
}

void UIElement::loadTexture(std::string filename) {
    if (filename.length() == 0) {
        throw std::runtime_error("Cannot load texture from empty filename");
    }

    if (!_tex.loadFromFile(filename)) {
        std::cout << filename << " failed to load into a texture!\n";
        return;
    }

    _tex.setSmooth(_smooth);

    sf::Vector2f texSize = (sf::Vector2f)_tex.getSize();

    _sprite.setTexture(_tex);
    _sprite.setPosition((sf::Vector2f)_pos);
    
    float scale_x = _size.x / texSize.x;
    float scale_y = _size.y / texSize.y;

    _sprite.setScale(scale_x, scale_y);
}

void UIElement::loadTexture(std::string filename, bool smooth) {
    _smooth = smooth;
    loadTexture(filename);
}

void UIElement::draw(std::weak_ptr<sf::RenderTarget> _win) {
    auto window = _win.lock();
    window->draw(_sprite);
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

UI::UI(std::weak_ptr<sf::RenderTarget> win) : _win(win) {}

std::vector<UIElement> UI::getElements() const {
    return _elements;
}

void UI::draw() const {
    for (auto elem : _elements) {
        elem.draw(_win);
    }
}
