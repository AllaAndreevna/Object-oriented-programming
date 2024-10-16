#ifndef BOX_H // директива препроцессора C++, 
                // которая используется для защиты от 
                // повторного включения заголовочного 
                // файла (robot.h) в программу.
#define BOX_H

#include <string>
#include <vector> 

class GameBox {
private:
    std::string name_; // название игры
    int width_; // ширина коробки
    int height_; // высота коробки
    int depth_; // глубина коробки

public:
    // Конструктор по умолчанию
    GameBox() : name_(""), width_(0), height_(0), depth_(0) {}

    // Конструктор инициализации
    GameBox(const std::string& name, int width, int height, int depth)
        : name_(name), width_(width), height_(height), depth_(depth) {}

    // Конструктор копирования
    GameBox(const GameBox& other)
        : name_(other.name_), width_(other.width_), height_(other.height_), depth_(other.depth_) {}

    // Методы доступа
    std::string getName() const { return name_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    int getDepth() const { return depth_; }

    // Перегрузка оператора ==
    bool operator==(const GameBox& other) const {
        return name_ == other.name_ &&
               width_ == other.width_ &&
               height_ == other.height_ &&
               depth_ == other.depth_;
    }

    // Метод для проверки пересечения с другой коробкой
    bool intersects(const GameBox& other) const {
        // Реализовать логику проверки пересечения
        return (width_ > other.width_ && height_ > other.height_ && depth_ > other.depth_) ||
               (width_ < other.width_ && height_ < other.height_ && depth_ < other.depth_);
    }
};


class BoxContainer {
private:
    std::vector<GameBox> boxes_; 
    int maxItems_; // вместимость контейнера

public:
    // конструктор по умолчанию
    BoxContainer() : maxItems_(10) {}

    // конструктор инициализации
    BoxContainer(const std::vector<GameBox>& boxes) : boxes_(boxes), maxItems_(10) {}

    // конструктор копирования
    BoxContainer(const BoxContainer& other) : boxes_(other.boxes_), maxItems_(other.maxItems_) {}

    // методы доступа
    int getMaxItems() const { return maxItems_; }
    void setMaxItems(int maxItems) { maxItems_ = maxItems; }
    std::vector<GameBox> getBoxes() const { return boxes_; }
    void addBox(const GameBox& box) { boxes_.push_back(box); }

    // проверка пересечений
    bool isValid() const { return boxes_.size() <= maxItems_; }
};

#endif 


