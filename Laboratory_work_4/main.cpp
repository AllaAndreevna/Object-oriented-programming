#include "ColorTrie.h"
#include <cassert>
#include <iostream>
#include <vector>


int main() {
    system ("chcp 65001"); // кодировка UTF-8

  
    //инициализация
    ColorTrie<char> trie;

    // тестирование конструктора копирования
    ColorTrie<char> newTrie(trie);

    // проверка размера коллекции
    assert(trie.getSize() == 0);

    // добавление значений
    trie.insert("red", 'R');
    assert(trie.getSize() == 1);
    trie.insert("green", 'G');
    assert(trie.getSize() == 2);
    trie.insert("red", 'R'); // Дубликат
    assert(trie.getSize() == 2); // размер остаётся прежним

    // trie.insert("blue", "B");  
    // проверка наличия значений
    assert(trie.contains("red") == true);
    assert(trie.contains("blue") == false);

    // удаление значений
    trie.remove("red");
    assert(trie.getSize() == 1);
    assert(trie.contains("red") == false);

    // сохранение и загрузка из файла
    trie.saveToFile("trie_data.txt");
    ColorTrie<char> loadedTrie;
    loadedTrie.loadFromFile("trie_data.txt");
    assert(loadedTrie.getSize() == 1);
    assert(loadedTrie.contains("green") == true);
    assert(trie == loadedTrie);

    // оператор сравнения
    ColorTrie<char> anotherTrie;
    anotherTrie.insert("green", 'G');
    assert(loadedTrie == anotherTrie);

    // оператор пересечения с пустой коллекцией
    ColorTrie<char> AnotherNewTrie;
    ColorTrie<char> intersection = trie && AnotherNewTrie;
    assert(intersection.getSize() == 0);
    assert(intersection.contains("green") == false);

    // оператор пересечения с непустой коллекцией
    ColorTrie<char> intersection1 = trie && loadedTrie;
    assert(intersection1.getSize() == 1);
    assert(intersection1.contains("green") == true); // возвращенная коллекция 
                                                     // равна одной из исходных коллекций

    // очистка коллекции
    trie.clear();
    ColorTrie<char> OneMoreTrie;
    assert(trie.getSize() == OneMoreTrie.getSize());

    // копирование, сравнение и сравнение коллекции
    ColorTrie<char> originalTrie;
    originalTrie.insert("red", 'R');
    originalTrie.insert("green", 'G');

    ColorTrie<char> copiedTrie(originalTrie);

    assert(originalTrie == copiedTrie);

    // вставляем новый элемент в оригинал
    originalTrie.insert("blue", 'B');

    assert(!(originalTrie == copiedTrie));

    // Тестирование функции автодополнения
    ColorTrie<char> trie_auto;
    trie_auto.insert("red", 'R');
    trie_auto.insert("red-blue", 'R');
    trie_auto.printAutocomplete("re");


    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}

// структура класса