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
 void controls(Node * head)
 {
     char x;
     while(x != 'e')
     {
     cout<<"Enter 'i' to insert a new Node || Enter 'd' to delete a Node || Enter 'e' to exit"<<endl;
     cin>>x;
     switch(x)
     {
         case 'i':
             {
                 int index, data;
                 cout<<"Enter the index at which you want to insert the Node"<<endl;
                 cin>>index;
                 cout<<"Enter value: "<<endl;
                 cin>>data;
                 insertNode(head, index, data);
                 printNodes(head);
                 break;
             }

             case 'd':
             {
                 int index;
                 cout<<"Enter the index from which you want to delete the Node"<<endl;
                 cin>>index;
                 deleteNode(head, index);
                 printNodes(head);
                 break;
             }

             case 'e':
                break;

             default:
                {
                cout<<"Wrong character entered"<<endl;
                }

     }
     }
 }

int main()
{
    cout<<"--Enter the Linked List--"<<endl;
    Node * head = takeInput();
    cout<<endl;
    controls(head);

    return 0;
}
