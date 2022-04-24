#include<iostream>
#include<queue>
using namespace std;

class BTNode
{
    public:
    int data;
    BTNode * left;
    BTNode * right;

    BTNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BTNode * inputLevelWise()
{
    int rootData;
    cout<<"Enter the value of root: ";
    cin>>rootData;
    BTNode * root = new BTNode(rootData);

    queue<BTNode*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode * f = q.front();
        q.pop();

        int leftChildData;
        cout<<"Enter left child of "<<f->data<<": ";
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BTNode * child = new BTNode(leftChildData);
            q.push(child);
            f->left = child;
        }

        int rightChildData;
        cout<<"Enter right child of "<<f->data<<": ";
        cin>>rightChildData;
        if(rightChildData != -1)
        {
            BTNode * child = new BTNode(rightChildData);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

///Level Order Traversal
void printTreeLevelWise(BTNode * root)
{
    if(!root)
    {
        cout<<"Tree does not exist"<<endl;
        return;
    }

    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        BTNode * f = q.front();
        q.pop();
        cout<<f->data<<": ";

        if(f->left)
        {
            cout<<"L"<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right)
        {
            cout<<"R"<<f->right->data<<" ";
            q.push(f->right);
        }
        cout<<endl;
    }
}

int main()
{
    BTNode * root = inputLevelWise();
    cout<<endl;
    printTreeLevelWise(root);
}
