#include "robot.h"
#include <iostream>
#include <cassert>

// реализация методов класса и их описание

// Конструктор по умолчанию
RobotForPoliv::RobotForPoliv() : id_(0), capacity_(0), waterInCapacity_(0) {}

// Конструктор инициализации
RobotForPoliv::RobotForPoliv(int id, double capacity) :
                            id_(id), 
                            capacity_(capacity), 
                            waterInCapacity_(0) {}

// Конструктор копирования
RobotForPoliv::RobotForPoliv(const RobotForPoliv& other) : 
                            id_(other.id_),
                            capacity_(other.capacity_), 
                            waterInCapacity_(other.waterInCapacity_) {}

// Метод набора воды
void RobotForPoliv::takeWater(double water) {
    if (water > 0 && water <= capacity_) {
        waterInCapacity_ += water;
    } else {
        std::cerr << "Невозможно набрать воду. Объем воды должен быть больше 0 и не превышать объем ёмкости." << std::endl;
    }
}

// Метод полива
void RobotForPoliv::poliv(double water) {
    if (water > 0 && water <= waterInCapacity_) {
        waterInCapacity_ -= water;
    } else {
        std::cerr << "Невозможно полить дерево. Объем воды должен быть больше 0 и не превышать количество воды в ёмкости." << std::endl;
    }
}

// Методы доступа
int RobotForPoliv::getId() const { return id_; }
double RobotForPoliv::getCapacity() const { return capacity_; }
double RobotForPoliv::getWaterInCapacity() const { return waterInCapacity_; }



// Тестирование классов, импортирование нужных файлов
int main() {
    system("chcp 65001"); // кодировка UTF-8

    // Тестирование конструктора по умолчанию
    RobotForPoliv defaultRobot;
    assert(defaultRobot.getId() == 0 && "ID в конструкторе по умолчанию нет");
    assert(defaultRobot.getCapacity() == 0 && "в конструкторе по умолчанию нет вместимости");
    assert(defaultRobot.getWaterInCapacity() == 0 && "в конструкторе по умолчанию нет воды");

    // Тестирование конструктора инициализации
    RobotForPoliv robot(1, 2.0);
    assert(robot.getId() == 1 && "нет ID");
    assert(robot.getCapacity() == 2.0 && "нет вместимости");
    assert(robot.getWaterInCapacity() == 0 && "нет воды");

    // Тестирование конструктора копирования
    RobotForPoliv copiedRobot(robot);
    assert(copiedRobot.getId() == 1 && "скопированный ID неверен");
    assert(copiedRobot.getCapacity() == 2.0 && "скопированная вместимость неверна");
    assert(copiedRobot.getWaterInCapacity() == 0 && "скопированный объем воды неверен");

    // Тестирование методов доступа
    assert(robot.getId() == 1 && "getId() возвращает неверное значение");
    assert(robot.getCapacity() == 2.0 && "getCapacity() возвращает неверное значение");
    assert(robot.getWaterInCapacity() == 0 && "getWaterInCapacity() возвращает неверное значение");

    // Тестирование метода набора воды
    robot.takeWater(1.5);
    assert(robot.getWaterInCapacity() == 1.5 && "takewater() не работает");

    // Тестирование метода полива
    robot.poliv(0.5);
    assert(robot.getWaterInCapacity() == 1.0 && "poliv() не работает");

    std::cout << "Тесты пройдены успешно." << std::endl;

    return 0;
}