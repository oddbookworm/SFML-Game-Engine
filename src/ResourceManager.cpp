#include "ResourceManager.h"

ResourceManager::ResourceManager() {}

bool ResourceManager::addTexture(const std::string& filename) {
    auto tex = std::make_shared<sf::Texture>();
    if (!tex->loadFromFile(filename)) {
        return false;
    }

    _textures.emplace(filename, tex);
    return true;
}

bool ResourceManager::addSoundBuffer(const std::string& filename) {
    auto sndbuf = std::make_shared<sf::SoundBuffer>();
    if (!sndbuf->loadFromFile(filename)) {
        return false;
    }

    _sounds.emplace(filename, sndbuf);
    return true;
}

bool ResourceManager::addFont(const std::string& filename) {
    auto font = std::make_shared<sf::Font>();
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

std::shared_ptr<sf::SoundBuffer> ResourceManager::getSoundBuffer(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::SoundBuffer>>(_sounds, filename)) {
        if (!addSoundBuffer(filename)) {
            std::cout << "Sound failed to load, using placeholder sound!\n";
            addSoundBuffer("assets/sounds/sound.wav");
            return _sounds["assets/sounds/sound.wav"];
        }
    }

    return _sounds[filename];
}

std::shared_ptr<sf::Font> ResourceManager::getFont(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::Font>>(_fonts, filename)) {
        if (!addFont(filename)) {
            std::cout << "Font failed to load, using placeholder font!\n";
            addFont("assets/fonts/FuzzyBubbles-Bold.ttf");
            return _fonts["assets/fonts/FuzzyBubbles-Bold.ttf"];
        }
    }

    return _fonts[filename];
}

void ResourceManager::delTexture(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::Texture>>(_textures, filename)) {
        std::cout << "Cannot delete texture that does not exist!\n";
        return;
    }
    
    _textures.erase(filename);
}

void ResourceManager::delSoundBuffer(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::SoundBuffer>>(_sounds, filename)) {
        std::cout << "Cannot delete sound that does not exist!\n";
        return;
    }
    
    _sounds.erase(filename);
}

void ResourceManager::delFont(const std::string& filename) {
    if (!keyExists<std::string, std::shared_ptr<sf::Font>>(_fonts, filename)) {
        std::cout << "Cannot delete font that does not exist!\n";
        return;
    }
    
    _fonts.erase(filename);
}