// реализация методов, объявленных в заголовочном файле .h
#include "box.h"

// Реализация методов класса GameBox

// Конструктор инициализации
GameBox::GameBox(const std::string& name, int width, int height, int depth)
    : Box(width, height, depth), name_(name) {}

// Метод для получения имени
std::string GameBox::getName() const {
    return name_;
}

// Метод для проверки пересечения с другими коробками
bool GameBox::intersects(const GameBox& other) const {
    // Коробки пересекаются, если они "накладываются" друг на друга в любом измерении
    return (width_ > other.width_ && height_ > other.height_ && depth_ > other.depth_) ||
           (width_ < other.width_ && height_ < other.height_ && depth_ < other.depth_);
}

// Реализация методов класса BoxContainer

// Конструктор инициализации
BoxContainer::BoxContainer(int width, int height, int depth, int maxItems)
    : Box(width, height, depth), maxItems_(maxItems) {}

// Метод добавления коробки в контейнер
bool BoxContainer::addBox(const GameBox& box) {
    if (boxes_.size() >= maxItems_) {
        return false; // контейнер полон
    }

    // Проверка: можем ли поместить коробку
    if (box.getWidth() > width_ || box.getHeight() > height_ || box.getDepth() > depth_) {
        return false; // коробка не помещается
    }

    // Проверка на пересечения с другими коробками
    for (const auto& existingBox : boxes_) {
        if (box.intersects(existingBox)) {
            return false; // коробка пересекается
        }
    }

    boxes_.push_back(box);
    return true; // коробка добавлена
}