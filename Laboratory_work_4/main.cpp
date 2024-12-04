#include <cassert>
#include <iostream>
#include <vector>
#include "ColorTrie.h"

int main() {
    system ("chcp 65001"); // кодировка UTF-8

    //инициализация
    ColorTrie<char> trie;

    // тестирование конструктора копирования
    ColorTrie<char> newTrie(trie);

    // Тест 1: проверка размера коллекции
    assert(trie.getSize() == 0);

    // Тест 2: добавление значений
    trie.insert("red", 'R');
    assert(trie.getSize() == 1);
    trie.insert("green", 'G');
    assert(trie.getSize() == 2);
    trie.insert("red", 'R'); // Дубликат
    assert(trie.getSize() == 2); // размер остаётся прежним

    // Тест 3: проверка наличия значений
    assert(trie.contains("red") == true);
    assert(trie.contains("blue") == false);

    // Тест 4: удаление значений
    trie.remove("red");
    assert(trie.getSize() == 1);
    assert(trie.contains("red") == false);

    // Тест 5: сохранение и загрузка из файла
    trie.saveToFile("trie_data.txt");
    ColorTrie<char> loadedTrie;
    loadedTrie.loadFromFile("trie_data.txt");
    assert(loadedTrie.getSize() == 1);
    assert(loadedTrie.contains("green") == true);
    assert(trie == loadedTrie);

    // Тест 6: оператор сравнения
    ColorTrie<char> anotherTrie;
    anotherTrie.insert("green", 'G');
    assert(loadedTrie == anotherTrie);

    // Тест 7: оператор пересечения с пустой коллекцией
    ColorTrie<char> AnotherNewTrie;
    ColorTrie<char> intersection = trie && AnotherNewTrie;
    assert(intersection.getSize() == 0);
    assert(intersection.contains("green") == false);

    // Тест 8: оператор пересечения с непустой коллекцией
    ColorTrie<char> intersection1 = trie && loadedTrie;
    assert(intersection1.getSize() == 1);
    assert(intersection1.contains("green") == true); // возвращенная коллекция 
                                                     // равна одной из исходных коллекций

    // Тест 9: очистка коллекции
    trie.clear();
    ColorTrie<char> OneMoreTrie;
    assert(trie.getSize() == OneMoreTrie.getSize());

    // Тест 10: копирование, сравнение и сравнение коллекции
    ColorTrie<char> originalTrie;
    originalTrie.insert("red", 'R');
    originalTrie.insert("green", 'G');

    ColorTrie<char> copiedTrie(originalTrie);

    assert(originalTrie == copiedTrie);

    // вставляем новый элемент в оригинал
    originalTrie.insert("blue", 'B');

    assert(!(originalTrie == copiedTrie));

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}