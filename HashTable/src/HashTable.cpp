#include "../include/HashTable.h"
#include <iostream>

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    table = new std::list<std::pair<int, std::string>>[capacity];
}

HashTable::~HashTable()
{
    delete[] table;
}

int HashTable::hashFunction(int key)
{
    return key % capacity;
}

void HashTable::insert(int key, const std::string& value)
{
    int index = hashFunction(key);
    for (auto& pair : table[index])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    table[index].push_back({key, value});
    size++;
}

bool HashTable::search(int key, std::string& value)
{
    int index = hashFunction(key);
    for (auto& pair : table[index])
    {
        if (pair.first == key)
        {
            value = pair.second;
            return true;
        }
    }
    return false;
}

bool HashTable::remove(int key)
{
    int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it)
    {
        if (it->first == key)
        {
            table[index].erase(it);
            size--;
            return true;
        }
    }
    return false;
}

void HashTable::display()
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "[" << i << "] ";
        for (auto& pair : table[i])
            std::cout << "(" << pair.first << ", " << pair.second << ") -> ";
        std::cout << "NULL" << std::endl;
    }
}

int HashTable::getSize()
{
    return size;
}

double HashTable::loadFactor()
{
    return (double)size / capacity;
}
