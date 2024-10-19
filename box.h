#ifndef BOX_H  // директива препроцессора C++, 
                // которая используется для защиты от 
                // повторного включения заголовочного 
                // файла (robot.h) в программу.
#define BOX_H

#include <string>
#include <vector>

// Базовый класс Box
class Box {
protected:
    int width_;   // ширина
    int height_;  // высота
    int depth_;   // глубина

public:
    Box(int width, int height, int depth)
        : width_(width), height_(height), depth_(depth) {}

    virtual ~Box() {} // Виртуальный деструктор

    // Виртуальный метод для получения типа
    virtual std::string getType() const = 0;

    // Методы доступа
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    int getDepth() const { return depth_; }
};

// Производный класс GameBox
class GameBox : public Box {
private:
    std::string name_; // название игры

public:
    // Конструктор по умолчанию
    GameBox() : Box(0, 0, 0), name_("") {}

    // Конструктор инициализации
    GameBox(const std::string& name, int width, int height, int depth)
        : Box(width, height, depth), name_(name) {}

    // Метод для получения имени
    std::string getName() const { return name_; }

    // Метод для получения типа
    std::string getType() const override {
        return "GameBox: " + name_;
    }

    // Метод для проверки пересечения с другой коробкой
    bool intersects(const GameBox& other) const {
        return (width_ > other.width_ && height_ > other.height_ && depth_ > other.depth_) ||
               (width_ < other.width_ && height_ < other.height_ && depth_ < other.depth_);
    }

    // Перегрузка оператора ==
    bool operator==(const GameBox& other) const {
        return name_ == other.name_ &&
               width_ == other.width_ &&
               height_ == other.height_ &&
               depth_ == other.depth_;
    }
};

// Производный класс BoxContainer
class BoxContainer : public Box {
private:
    std::vector<GameBox> boxes_; 
    int maxItems_; // вместимость контейнера

public:
    // Конструктор по умолчанию
    BoxContainer() : Box(10, 10, 10), maxItems_(10) {}

    // Конструктор инициализации
    BoxContainer(int width, int height, int depth, int maxItems)
        : Box(width, height, depth), maxItems_(maxItems) {}

    // Метод для получения типа
    std::string getType() const override {
        return "BoxContainer";
    }

    // Методы доступа
    int getMaxItems() const { return maxItems_; }
    void setMaxItems(int maxItems) { maxItems_ = maxItems; }
    std::vector<GameBox> getBoxes() const { return boxes_; }
    
    // Метод добавления коробки
    bool addBox(const GameBox& box) {
        if (boxes_.size() < maxItems_) {
            boxes_.push_back(box);
            return true; // добавление успешное
        }
        return false; // контейнер полон
    }

    // Проверка на валидность
    bool isValid() const { return boxes_.size() <= maxItems_; }
};

#endif // BOX_H
