#pragma once

#ifndef __UI_H__
#define __UI_H__

#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

// intended to be subclassed for a specific style of UI Element
// should be instantiatiable for something generic, but relatively
// limited in that everything has to be manually crafted
class UIElement {
public:
    // default constructor, doesn't do anything
    UIElement();
    // constructor that defines a position and size, but no image data
    UIElement(const sf::Vector2i pos, const sf::Vector2u size);
    // full constructor
    UIElement(const sf::Vector2i pos, const sf::Vector2u size, sf::Texture& tex);

    // virtual destructor
    virtual ~UIElement();

    // getters
    sf::Vector2i getPos() const;
    sf::Vector2u getSize() const;
    sf::Texture getTex() const;

    // creating texture and sprite
    void loadTexture(std::string filename);
    void loadTexture(std::string filename, bool smooth);

    // drawing
    virtual void draw(std::weak_ptr<sf::RenderTarget> _win);

protected:
    // general values
    sf::Vector2i _pos;
    sf::Vector2u _size;
    
    // texture
    sf::Sprite _sprite; // nts: sprites only reference a texture, they do not store pixel data
    sf::Texture _tex;
    bool _smooth = false;

private:

};

class UI {
public:
    UI(std::weak_ptr<sf::RenderTarget> win);

    void addElement(const UIElement& elem);

    std::vector<UIElement> getElements() const;

    void draw() const;

protected:
    std::vector<UIElement> _elements;
    // * TODO change up slightly how drawing is done by using an intermediate surface
    std::weak_ptr<sf::RenderTarget> _win;

private:

};

#endif // __UI_H__