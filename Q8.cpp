#include <iostream>
#include <queue>
using namespace std;

class BTNode
{
    public:
    BTNode * left;
    BTNode * right;
    int data;

    BTNode(int data){
        left = NULL;
        right = NULL;
        this->data =  data;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
    private:
    BTNode * insertNode(BTNode * node, int data){
        if(node==NULL){
            BTNode * n = new BTNode(data);
            return n;
        }
        if(data < node->data){
            node->left = insertNode(node->left, data);
        }else{
            node->right = insertNode(node->right, data);
        }
        return node;
    }

    BTNode * deleteNode(BTNode * node, int data)
    {
        if(!node) return NULL;

        if(data < node->data){
            node->left = deleteNode(node->left, data);
        }else if(data > node->data){
            node->right = deleteNode(node->right, data);
        }else{
            if(!node->left && !node->right){
                delete node;
                return NULL;
            }else if(!node->left){
                BTNode * temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(!root->right){
                BTNode * temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BTNode * minNode = node->right;
                while(minNode->left){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteNode(node->right, rightMin);
            }
        }
        return node;
    }

    public:
    BTNode * root;

    BST()
    {
        root = NULL;
    }

    void Insert(int data)
    {
        root = insertNode(root, data);
    }

    void Delete(int data)
    {
        root = deleteNode(root, data);
    }

    void print()
    {
        queue<BTNode*> q;
        q.push(root);

        while(!q.empty()){
            BTNode * f = q.front();
            q.pop();
            cout<<f->data<<": "; 

            if(f->left){
                cout<<"L"<<f->left->data<<" ";
                q.push(f->left);
            }
            if(f->right){
                cout<<"R"<<f->right->data<<" ";
                q.push(f->right); 
            }
            cout<<endl;
        }
    }
};

int main()
{
    BST b;
    int n;
    int flag;
    cout<<"Enter the number of nodes u want to insert: ";
    cin>>n;
    cout<<endl;
    for(int i = 0; i<n; i++){
        int x;
        cout<<"Enter the value: ";
        cin>>x;
        b.Insert(x);
    }

    b.print();
    cout<<endl;
    cout<<"Enter the element u want to insert: ";
    cin>>flag;
    b.Insert(flag);
    b.print();
    cout<<endl;
    cout<<"Enter the element u want to delete: ";
    cin>>flag;
    b.Delete(flag);
    b.print();

    return 0;
}