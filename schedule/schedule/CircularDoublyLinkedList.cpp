#include "CircularDoublyLinkedList.h"

void CircularDoublyLinkedList::insert(int data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else 
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void CircularDoublyLinkedList::remove(int data)
{
    if (head == nullptr) 
        return;

    Node* curr = head;
    do
    {
        if (curr->data == data)
        {
            if (curr == head && curr->next == head)  // only one node in the list
                head = nullptr;
            else if (curr == head)  // removing the head node
                head = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return;
        curr = curr->next;
    } while (curr != head);
}

void CircularDoublyLinkedList::print()
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = head;
    do 
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}
