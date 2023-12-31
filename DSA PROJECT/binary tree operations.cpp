#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root)
{
    cout<<"ENTER DATA: " <<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1 )
    {
        return NULL;
    }
    cout<<"ENTER DATA TO FOR LEFT NODE : "<<endl;
    int data;
    cin>>data;
    root->left = buildTree(root->left);
     cout<<"ENTER DATA TO FOR right NODE : "<<endl;
    int data;
    cin>>data;
    root->right = buildTree(root->right);

    return root;
}
int main()
{
    Node* root = NULL;
    buildTree(root);


    return 0;
}
