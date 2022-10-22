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

/**
 * Utility class for managing textures, soundbuffers, and fonts. Stores unordered_maps
 * of filenames associated with shared_ptr's of the corresponding SFML object
*/
class ResourceManager {
public:
    ResourceManager();

    /**
     * Returns a shared pointer to a texture loaded from a file.
     * If the texture has not already been loaded, it loads it and returns
     * a shared pointer. If the texture cannot be loaded, it will load a
     * placeholder texture
     * 
     * @param filename The name of the file to be loaded or that has already been loaded
     * @return shared pointer to a texture
    */
    std::shared_ptr<sf::Texture> getTexture(const std::string& filename);

    /**
     * Returns a shared pointer to a soundbuffer loaded from a file.
     * If the soundbuffer has not already been loaded, it loads it and returns
     * a shared pointer. If the soundbuffer cannot be loaded, it will load a
     * placeholder sound
     * 
     * @param filename The name of the file to be loaded or that has already been loaded
     * @return shared pointer to a soundbuffer
    */
    std::shared_ptr<sf::SoundBuffer> getSoundBuffer(const std::string& filename);

    /**
     * Returns a shared pointer to a font loaded from a file.
     * If the font has not already been loaded, it loads it and returns
     * a shared pointer. If the font cannot be loaded, it will load a
     * placeholder font
     * 
     * @param filename The name of the file to be loaded or that has already been loaded
     * @return shared pointer to a font
    */
    std::shared_ptr<sf::Font> getFont(const std::string& filename);

    /**
     * Deletes the shared pointer stored internally to the texture loaded from
     * the given file (if it has already been loaded).
     * Note: this only deletes this object's reference to the shared pointer. But
     * because it is a shared pointer, all references to it must be deleted for the
     * texture to be fully deleted.
     * 
     * @param filename the name of the file whose texture is to be deleted
    */
    void delTexture(const std::string& filename);

    /**
     * Deletes the shared pointer stored internally to the soundbuffer loaded from
     * the given file (if it has already been loaded).
     * Note: this only deletes this object's reference to the shared pointer. But
     * because it is a shared pointer, all references to it must be deleted for the
     * soundbuffer to be fully deleted.
     * 
     * @param filename the name of the file whose soundbuffer is to be deleted
    */
    void delSoundBuffer(const std::string& filename);

    /**
     * Deletes the shared pointer stored internally to the font loaded from
     * the given file (if it has already been loaded).
     * Note: this only deletes this object's reference to the shared pointer. But
     * because it is a shared pointer, all references to it must be deleted for the
     * font to be fully deleted.
     * 
     * @param filename the name of the file whose font is to be deleted
    */
    void delFont(const std::string& filename);

private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> _textures;
    std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> _sounds;
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> _fonts;

    /**
     * Loads and inserts a texture loaded from a file into the _textures map.
     * 
     * @param filename the name of the file to be loaded
     * @return a boolean that indicates if the load was successful
    */
    bool addTexture(const std::string& filename);

    /**
     * Loads and inserts a sound loaded from a file into the _sounds map
     * 
     * @param filename the name of the file to be loaded
     * @return a boolean that indicates if the load was successful
    */
    bool addSoundBuffer(const std::string& filename);

    /**
     * Loads and inserts a font loaded from a file into the _fonts map.
     * 
     * @param filename the name of the file to be loaded
     * @return a boolean that indicates if the load was successful
    */
    bool addFont(const std::string& filename);
};

#endif // __RESOURCEMANAGER_H__