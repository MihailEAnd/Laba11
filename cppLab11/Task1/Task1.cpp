#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int x;
    Node* Next;
};

template <typename T>
class Array
{
    Node* Head, * Tail; 
public:
    Array() :Head(NULL), Tail(NULL) {}; 
    ~Array(); 
    T Push(int x); 
    T Peek();
    T Pop();
    friend ostream& operator << (ostream& stream, const Array& a); 
};

template <typename T>
Array<T>::~Array() 
{
    Node* temp = Head; 
    while (temp != 0) 
    {
        temp = Head->Next; 
        delete Head;  
        Head = temp; 
    }
}

void Array<void>::Push(int x)
{
    Node* temp = new Node; 
    temp->x = x;
    temp->Next = NULL;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}
ostream& operator << (ostream& stream, const Array<void>& a)
{
    Node* temp = a.Head;
    while (temp != NULL)
    {
        stream << temp->x << "";
        temp = temp->Next;
    }
    return stream << endl;
}
void Array<void>::Peek()
{
    cout << Head->x;
}
void Array<void>::Pop()
{
    Head = Head->Next;
}
void main()
{
    Array<void> arr;
    int size, count;
    cout << "Size = ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Count " << i << "/" << size << " = ";
        cin >> count;
        arr.Push(count);
    }
    cout << arr;
    arr.Peek();
    arr.Pop();
    cout << endl;
    cout << arr;
}

