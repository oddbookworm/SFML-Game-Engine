#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iostream>
#include <unordered_map>

#include <SFML/Graphics.hpp>

// for printing SFML vectors
std::ostream& operator<<(std::ostream& s, const sf::Vector2i& v);
std::ostream& operator<<(std::ostream& s, const sf::Vector2u& v);
std::ostream& operator<<(std::ostream& s, const sf::Vector2f& v);

// for checking if std::unordered_map contains key
template <typename K, typename V>
bool keyExists(std::unordered_map<K, V> _map, K key) {
    return !(_map.find(key) == _map.end());
}

#endif // __UTILITY_H__