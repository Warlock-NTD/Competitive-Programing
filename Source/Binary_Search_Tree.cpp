#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left ; Node *right;
    Node();
    Node(int ref_);
    void free(Node* root);
};
class Solution
{
    public:
    Node* minVal (Node* root);
    Node* delete_(Node* root, int ref_);
    Node* insert_(Node* root, int data);
    void inorder (Node* root);
};
Node* Solution::minVal(Node* root)
{
    Node* current = root;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}
void Node::free(Node* root)
{
    root->data = 0 ;
    root->left = NULL; root->right = NULL;
    delete root;
}
Node::Node()
{
    left = NULL;
    right= NULL;
    data = 0;
}
Node::Node(int ref_)
{
    data = ref_;
    left = NULL; right= NULL;
}
Node* Solution::insert_(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert_(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert_(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
void Solution::inorder(Node* root)
{
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
Node* Solution::delete_(Node* root, int ref_)
{
    if(root == NULL)    return root;
        if(ref_ > root->data)
            root->right = delete_(root->right,ref_);
        else if(ref_ < root->data)
            root->left = delete_(root->left,ref_);
        else if (ref_ == root->data)
        {
            if(root->left==NULL && root->right==NULL)   return NULL;
            else if(root->left == NULL)
            {
                Node* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                Node*temp = root->left;
                free(root);
                return temp;
            }
               Node* temp = minVal(root->right);
               root->data = temp->data;
               root->right = delete_(root->right, temp->data);

        }
    return root;
}
// 2, 1, 10, 6, 3, 8, 7, 13, 20.
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution myTree;
    Node *root=NULL;
    root = myTree.insert_(root,1);
    root = myTree.insert_(root,10);
    root = myTree.insert_(root,6);
    root = myTree.insert_(root,3);
    root = myTree.insert_(root,8);
    root = myTree.insert_(root,7);
    root = myTree.insert_(root,13);
    root = myTree.insert_(root,20);
    // first print .
    myTree.inorder(root);
    //
    root = myTree.insert_(root,14);
    root = myTree.insert_(root,0);
    root = myTree.insert_(root,35);
    // second print .
    cout<<'\n';
    myTree.inorder(root);
    //
    root = myTree.delete_(root,6);
    root = myTree.delete_(root,13);
    root = myTree.delete_(root,35);
    // third print .
    cout<<'\n';
    myTree.inorder(root);

    return 0;
}
