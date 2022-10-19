#include "ResourceManager.h"

ResourceManager::ResourceManager() {}

bool ResourceManager::addTexture(std::string filename) {
    std::cout << filename << "\n";
    sf::Texture tex;
    if (!tex.loadFromFile(filename)) {
        return false;
    }

    _textures.emplace(filename, std::make_shared<sf::Texture>(tex));
    return true;
}

bool ResourceManager::addSoundBuffer(std::string filename) {
    std::shared_ptr<sf::SoundBuffer> sndbuf;
    if (!sndbuf->loadFromFile(filename)) {
        return false;
    }

    _sounds.emplace(filename, sndbuf);
    return true;
}

bool ResourceManager::addFont(std::string filename) {
    std::shared_ptr<sf::Font> font;
    if (!font->loadFromFile(filename)) {
        return false;
    }

    _fonts.emplace(filename, font);
    return true;
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(std::string filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::Texture>>(_textures, filename)) {
        if (!addTexture(filename)) {
            std::cout << "Texture failed to load, using placeholder texture!\n";
            addTexture("/home/andrew/Projects/SFML_Game_Engine/cowcar.png");
        }
    }

    return _textures[filename];
}