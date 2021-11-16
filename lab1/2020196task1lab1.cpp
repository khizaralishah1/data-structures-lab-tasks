#include <iostream>
using namespace std;

int main()
{
    const int size = 6;
    int arr[size];
    int* ptr = arr;

    cout << "Enter values into an array:\n";
    for(int i=0; i<size; ++i)
        cin >> *(ptr+i);

    cout << "\nDisplay array:\n";
    for(int i=0; i<size; ++i)
        cout << *(ptr+i) << " ";

    //finding maximum value
    int max = *ptr; // stores the first element of array
    for(int i=0; i<size; ++i)
        if ( *(ptr+i) > max )
            max = *(ptr+i);

    cout << "\n\nMaximum value is: " << max << endl;

    return 0;
}