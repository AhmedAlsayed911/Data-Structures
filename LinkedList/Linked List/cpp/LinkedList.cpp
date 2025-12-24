#include "../headers/LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList()
{
    DeleteAll();
}

void LinkedList::Append(int id, const char* name, int age)
{
    Node* newNode = new Node();
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->data.age = age;

    newNode->next = NULL;

    if (!head)
    {
        newNode->prev = NULL;
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LinkedList::InsertFirst(int id, const char* name, int age)
{
    Node* newNode = new Node();
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->data.age = age;

    newNode->prev = NULL;
    newNode->next = head;

    if (head)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void LinkedList::InsertMiddle(int id, const char* name, int age)
{
    if (head == NULL || head->next == NULL)
    {
        Append(id, name, age);
        return;
    }

    Node* one = head;
    Node* two = head;

    while (one->next && two->next->next)
    {
        one = one->next;
        two = two->next->next;
    }

    Node* newNode = new Node();
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->data.age = age;

    newNode->next = one->next;
    newNode->prev = one;

    one->next->prev = newNode;
    one->next = newNode;
}

void LinkedList::searchById(int id)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data.id == id)
        {
            cout << "Found -> ID: " << temp->data.id
                 << ", Name: " << temp->data.name
                 << ", Age: " << temp->data.age << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void LinkedList::SearchByName(const char* name)
{
    Node* temp = head;
    while (temp)
    {
        if (strcmp(temp->data.name, name) == 0)
        {
            cout << "Found -> ID: " << temp->data.id
                 << ", Name: " << temp->data.name
                 << ", Age: " << temp->data.age << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Employee with name " << name << " not found.\n";
}

void LinkedList::DeleteById(int id)
{
    Node* temp = head;
    while (temp && temp->data.id != id)
        temp = temp->next;

    if (temp == NULL)
        return;
    
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
}

void LinkedList::DeleteByName(const char* name)
{
    Node* temp = head;

    while (temp && strcmp(temp->data.name, name) != 0)
        temp = temp->next;

    if (!temp)
        return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
}

void LinkedList::DeleteAll()
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

void LinkedList::Display()
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp)
    {
        cout << "ID: " << temp->data.id
             << ", Name: " << temp->data.name
             << ", Age: " << temp->data.age << endl;
        temp = temp->next;
    }
}

int LinkedList::Count()
{
    int count = 0;
    Node* temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
