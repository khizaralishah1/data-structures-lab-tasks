#include <iostream>
#include <string>
using namespace std;

struct node
{
    string name;
    int reg;
    node* next;

};

node* head = nullptr;

int mainMenu();

int main()
{
    int exits = 1;

    while ( exits )
    {
        exits = mainMenu();
    }
    

    return 0;
}

void push()
{
    string n;
    int r;

    cout << "Enter Name: ";
    cin >> n;
    cout << "Enter Reg: ";
    cin >> r;

    if ( head == nullptr )
    {
        head = new node;
        head->name = n;
        head->reg = r;
        head->next = nullptr;
        return;
    }

    node* temp = new node;
    temp->name = n;
    temp->reg = r;
    temp->next = head;
    head = temp;
}

void pop()
{
    if ( head == nullptr )
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    node* temp = head;
    head = head->next;

    delete temp; 

    cout << "\nPopped!\n";
}

void print()
{
    if ( head == nullptr )
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    node* temp = head;

    cout << "\nPrinting All Students: \n\n";

    while ( temp != nullptr )
    {
        cout << temp->name << "\t" << temp->reg << endl;
        temp = temp->next;
    }
}

void seeTop()
{
    if ( head == nullptr )
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "\n\nTop Record is:\nName: " << head->name << "\tReg Number: " << head->reg << endl;
}

int mainMenu()
{

    cout << "\n0. Exit Program\n1. Push Student in Stack\n";
    cout << "2. Pop Student from Stack\n3. Show top record in stack\n";
    cout << "4. Display all students\n\n";

    int choice;

    cin >> choice;

    switch ( choice )
    {
        case 0:
            return 0;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            seeTop();
            break;
        case 4:
            print();
            break;
        default:
            cout << "\n\nPlease enter correct choice. Try again...\n\n";
    }

    return 1;
}