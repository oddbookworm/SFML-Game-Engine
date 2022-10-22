#pragma once

#ifndef __UI_H__
#   define __UI_H__

#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "utility.h"

/**
 * intended to be subclassed for a specific style of UI Element
 * should be instantiatiable for something generic, but relatively
 * limited in that everything has to be manually crafted
*/
class UIElement {
public:
    UIElement();

    /**
     * Constructs a blank UIElement
     * 
     * @param pos sf::Vector2i describing position of the element
     * 
     * @param size sf::Vector2u describing the size of the element
    */
    UIElement(const sf::Vector2i pos, const sf::Vector2u size);

    /**
     * Constructs a blank UIElement
     * 
     * @param pos sf::Vector2i describing position of the element
     * 
     * @param size sf::Vector2u describing the size of the element
     * 
     * @param tex shared_ptr to a texture to be rendered on the element
    */
    UIElement(const sf::Vector2i pos, const sf::Vector2u size, std::shared_ptr<sf::Texture> tex);

    /**
     * virtual destructor
    */
    virtual ~UIElement();

    /**
     * returns the position of the element
    */
    sf::Vector2i getPos() const;

    /**
     * returns the size of the element
    */
    sf::Vector2u getSize() const;
    
    /**
     * returns a shared pointer to the texture of the element
    */
    std::shared_ptr<sf::Texture> getTex() const;

    /**
     * loads a texture from a file
     * 
     * @param filename the name of the file to be loaded
    */
    void loadTexture(const std::string& filename);

    /**
     * loads a texture from a file and applies smoothing if desired
     * 
     * @param filename the name of the file to be loaded
     * 
     * @param smooth applies smoothing if set to true
    */
    void loadTexture(const std::string& filename, bool smooth);

    /**
     * draws the element onto the _target RenderTexture
    */
    virtual void draw(std::shared_ptr<sf::RenderTexture> _target);

protected:
    // general values
    sf::Vector2i _pos;
    sf::Vector2u _size;
    
    /**
     * internal shared functionality for actually creating the necessary structures
    */
    void loadTexture();
    
    sf::Sprite _sprite; // nts: sprites only reference a texture, they do not store pixel data
    std::shared_ptr<sf::Texture> _tex;
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
    std::shared_ptr<sf::RenderTexture> _surf;
    std::weak_ptr<sf::RenderTarget> _win;

private:

};

#endif // __UI_H__