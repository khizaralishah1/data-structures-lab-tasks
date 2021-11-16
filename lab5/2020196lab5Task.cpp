// Khizar Ali Shah
// 2020196
#include <iostream>
using namespace std;

bool verifyBrackets(string);
void enqueue(char*, int&, int&, char); // takes in queue array, its front and rear, and the value to be inserted
void dequeue(char*, int&, int&);
bool corresponds(char, char); // utility function

int main()
{
    string brac;
    cout << "Enter an expression having brackets: ";
    cin >> brac;

    cout << "\n\nGive string: " << brac << "\n\n\n";

    if ( verifyBrackets(brac) )
        cout << "BALANCED\n\n";
    else
        cout << "NOT Balanced\n\n";

    return 0;
}

bool verifyBrackets(string b)
{
    int len = b.length();

    //creating a queue
    char queue[len];
    int front = -1, rear = -1;

    for ( int i = len-1; i >= 0; --i )
    {
        //populating queue
        if ( b[i] == ')' || b[i] == '}' || b[i] == ']' )
            enqueue(queue, front, rear, b[i]); // front and rear must be passed by reference!

        else if ( b[i] == '(' || b[i] == '{' || b[i] == '[' )
        {
            if ( i == len-1 || front == -1 ) return false; // If starting bracket is seen in the end, then it is not balanced trivially.

            else if ( corresponds ( b[i], queue[rear] ) )
                dequeue(queue, front, rear);

            else return false;
        }     
    }

    if ( front != -1 )
        return false;
        
    return true;
}

void enqueue(char* queue, int& front, int& rear, char value)
{
    if ( front == - 1 )
        ++front;
    ++rear;

    queue[rear] = value;
}

void dequeue(char* queue, int& front, int& rear)
{
    if ( front == 0 && rear == 0 ) front = rear = -1;

    else --rear;
}

bool corresponds(char a, char b)
{
    if ( a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']'  ) 
        return true;
    
    return false;
}