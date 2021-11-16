#include <iostream>
using namespace std;

template <typename T>
class doublyLinkedList
{
private:
    static doublyLinkedList* head;
    static doublyLinkedList* last;
    T data;
    doublyLinkedList* next;
    doublyLinkedList* prev;

public:
    static void insertAtTail(T);
    static void insertAtHead(T);
    static void insertAtPosition(T, int); // head is at position 1
    static void printForward();
    static void printBackward();
    static void deleteAtPos(int);
    static void deleteAll();
    static int search(T); // returns positions

};

template <class T>
doublyLinkedList<T>* doublyLinkedList<T>::head = nullptr;
template <class T>
doublyLinkedList<T>* doublyLinkedList<T>::last = nullptr;

int main()
{
    doublyLinkedList<char>::insertAtTail('a');
    doublyLinkedList<char>::insertAtTail('b');
    doublyLinkedList<char>::insertAtTail('c');
    doublyLinkedList<char>::insertAtTail('d');
    doublyLinkedList<char>::insertAtTail('e');
    doublyLinkedList<char>::insertAtTail('f');
    doublyLinkedList<char>::insertAtPosition('x', 8);
    doublyLinkedList<char>::insertAtHead('y');

    doublyLinkedList<char>::printForward();
    doublyLinkedList<char>::printBackward();

    cout << "'c' found at position: " << doublyLinkedList<char>::search('c') << endl;

    doublyLinkedList<char>::deleteAll();

    return 0;
}

template <typename T>
int doublyLinkedList<T>::search(T val)
{
    doublyLinkedList* temp = head;

    int i = 0;

    while( temp != nullptr )
    {
        ++i;
        if ( temp->data == val )
            return i;
        temp = temp->next;
    }

    return -1;

}

template <typename T>
void doublyLinkedList<T>::insertAtTail(T val)
{
    if ( head == nullptr )
    {
        insertAtHead(val);
        return;
    }

    last->next = new doublyLinkedList;
    last->next->data = val;
    last->next->next = nullptr;
    last->next->prev = last;
    last = last->next;
}

template <typename T>
void doublyLinkedList<T>::insertAtHead(T val)
{
    if ( head == nullptr )
    {
        head = new doublyLinkedList;
        head->data = val;
        head->next = head->prev = nullptr;
        last = head;
        return;
    }

    head->prev = new doublyLinkedList;
    head->prev->data = val;
    head->prev->next = head;
    head->prev->prev = nullptr;
    head = head->prev;
}

template <typename T>
void doublyLinkedList<T>::insertAtPosition(T val, int pos)
{
    if ( head == nullptr || pos == 1 )
    {
        insertAtHead(val);
        return;
    }

    doublyLinkedList* temp = head;

    for( int i=2; i < pos; ++i )
    {
        if ( temp->next->next != nullptr )
            temp = temp->next;
        else
        {
            insertAtTail(val);
            return;
        }
    }

    temp->next->prev = new doublyLinkedList;
    temp->next->prev->next = temp->next;
    temp->next = temp->next->prev;
    temp->next->prev = temp;
    temp->next->data = val;
}

template <typename T>
void doublyLinkedList<T>::printForward()
{
    cout << "Print Forward: ";

    if ( head == nullptr )
    {
        cout << "Empty list" << endl;
        return;
    }

    doublyLinkedList* temp = head;

    while( temp != nullptr )
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

template <typename T>
void doublyLinkedList<T>::printBackward()
{
    cout << "Print Backward: ";

    if ( head == nullptr )
    {
        cout << "Empty list" << endl;
        return;
    }

    doublyLinkedList* temp = last;

    while( temp != nullptr )
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

template <typename T>
void doublyLinkedList<T>::deleteAll()
{
    if ( head == nullptr )
        return;

    while ( 1 )
    {
        if ( head->next != nullptr )
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        else
        {
            delete head;
            head = nullptr;
            return;
        }
    }
}

template <typename T>
void doublyLinkedList<T>::deleteAtPos(int pos)
{
    if ( head == nullptr )
        return;

    if ( pos == 1 )
    {
        if ( head->next != nullptr )
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        else
        {
            delete head;
            head = nullptr;
        }

        return;
    }

    doublyLinkedList* temp = head;

    for(int i=2; i < pos; ++i )
    {
        if ( temp->next != nullptr )
            temp = temp->next;
        else
            break;
    }

    if ( temp->next->next == nullptr )
    {
        delete temp->next;
        temp->next = nullptr;
        return;
    }

    temp->next = temp->next->next;
    delete temp->next->prev;
    temp->next->prev = temp;

    

}