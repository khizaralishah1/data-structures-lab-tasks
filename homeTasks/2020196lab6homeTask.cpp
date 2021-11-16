//Khizar Ali Shah 2020196
//Lab 6 Home task. Insertion Sort

#include <iostream>
using namespace std;

struct node
{
    string name;
    int reg;
    node* next;

} *head = nullptr, *last = nullptr;

void insert(string, int);
void insertBetween(string, int, node*);
void print();
int mainMenu();
void sortReg();
void sortName();

int main()
{
    int runs = 1;
    while(runs)
    {
        runs = mainMenu();
    }

    return 0;
}

void insert(string n, int r)
{
    if(head == nullptr)
    {
        head = new node;
        head->name = n;
        head->reg = r;
        head->next = nullptr;
        last = head;
        return;
    }

    last->next = new node;
    last->next->next = nullptr;
    last->next->name = n;
    last->next->reg = r;
    last = last->next;
}

void insertBetween(string n, int r, node* temp)
{
    node* newNode = new node;
    newNode->name = n;
    newNode->reg = r;

    if(temp == nullptr)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void print()
{
    node* temp = head;
    
    while(temp!=nullptr)
    {
        cout << "Name: " << temp->name << "\tReg: " << temp->reg << endl;
        temp = temp->next;
    }

    cout << endl << endl;
}

int mainMenu()
{
    int choice;
    cout << "\n\n0. Print All\n1. Enter a student\n2. Sort by name\n3. Sort by reg\n4. Exit\n\nYour Choice: ";
    cin >> choice;

    string n;
    int r;

    switch(choice)
    {
        case 0:
            print();
            break;
        case 1:
            cout << "Enter student name: ";
            cin >> n;
            cout << "Enter reg number: ";
            cin >> r;
            insert(n, r);
            break;
        case 2:
            sortName();
            break;

        case 3:
            sortReg();
            break;

        case 4:
            return 0;

        default:
            cout << "\nEnter valid choice. Try again...\n\n";    
    }

    return 1;
}

void sortName()
{
    node* i = head->next;
    node* prevI = head;
    node* temp = head;
    node* prevTemp = nullptr;

    while(i != nullptr)
    {
        while(i->name > temp->name)
        {
            prevTemp = temp;
            temp = temp->next;
        }

        if(temp != i)
        {
            insertBetween(i->name, i->reg, prevTemp);
            prevI->next = i->next;
        }

        prevI = i;
        i = i->next;
        temp = head;
        prevTemp = nullptr;
    }

    cout << "\n\nSORTED BY NAME SUCCESSFULLY\n\n";
}

void sortReg()
{
    node* i = head->next;
    node* prevI = head;
    node* temp = head;
    node* prevTemp = nullptr;

    while(i != nullptr)
    {
        while(i->reg > temp->reg)
        {
            prevTemp = temp;
            temp = temp->next;
        }

        if(temp != i)
        {
            insertBetween(i->name, i->reg, prevTemp);
            prevI->next = i->next;
        }

        prevI = i;
        i = i->next;
        temp = head;
        prevTemp = nullptr;
    }

    cout << "\n\nSORTED BY REG NUMBER SUCCESSFULLY\n\n";
}