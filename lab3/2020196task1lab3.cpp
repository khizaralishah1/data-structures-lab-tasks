#include <iostream>
using namespace std;

struct node
{
    float price;
    string productName;
    node* next;
};

node* head = nullptr;
node* last = nullptr;

void input(string, float);
void print();
void deleteItem(string);
int mainMenu();

int main()
{
    int runs = 1;

    while ( runs == 1 )
        runs = mainMenu();


    return 0;
}

void input(string itemName, float p)
{
    node* newNode = new node;
    newNode->price = p;
    newNode->productName = itemName;
    newNode->next = nullptr;

    if ( head == nullptr )
    {
        head = newNode;
        last = head;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void print()
{
    node* temp = head;

    cout << "\nPrinting Grocery Items: \n\n";
    while( temp != nullptr )
    {
        cout << temp->productName << "\t" << temp->price << endl;
        temp = temp->next;
    }
}

void deleteItem(string name)
{
    node* prev = head;
    node* current = head;

    while(current != nullptr && current->productName != name)
    {
        prev = current;
        current = current->next;
    }

    if ( current == head )
    {
        head = current->next;
        delete prev;
        return;
    }

    if(current != nullptr)
    {
        prev->next = current->next;
        delete current;
        cout << "Item '" << name << "' deleted successfully\n\n";
    }
    else
        cout << "The item '" << name << "' is not present in the list\n\n";
    
}

int mainMenu()
{
    int choice;
    
    cout << "\n\n1. Add Node\n2. Display List\n3. Delete Node\n4. Exit\n\n";
    cout << "Your Choice: ";
    cin >> choice;

    string productName;
    float price;

    switch(choice)
    {
        case 1:
            cout << "Enter Product Name: ";
            cin >> productName;
            cout << "Enter Product Price: ";
            cin >> price;
            input(productName, price);
            break;
        
        case 2:
            print();
            break;

        case 3:
            cout << "Enter Product Name: ";
            cin >> productName;
            deleteItem(productName);
            break;

        case 4:
            return 0;

        default:
            cout << "\nIncorrect choice. Please try again\n\n";
    }

    return 1;
}