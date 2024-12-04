﻿# Объектно-ориентированное программирование C++

## Вариант 13 для л/р 1-3

За отсутствием слоновой кости, преподаватели кафедры философии решили построить башню из игр в игровой комнате.
Помимо игр у них есть ящики, в которые можно складывать игры. Помогите преподавателям использовать новые информационные технологии, чтобы рассчитать устойчивость башни. Коробка падает, если ее центр масс не лежит на другой коробке. Коробки кладутся рядом с другими коробками или сверху. Коробка не должна падать, в противном случае ее нельзя поместить в коробку.

13.1) Прямоугольная коробка с игрой: название, размеры, метод проверки пересечения с другой коробкой.

13.2) Ящик с играми: набор коробок с играми внутри ящика и их расположение, проверка возможности разместить в ящике еще одну коробку.
Коробки в ящике не должны падать, коробки должны помещаться по габаритам, для всех ящиков задано максимальное количество предметов.

13.3) Башня из игр: список ящиков, коробок и их расположения, метод проверки устойчивости башни.

## Л/Р 1 - Разработка класса

Требования к сдаваемым работам


Структура класса - 40%

Класс содержит перечисленные пункты:

конструктор по умолчанию
конструктор инициализации
конструктор копирования
поля класса, требуемые по условию задачи
методы доступа (селекторы и модификаторы) для скрытых (private) полей класса где это необходимо
Если в классе окажутся открытые (public) поля, это должно быть обосновано

Класс не допускает хранение ошибочных значений

Тестирование - 10%

Тесты отвечают следующим требованиям:

все тесты вызываются из функции main()
для тестирования используется функция assert() из библиотеки assert.h
при отсутствии ошибок выводится сообщение об успешном прохождении тестов
Перечисленные функции успешно проходят тестирование

конструктор по умолчанию
конструктор инициализации
конструктор копирования
методы доступа полей класса
Оформление кода - 30%

Код программы выдержан в одном стиле, на протяжении всего кода программы, выбранные пользователем имена переменных придерживаются одного и того же стиля написания (например, UpperCamelCase для классов, lowerCamelCase для полей и методов, SCREAMING_SNAKE_CASE для констант). Имена переменных осмысленны, имена классов, методов и полей отражают их конкретную роль в программе

(исключение: переменные в циклах, временные переменные)

Длины строк не превышают 80 символов (исключение: строки с комментариями)

Эффективность кода - 20%

Методы, не изменяющие поля класса, объявлены как константные (подсказка: методы, возвращающие значения полей)

Ненужное копирование избегается передачей значений по ссылке (исключение: базовые типы данных (int, double, char, bool и т.п.))



## Л/Р 2 - Наследование

Требования к сдаваемым работам


Структура классов - 40%

Выполнены требования к структуре класса из л/р 1.

Правильно выполнено наследование - все общие для классов методы и поля правильно размещены в родительском классе, а уникальные – только в классах-наследниках.

В иерархии классов присутствует метод идентификации, метод является виртуальным, перегруженным в каждом наследнике и возвращающим различные значения в зависимости от класса.

Тестирование - 20%

Выполнены требования к тестированию из л/р 1.

Тестируются перегруженные функции, межклассовое взаимодействие.

Оформление кода - 20%

Выполнены требования к оформлению кода из л/р 1.

Эффективность кода - 20%

Выполнены требования к эффективности кода из л/р 1.


## Л/Р 3 - Использование хранилищ STL

Требования к сдаваемым работам


Структура классов - 40%

Выполнены требования к структуре класса из л/р 2.

Корректно выбраны классы STL для решения поставленной задачи.

Создан класс, выполняющий поставленную задачу. Реализация обращения к внутреннему хранилищу является корректной и обоснованной.

Тестирование - 20%

Выполнены требования к тестированию из л/р 2.

Тестируется корректность выполнения методов в зависимости от типа объекта.

Корректность выполняемых операций в соответствии с заданием.

Оформление кода - 20%

Выполнены требования к оформлению кода из л/р 2.

Эффективность кода - 20%

Выполнены требования к эффективности кода из л/р 2.

## Вариант 13 для л/р 4 
Студенты с кафедры электротехники обнаружили, что свет от новых ламп кафедры виден из их общежития, располагающегося в нескольких километрах. Они решили попробовать передавать закодированные сообщения, последовательно включая и выключая лампы, находящиеся на кафедре. Теперь студентам, следящим из общежития, нужна программа, позволяющая записывать последовательность цветов и соответствующие им символы.
Коллекция: префиксное дерево <последовательность цветов, буква> с методом, возвращающим список хранящихся ключей, начинающихся с заданной последовательности.

