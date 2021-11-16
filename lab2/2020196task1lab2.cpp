#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inches;
};

int main()
{
    Distance d[2];

    cout << "\n\nDistance 1:\n";
    cout << "Feet: ";
    cin >> d[0].feet;
    cout << "Inches: ";
    cin >> d[0].inches;
    cout << "\n\nDistance 2:\n";
    cout << "Feet: ";
    cin >> d[1].feet;
    cout << "Inches: ";
    cin >> d[1].inches;

    Distance sum;

    sum.feet = d[0].feet + d[1].feet;

    if ( d[0].inches + d[1].inches >= 12 )
    {   
        sum.feet++;
        sum.inches = d[0].inches + d[1].inches - 12;
    }
    else
        sum.inches = d[0].inches + d[1].inches;

    cout << "\n\n\nSum = " << sum.feet << " feet and " << sum.inches << " inches.\n";


    return 0;
}