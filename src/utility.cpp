#include "utility.h"

std::ostream& operator<<(std::ostream& s, const sf::Vector2i& v) {
    return s << "(" << v.x << ", " << v.y << ")";
}

std::ostream& operator<<(std::ostream& s, const sf::Vector2u& v) {
    return s << "(" << v.x << ", " << v.y << ")";
}

std::ostream& operator<<(std::ostream& s, const sf::Vector2f& v) {
    return s << "(" << v.x << ", " << v.y << ")";
}