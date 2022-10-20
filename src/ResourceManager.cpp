#include "ResourceManager.h"

ResourceManager::ResourceManager() {}

bool ResourceManager::addTexture(const std::string& filename) {
    auto tex = std::make_shared<sf::Texture>();
    if (!tex->loadFromFile(filename)) {
        return false;
    }

    std::cout << filename << "\n";
    _textures.emplace(filename, tex);
    return true;
}

bool ResourceManager::addSoundBuffer(const std::string& filename) {
    std::shared_ptr<sf::SoundBuffer> sndbuf;
    if (!sndbuf->loadFromFile(filename)) {
        return false;
    }

    _sounds.emplace(filename, sndbuf);
    return true;
}

bool ResourceManager::addFont(const std::string& filename) {
    std::shared_ptr<sf::Font> font;
    if (!font->loadFromFile(filename)) {
        return false;
    }

    _fonts.emplace(filename, font);
    return true;
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::Texture>>(_textures, filename)) {
        if (!addTexture(filename)) {
            std::cout << "Texture failed to load, using placeholder texture!\n";
            addTexture("assets/images/missing_texture.png");
            return _textures["assets/images/missing_texture.png"];
        }
    }

    return _textures[filename];
}