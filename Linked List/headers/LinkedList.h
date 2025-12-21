#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstring>
using namespace std;

struct Employee
{
    int id;
    char name[50];
    int age;
};

struct Node
{
    Employee data;
    Node* next;
    Node* prev;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();
    
    void Append(int id, const char* name, int age);
    void InsertFirst(int id, const char* name, int age);
    void InsertMiddle(int id, const char* name, int age);
    
    void searchById(int id);
    void SearchByName(const char* name);
    
    void DeleteById(int id);
    void DeleteByName(const char* name);
    void DeleteAll();
    
    void Display();
    int Count();
};

#endif
