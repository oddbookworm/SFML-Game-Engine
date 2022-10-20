#pragma once

#ifndef __RESOURCEMANAGER_H__
#   define __RESOURCEMANAGER_H__

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "utility.h"

class ResourceManager {
public:
    ResourceManager();

    std::shared_ptr<sf::Texture> getTexture(const std::string& filename);
    sf::SoundBuffer getSoundBuffer(const std::string& filename);
    sf::Font getFont(const std::string& filename);

private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> _textures;
    std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> _sounds;
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> _fonts;

    bool addTexture(const std::string& filename);
    bool addSoundBuffer(const std::string& filename);
    bool addFont(const std::string& filename);
};

#endif // __RESOURCEMANAGER_H__