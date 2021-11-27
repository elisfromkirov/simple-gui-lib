#include "Core/Platform/Color.hpp"
#include "Core/Platform/Rectangle.hpp"

Rectangle::Rectangle(const Rect2& rect)
    : rectangle_{sf::Vector2f{rect.size.x, rect.size.y}} {
    rectangle_.setPosition(sf::Vector2f{rect.position.x, rect.position.y});
}

Rectangle::~Rectangle() {}

void Rectangle::SetFillColor(const Color& color) {
    rectangle_.setFillColor(NativeColorFromColor(color));
}

void Rectangle::SetPosition(const Vector2i& position) {
    rectangle_.setPosition(sf::Vector2f{position.x, position.y});
}

void Rectangle::SetRotation(int32_t degrees) {
    rectangle_.setRotation(degrees);
}

void Rectangle::SetSize(const Vector2u& size) {
    rectangle_.setSize(sf::Vector2f{size.x, size.y});
}

Vector2u Rectangle::GetSize() const {
    sf::Vector2f size{rectangle_.getSize()};

    return Vector2u{static_cast<uint32_t>(size.x), static_cast<uint32_t>(size.y)};
}

const NativeRectangle& Rectangle::GetNativeRectangle() const {
    return rectangle_;
}