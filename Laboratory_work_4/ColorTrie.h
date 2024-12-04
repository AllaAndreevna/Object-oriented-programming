#ifndef COLOR_TRIE_H
#define COLOR_TRIE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <cassert>
#include <fstream>
#include <stdexcept>

template <typename T>
class ColorTrie {
private:
    struct Node {
        std::unordered_map<char, std::unique_ptr<Node>> children;
        bool isEndOfWord;
        T value;

        Node(); // конструктор
    };

    std::unique_ptr<Node> root;
    size_t size;

    void clear(Node* node);
    void collectKeys(Node* node, const std::string& prefix, std::vector<std::pair<std::string, T>>& keys) const;
    bool removeHelper(Node* node, const std::string& colors, size_t depth);
    bool isEqual(Node* node1, Node* node2) const;
    void saveToFile(Node* node, const std::string& prefix, std::ofstream& outFile) const; 

public:
    ColorTrie();
    ColorTrie(const ColorTrie& other);
    ~ColorTrie();

    void clear();
    size_t getSize() const;
    void insert(const std::string& colors, T symbol);
    bool remove(const std::string& colors);
    bool contains(const std::string& colors) const;
    std::vector<std::pair<std::string, T>> getKeysWithPrefix(const std::string& prefix) const;
    std::vector<std::pair<std::string, T>> getAllKeys() const;
    bool operator==(const ColorTrie& other) const;
    ColorTrie operator&&(const ColorTrie& other) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    T operator[](const std::string& colors) const; 
};

#include "ColorTrie.cpp" // подключение реализации

#endif 