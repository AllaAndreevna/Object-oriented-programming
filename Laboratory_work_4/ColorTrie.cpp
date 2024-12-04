#include "ColorTrie.h"
#include <fstream>
#include <string>
#include <stdexcept>

template <typename T>
ColorTrie<T>::Node::Node() : isEndOfWord(false) {}

// конструктор по умолчанию
template <typename T>
ColorTrie<T>::ColorTrie() : root(std::make_unique<Node>()), size(0) {}


// конструктор копирования
template <typename T>
ColorTrie<T>::ColorTrie(const ColorTrie& other) : root(std::make_unique<Node>()), size(other.size) {
    for (const auto& key : other.getAllKeys()) {
        insert(key.first, key.second);
    }
}

// деструктор
template <typename T>
ColorTrie<T>::~ColorTrie() {
    clear(root.get());
}

// рекурсивное удаление всех узлов дерева, 
// а затем создаю новый корень и сбрасываю размер
template <typename T>
void ColorTrie<T>::clear(Node* node) {
    if (!node) return;
    for (auto& pair : node->children) {
        clear(pair.second.get());
    }
}

// метод, удаляющий все хранящиеся значения из коллекции
template <typename T>
void ColorTrie<T>::clear() {
    clear(root.get());
    root = std::make_unique<Node>();
    size = 0;
}

// метод, возвращающий количество хранящихся в коллекции значений
template <typename T>
size_t ColorTrie<T>::getSize() const {
    return size;
}

// метод, принимающий путь к файлу и сохраняющий в него содержимое коллекции
template <typename T>
void ColorTrie<T>::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Unable to open file for writing");
    }
    if (root) {
        saveToFile(root.get(), "", outFile); // вызываем перегруженный метод
    }
    outFile.close();
}

template <typename T>
void ColorTrie<T>::saveToFile(Node* node, const std::string& prefix, std::ofstream& outFile) const {
    if (!node) return;

    // если узел является концом слова, сохраняется полное слово
    if (node->isEndOfWord) {
        outFile << prefix << " " << node->value << std::endl; 
    }

    // рекурсивно сохраняем дочерние узлы
    for (const auto& pair : node->children) {
        saveToFile(pair.second.get(), prefix + pair.first, outFile); // Добавляем текущий символ к префиксу
    }
}

// метод, добавляющий в коллекцию заданное значение
template <typename T>
void ColorTrie<T>::insert(const std::string& colors, T symbol) {
    Node* current = root.get();
    for (char c : colors) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = std::make_unique<Node>();
        }
        current = current->children[c].get();
    }
    if (!current->isEndOfWord) {
        current->isEndOfWord = true;
        current->value = symbol;
        size++;
    }
}

// метод, удаляющий из коллекции заданное значение при его наличии
template <typename T>
bool ColorTrie<T>::remove(const std::string& colors) {
    return removeHelper(root.get(), colors, 0);
}
// вспомогательный метод removeHelper
template <typename T>
bool ColorTrie<T>::removeHelper(Node* node, const std::string& colors, size_t depth) {
    if (!node) return false; // проверка на наличие

    if (depth == colors.size()) {
        if (!node->isEndOfWord) return false; // Слово не найдено
        node->isEndOfWord = false; // Удаляем конец слова
        size --; // УМЕНЬШАЕМ РАЗМЕР!!!
        return node->children.empty(); // Возвращаем true, если узел можно удалить
    }

    char c = colors[depth];
    if (removeHelper(node->children[c].get(), colors, depth + 1)) {
        node->children.erase(c);
        return !node->isEndOfWord && node->children.empty();
    }
    return false;
}

// оператор [], принимающий ключ и возвращающий его значение
template <typename T>
T ColorTrie<T>::operator[](const std::string& colors) const {
    Node* current = root.get();
    for (char c : colors) {
        if (current->children.find(c) == current->children.end()) {
            throw std::out_of_range("Key not found");
        }
        current = current->children[c].get();
    }
    if (!current->isEndOfWord) {
        throw std::out_of_range("Key not found");
    }
    return current->value;
}

