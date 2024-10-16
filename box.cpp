// реализация методов, объявленных в заголовочном файле .h
class GameBox {
private:
    std::string name_; 
    int width_; 
    int height_; 
    int depth_; 

public:

    GameBox(const std::string& name, int width, int height, int depth)
        : name_(name), width_(width), height_(height), depth_(depth) {}

    // Методы доступа
    std::string getName() const { return name_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    int getDepth() const { return depth_; }

    // Метод проверки пересечения с другими коробками
    bool intersects(const GameBox& other) const {
        // for sкоробки пересекаются, если они "накладываются" друг на друга в любом измерении (width, height, depth)
        return (width_ > other.width_ && height_ > other.height_ && depth_ > other.depth_) ||
               (width_ < other.width_ && height_ < other.height_ && depth_ < other.depth_);
    }
};


class BoxContainer {
private:
    std::vector<GameBox> boxes_; 
    int maxItems_; 
    int width_;
    int height_; 
    int depth_; 

public:

    BoxContainer(int width, int height, int depth, int maxItems)
        : width_(width), height_(height), depth_(depth), maxItems_(maxItems) {}

    // Методы доступа
    int getMaxItems() const { return maxItems_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    int getDepth() const { return depth_; }
    std::vector<GameBox> getBoxes() const { return boxes_; }

    // Метод добавления коробки в контейнер
    bool addBox(const GameBox& box) {
        if (boxes_.size() >= maxItems_) {
            return false; // container is full
        }

        // проверка: можем ли поместить коробку
        if (box.getWidth() > width_ || box.getHeight() > height_ || box.getDepth() > depth_) {
            return false; // box does not fit
        }

        // проверка на пересечения с другими коробками
        for (const auto& existingBox : boxes_) {
            if (box.intersects(existingBox)) {
                return false; // коробка пересекается 
            }
        }

        boxes_.push_back(box);
        return true; // коробка добавлена
    }

};