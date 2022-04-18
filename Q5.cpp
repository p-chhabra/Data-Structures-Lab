#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack
{
public:
    int capacity;
    int nextIndex;
    T * arr;

    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        nextIndex = 0;
    }

    void push(int data)
    {
        if(capacity == nextIndex)
        {
            capacity = capacity*2;
            T * newArr = new T[capacity];
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
    T top()
    {
        return arr[nextIndex-1];
    }
};

void Postfix(char *a)
{    Stack<char> s(5);
    char output[50],t;
    for(int i=0;a[i]!='\0';i++)
    {   char ch = a[i];
        switch(ch)
        {
        case '^':
        case '-':
        case '+':
        case '/':
        case '*':   s.push(ch);
                    break;
        case ')': t=s.top();
                    s.pop();
                   cout<<t;
                    break;
        }
        if (isalpha(ch))
            cout<<ch;
    }
}

int main()
{
    cout<<"Enter a infix expression: "<<endl;
    char input[100];
    cin>>input;
    cout<<endl<<"Postfix expression: "<<endl;
    Postfix(input);
    cout<<endl;
    return 0;
}
