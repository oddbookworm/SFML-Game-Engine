#include <iostream>

#include <SFML/Graphics.hpp>

// for printing SFML vectors
std::ostream& operator<<(std::ostream& s, const sf::Vector2i& v);
std::ostream& operator<<(std::ostream& s, const sf::Vector2u& v);
std::ostream& operator<<(std::ostream& s, const sf::Vector2f& v);