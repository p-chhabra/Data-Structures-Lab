#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int capacity;
    int nextIndex;
    int * arr;

    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        nextIndex = 0;
    }

    void push(int data)
    {
        if(capacity == nextIndex)
        {
            capacity = capacity*2;
            int * newArr = new int[capacity];
            for(int i = 0; i<capacity/2; i++)
            {
                newArr[i] = arr[i];
            }
            delete arr;
            arr = newArr;
        }

        arr[nextIndex] = data;
        nextIndex++;
    }

    void pop()
    {
        if(nextIndex==0){
            cout<<"Stack Empty"<<endl;
            return;
        }
        nextIndex--;
    }

    int getSize()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    int top()
    {
        return arr[nextIndex-1];
    }
};

int main()
{
    Stack s(4);
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(1);
    cout<<s.top();
    return 0;
}
