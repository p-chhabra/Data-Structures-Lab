#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node * next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printNodes(Node * head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node *  takeInput()
{
    Node * head = NULL;
    Node * tail = NULL;
    int data;
    cout<<"Enter the first Element"<<endl;
    cin>>data;
    while(data != -1)
    {
        Node * n = new Node(data);
        if(head == NULL)
        {
            head = n;
            tail = n;
        }

        else
        {
            tail->next = n;
            tail = tail->next; //or we can do tail = n;
        }
        cin>>data;
    }
    return head;
}

Node * deleteNode(Node * head, int index)
{
    if(index<0) return head;
    if(index == 0 && head)
    {
        Node * temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 1;
    Node * temp = head;
    while(count <= index - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp && temp->next)
    {
        Node * del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        delete del;
        return head;
    }
    return head;
}

Node * insertNode(Node * head, int index, int data)
{
    if(index < 0) return head;
    if(index == 0)
    {
        Node * n = new Node(data);
        n->next = head;
        return n;
    }

    int count = 1;
    Node * temp = head;
    while(count<=index - 1)
    {
        temp = temp->next;
        count++;
    }
    if(temp)
    {
        Node * n = new Node(data);
        n->next = temp->next;
        temp->next = n;
        return head;
    }
    return head;
}

int main()
{
    Node * head = takeInput();
    cout<<endl;
    printNodes(head);
    head = insertNode(head,3,12);
    cout<<endl;
    printNodes(head);
    head = deleteNode(head,2);
    cout<<endl;
    printNodes(head);

    return 0;
}
