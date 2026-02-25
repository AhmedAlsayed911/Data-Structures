#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <utility>
#include <string>

class HashTable
{
private:
    int capacity;
    int size;
    std::list<std::pair<int, std::string>>* table;

    int hashFunction(int key);

public:
    HashTable(int capacity = 10);
    ~HashTable();

    void insert(int key, const std::string& value);
    bool search(int key, std::string& value);
    bool remove(int key);
    void display();
    int getSize();
    double loadFactor();
};

#endif
