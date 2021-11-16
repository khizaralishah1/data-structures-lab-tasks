//Khizar Ali Shah
//2020196 (BCS)
//Home Task (Doubly Linked List)

#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int reg;
    student* next, *prev;
    static student *head, *last;
    static void create(student*&); // utility function. private

public:
    static void addAtStart();
    static void addAtEnd();
    static void addAtPosition(); // head is at position 1
    static void showAll();
    static void remove(int=1); // reason = 0 will only find the student. Otherwise remove
    static void removeAll();
};

int mainMenu();
student *student::head = nullptr;
student *student::last = nullptr;

int main()
{
    int runs = 1;
    while ( runs )
        runs = mainMenu();

    return 0;
}

void student::addAtStart()
{
    if ( head != nullptr )
    {
        create(head->prev);
        head->prev->next = head;
        head = head->prev;
        head->prev = nullptr;
    }
    else
    {
        create(head);
        last = head;
    }

}

void student::addAtEnd()
{
    create(last->next);
    last->next->prev = last;
    last = last->next;
    last->next = nullptr;
}

void student::addAtPosition()
{
    int pos;
    cout << "Enter position where you want to add student: ";
    cin >> pos;

    if ( pos < 1)
    {
        cout << "\nInvalid position\n";
        return;
    }
    else if ( pos == 1 )
        addAtStart();

    student* temp = head;

    for(int i=2; i < pos; ++i)
    {
        if ( temp->next->next != nullptr )
            temp = temp->next;
        else
        {
            addAtEnd();
            return;
        }
    }

    create(temp->next->prev);
    temp->next->prev->next = temp->next;
    temp->next = temp->next->prev;
    temp->next->prev = temp;
}

void student::showAll()
{
    if ( head == nullptr )
    {
        cout << "\n\nNo student in the list\n\n";
        return;
    }

    cout << "\n\nShowing All Students: \n";
    
    student* temp = head;

    while ( temp != nullptr )
    {
        cout << temp->name << "\t" << temp->reg << endl;
        temp = temp->next;
    }

    cout << "\n\n";
}

void student::remove(int reason)
{
    int id;
    cout << "Enter ID/Reg of the student you want to remove: ";
    cin >> id;

    if ( id < 0 )
    {
        cout << "\nInvalid ID.\n\n";
        return;
    }

    student* temp = head;

    while ( temp != nullptr )
    {
        if ( temp->reg == id )
        {
            if ( reason == 0 ) // only finding 
                cout << "Found '" << temp->name << "' with the given id/reg\n\n";
            else // for deleting
            {
                if ( temp == head )
                    head = head->next;
                else if ( temp == last )
                {
                    last = last->prev;
                    last->next = nullptr;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;       
            }

            return;
        }

        temp = temp->next;
    }

    cout << "\nNO student with ID/Reg " << id << " exists. \n\n";

}

void student::removeAll()
{
    if( head == nullptr )
        return;

    while ( head->next != nullptr )
    {
        head = head->next;
        delete head->prev;
    }

    delete head;
    head = nullptr;
}

void student::create(student*& ptr)
{
    ptr = new student;
    cout << "\n\nAdding a student:\nName: ";
    cin >> ptr->name;
    cout << "Reg number: ";
    cin >> ptr->reg;
}

int mainMenu()
{
    cout << "\n\n0. Exit Program\n1. Add a student at start of list\n2. Add a student at the end of list\n3. Add a student between the nodes\n4. Show all students\n5. Find a student\n6. Remove a student\n7. Remove all students\n\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch(choice)
    {
        case 0:
            return 0;
        case 1:
            student::addAtStart();
            break;
        case 2:
            student::addAtEnd();
            break;
        case 3:
            student::addAtPosition();
            break;
        case 4:
            student::showAll();
            break;
        case 5:
            student::remove(0);
            break;
        case 6:
            student::remove();
            break;
        case 7:
            student::removeAll();
            break;
        default:
            cout << "Invalid choice. Try again...\n\n";
    }

    return 1;
}