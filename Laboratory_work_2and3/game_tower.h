#ifndef GAME_TOWER_H
#define GAME_TOWER_H

#include "box.h"
#include <vector> // выбранный класс STL для решения поставленной задачи 

class GameTower {
private:
    std::vector<BoxContainer> containers_; // Список контейнеров, составляющих башню

public:
    // Конструктор
    GameTower() {}

    // Метод для добавления контейнера в башню
    void addContainer(const BoxContainer& container) {
        containers_.push_back(container); // добавляет контейнеры 
    }

    // Метод для проверки устойчивости башни
    bool isStable() const {
        if (containers_.empty()) return true; // думаю, что пустая башня устойчива (крайний случай)

        // Проверка устойчивости по контейнерам
        for (size_t i = 1; i < containers_.size(); ++i) {
            const BoxContainer& lowerContainer = containers_[i - 1];
            const BoxContainer& upperContainer = containers_[i];

            // Может ли верхний контейнер стоять на нижнем
            if (!canStandOn(lowerContainer, upperContainer)) {
                return false; // Если не может, башня неустойчива
            }
        }
        return true;
    }

private:
    // Метод для проверки, может ли верхний контейнер стоять на нижнем
    bool canStandOn(const BoxContainer& lower, const BoxContainer& upper) const {
        // например, проверка, что центр масс верхнего контейнера
        // находится в пределах нижнего контейнера.
        // Для упрощения, предположу, что ширина и глубина верхнего
        // контейнера должны быть меньше или равны нижнему контейнеру.

        return upper.getWidth() <= lower.getWidth() &&
               upper.getDepth() <= lower.getDepth();
    }
};

#endif // GAME_TOWER_H