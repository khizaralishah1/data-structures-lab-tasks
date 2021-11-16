#include <iostream>
using namespace std;

struct Date
{
    int month, day, year;
};

struct University
{
    char name[20], category[15], location[30];
    Date date;
};

void inputDetails( University* );
void printDetails( University );


int main()
{
    University myUni;

    inputDetails(&myUni);
    printDetails(myUni);


    return 0;
}

void inputDetails( University *u )
{
    cout << "Enter the following details of the university\n\n\n";

    cout << "Name: ";
    cin >> u->name;

    cout << "Location: ";
    cin >> u->location;

    cout << "Category: ";
    cin >> u->category;

    cout << "Date of Creation:\n";
    cout << "Year: ";
    cin >> u->date.year;
    cout << "Month: ";
    cin >> u->date.month;
    cout << "Day: ";
    cin >> u->date.day;
}

void printDetails( University u )
{
    cout << "Printing the details of the university\n\n\n";

    cout << "Name:         " << u.name << endl;
    cout << "Location:     " << u.location << endl;
    cout << "Category:     " << u.category << endl;
    cout << "Date Created: " << u.date.day << "-" << u.date.month << "-" << u.date.year << endl;
}