#include <iostream>
using namespace std;

int smallestValue(int *, int);
void traverseBack(int *, int);

int main()
{
    const int size = 5;
    int *arr = new int[size];

    cout << "Enter " << size << " array values: \n";
    for(int i=0; i<size; ++i)
        cin >> *(arr+i);

    traverseBack(arr, size);

    int smallest = smallestValue(arr, size);
    cout << "Smallest: " << smallest << endl;

    return 0;
}

int smallestValue(int *temp, int size)
{
    int smallest = *temp;

    for (int i = 0; i < size; ++i)
        if ( *(temp + i) < smallest )
            smallest = *(temp + i);

    return smallest;
}

void traverseBack(int *temp, int size)
{
    cout << "\nTraversal Back: \n";
    
    for (int i = size-1; i >= 0; --i)
        cout << i << "\tValue = " << *(temp+i) << "\tAddress = " << temp+i << endl;

    cout << endl;
}