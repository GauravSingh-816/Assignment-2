#include "single.h"

// Constructor
SingleLinkedList::SingleLinkedList() {
    head = nullptr;
    tail = nullptr;
    numItems = 0;
}

// Overloaded constructor
SingleLinkedList::SingleLinkedList(Item_Type item) {
    Node* tempPtr = new Node;
    tempPtr->item = item;
    tempPtr->next = nullptr;
    head = tempPtr;
    tail = tempPtr;
    numItems = 1;
}

void SingleLinkedList::printSingleLinkedList() {
    Node* tempPtr = new Node;
    tempPtr = head;
    while (tempPtr != nullptr) {
        cout << " " << tempPtr->item.size;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
// Push item to the very front of the list
void SingleLinkedList::push_front(Item_Type item)
{
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = head;
    numItems++;
    head = newNode;
}

// Push item to the very end of the list
void SingleLinkedList::push_back(Item_Type item)
{
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;
    numItems++;
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* tempPtr = head;
        while (tempPtr != nullptr && tempPtr->next != nullptr) {
            tempPtr = tempPtr->next;
        }
        newNode->next = nullptr;
        tempPtr->next = newNode;
        tail = newNode;
    }
}
// Remove the first item in the list
void SingleLinkedList::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    else {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
        numItems--;
    }
}
// Remove the last item in the list
void SingleLinkedList::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    else {
        Node* tempPtr = head;
        Node* previousPtr = nullptr;
        while (tempPtr->next != nullptr) {
            previousPtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        delete tempPtr;
        previousPtr->next = nullptr;
        tail = previousPtr;
        numItems--;
    }
}

//Return true if empty, false otherwise
bool SingleLinkedList::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else return false;
}
// Inserts item at a specific index
void SingleLinkedList::insert(size_t index, const Item_Type& item)
{
    if (index < 0)
    {
        cout << "Index should be a positive number" << endl;
        return;
    }
    else if (index >= numItems)
    {
        push_back(item);
    }
    else
    {
        Node* newNode = new Node;
        newNode->item = item;

        Node* tempPtr = head;

        Node* previousPtr = nullptr;

        for (size_t i = 0; i < index; i++)
        {
            previousPtr = tempPtr;

            tempPtr = tempPtr->next;
        }
        previousPtr->next = newNode;
        newNode->next = tempPtr;
        numItems++;
    }
}

// Returns true if the item is removed. false otherwise
bool SingleLinkedList::remove(size_t index)
{
    if (index < 0 || index > numItems)
    {
        cout << "Index is out of range" << endl;
        return false;
    }
    else if (index == 0) {
        pop_front();
        return true;
    }
    else {
        Node* tempPtr = head;
        Node* previousPtr = nullptr;
        tempPtr = head;
        for (size_t i = 0; i < index; i++)
        {
            previousPtr = tempPtr;
            tempPtr = tempPtr->next;
            if (i == index - 1)
            {
                previousPtr->next = tempPtr->next;
                delete tempPtr;
            }
        }
        numItems--;
        return true;
    }
}

// Return index of found item. if not found, returns the size
size_t SingleLinkedList::find(const Item_Type& item)
{
    Node* tempPtr = head;
    size_t index = 0;
    while (!isEmpty()) {
        if (tempPtr->item.size == item.size)
        {
            return index;
        }
        else {
            index++;
            tempPtr = tempPtr->next;
        }
    }
    return numItems;
}