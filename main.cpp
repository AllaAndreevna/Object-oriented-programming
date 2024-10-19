#include "box.h"
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    system ("chcp 65001"); // кодировка UTF-8

    // Тестирование конструктора по умолчанию GameBox
    GameBox defaultBox;
    assert(defaultBox.getWidth() == 0);
    assert(defaultBox.getHeight() == 0);
    assert(defaultBox.getDepth() == 0);

    // Тестирование конструктора инициализации GameBox
    GameBox initializedBox("Game A", 10, 20, 30);
    assert(initializedBox.getName() == "Game A");
    assert(initializedBox.getWidth() == 10);
    assert(initializedBox.getHeight() == 20);
    assert(initializedBox.getDepth() == 30);

    // Тестирование конструктора копирования GameBox
    GameBox copiedBox(initializedBox);
    assert(copiedBox.getName() == initializedBox.getName());
    assert(copiedBox.getWidth() == initializedBox.getWidth());
    assert(copiedBox.getHeight() == initializedBox.getHeight());
    assert(copiedBox.getDepth() == initializedBox.getDepth());

    // Тестирование метода проверки пересечений коробок
    GameBox box1("Box 1", 10, 20, 30);
    GameBox box2("Box 2", 15, 25, 35); 
    assert(box1.intersects(box2)); // не должны пересекаться

    GameBox box3("Box 3", 5, 15, 25); 
    assert(box1.intersects(box3)); // должны пересекаться

    // Тестирование конструктора по умолчанию BoxContainer
    BoxContainer defaultContainer; // создаем контейнер с конструктором по умолчанию
    assert(defaultContainer.getMaxItems() == 10); // проверяем максимальное количество предметов

    // Тестирование конструктора инициализации BoxContainer
    std::vector<GameBox> boxes = { initializedBox }; // инициализация коробок
    BoxContainer bc2(10, 10, 10, 10); // создаем контейнер с размерами и максимальным количеством
    for (const auto& box : boxes) {
        bc2.addBox(box);
    }
    assert(bc2.getBoxes().size() == boxes.size()); // проверка количества коробок в контейнере

    // Тестирование конструктора копирования BoxContainer
    BoxContainer bc3(bc2);
    assert(bc3.getBoxes().size() == bc2.getBoxes().size()); // проверка количества коробок в контейнере

    // Добавление новой коробки
    GameBox newBox("Game B", 5, 5, 5); // Правильная инициализация
    assert(bc2.addBox(newBox)); // проверка добавления коробки
    assert(bc2.getBoxes().size() == boxes.size() + 1); // проверка увеличения количества коробок

    // Тестирование перегрузки операторов
    GameBox box4("Box 1", 10, 20, 30);
    GameBox box5("Box 1", 10, 20, 30);
    assert(box4 == box5); // должны быть равны

    // Тестирование перегрузки функций
    BoxContainer container(10, 10, 10, 5);
    GameBox box6("Box 3", 10, 20, 30);
    assert(container.addBox(box6)); // добавление должно быть успешным
    assert(container.getBoxes().size() == 1); // должна быть добавлена одна коробка

    // Тестирование межклассового взаимодействия
    GameBox box7("Box 4", 10, 20, 30);
    GameBox box8("Box 5", 10, 20, 30);
    assert(container.addBox(box7)); // добавление должно быть успешным
    assert(container.addBox(box8)); // добавление должно быть успешным
    assert(container.getBoxes().size() == 3); // должны быть добавлены три коробки

    // Проверка на валидность контейнера
    assert(container.isValid()); // контейнер должен быть валидным

    std::cout << "Тесты пройдены успешно." << std::endl;

    return 0;
}
