#include "game_tower.h"
// данная лабораторная работа позволяет реализовать реализацию класса GameTower и описание методов в одном заголовочном файле.
// но НА БУДУЩЕЕ, если этот класс нужно будет расширять, то описание работы методов будет вынесено в отдельный файл (этот) game_tower.cpp
// для удобства, красоты и эстетики.

GameTower::GameTower() {}

void GameTower::addContainer(const BoxContainer& container) {
    containers_.push_back(container); 
}

bool GameTower::isStable() const {
    if (containers_.empty()) return true; 


    for (size_t i = 1; i < containers_.size(); ++i) {
        const BoxContainer& lowerContainer = containers_[i - 1];
        const BoxContainer& upperContainer = containers_[i];

        if (!canStandOn(lowerContainer, upperContainer)) {
            return false; 
        }
    }
    return true; 
}

bool GameTower::canStandOn(const BoxContainer& lower, const BoxContainer& upper) const {

    return upper.getWidth() <= lower.getWidth() &&
           upper.getDepth() <= lower.getDepth();
}