// реализация метода collectkeys
template <typename T>
void ColorTrie<T>::collectKeys(Node* node, const std::string& prefix, std::vector<std::pair<std::string, T>>& keys) const {
    if (node->isEndOfWord) {
        keys.emplace_back(prefix, node->value); // Добавляем ключ и значение в вектор
    }
    for (const auto& pair : node->children) {
        collectKeys(pair.second.get(), prefix + pair.first, keys); // Рекурсивно собираем ключи
    }
}

// метод, принимающий ключ и возвращающий при его наличии в коллекции истину, 
// а при отсутствии – ложь
template <typename T>
bool ColorTrie<T>::contains(const std::string& colors) const {
    Node* current = root.get();
    for (char c : colors) {
        if (current->children.find(c) == current->children.end()) {
            return false;
        }
        current = current->children[c].get();
    }
    return current->isEndOfWord;
}


template <typename T>
std::vector<std::pair<std::string, T>> ColorTrie<T>::getKeysWithPrefix(const std::string& prefix) const {
    Node* current = root.get();
    for (char c : prefix) {
        if (current->children.find(c) == current->children.end()) {
            return {}; // Пустой вектор, если префикс не найден
        }
        current = current->children[c].get();
    }
    std::vector<std::pair<std::string, T>> keys;
    collectKeys(current, prefix, keys);
    return keys;
}

template <typename T>
std::vector<std::pair<std::string, T>> ColorTrie<T>::getAllKeys() const {
    std::vector<std::pair<std::string, T>> keys;
    collectKeys(root.get(), "", keys);
    return keys;
}

// оператор ==, принимающий другую коллекцию и возвращающий истину, 
// если обе коллекции хранят одинаковые значения и ложь в противном случае

template <typename T>
bool ColorTrie<T>::isEqual(Node* node1, Node* node2) const {
    if (node1 == nullptr && node2 == nullptr) {
        return true; // Оба узла пустые
    }
    if (node1 == nullptr || node2 == nullptr) {
        return false; // Один из узлов пустой, другой нет
    }

    if (node1->isEndOfWord != node2->isEndOfWord) {
        return false; // Разные состояния конца слова
    }
    if (node1->isEndOfWord && node2->isEndOfWord) {
        if (node1->value != node2->value) {
            return false; // Разные значения
        }
    }

    // сравниваем детей
    if (node1->children.size() != node2->children.size()) {
        return false; // разное количество детей
    }

    for (const auto& pair : node1->children) {
        char key = pair.first;
        if (node2->children.find(key) == node2->children.end() || 
            !isEqual(pair.second.get(), node2->children[key].get())) {
            return false; // деревья не равны
        }
    }

    return true; // деревья равны, всё хорошо
}
// само сравнение
template <typename T>
bool ColorTrie<T>::operator==(const ColorTrie& other) const {
    return isEqual(root.get(), other.root.get());
}

// оператор &&, принимающий другую коллекцию и возвращающий 
// все общие значения T в виде новой коллекции
template <typename T>
ColorTrie<T> ColorTrie<T>::operator&&(const ColorTrie& other) const {
    ColorTrie result;
    for (const auto& key : getAllKeys()) {
        if (other.contains(key.first)) {
            result.insert(key.first, key.second); // Используем последний символ как символ
        }
    }
    return result;
}

// template <typename T>
// void ColorTrie<T>::saveToFile(const std::string& filename) const {
//     std::ofstream file(filename);
//     if (file.is_open()) {
//         for (const auto& key : getAllKeys()) {
//             file << key.first << std::endl;
//         }
//         file.close();
//     }
// }

// метод, принимающий путь к файлу и загружающий из него содержимое коллекции
template <typename T>
void ColorTrie<T>::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Unable to open file for reading");
    }
    std::string key;
    T value;
    while (inFile >> key >> value) { // читаем ключ и значение
        insert(key, value); // вставляем в коллекцию
    }
    inFile.close();
}