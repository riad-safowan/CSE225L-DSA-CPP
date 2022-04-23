#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insertNode(node* root, int info) {
    if (root == NULL)
    {
        node* temp = newNode(info);
        root = temp;
        return root;
    }
    else if (info < root->data) {
        root->left = insertNode(root->left, info);
    }
    else {
        root->right = insertNode(root->right, info);
    }
    return root;
}

void printTreePreOrder(node* root) {
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreeInOrder(node* root) {
    if (root == NULL)
    {
        return;
    }
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}

int main() {
    node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 78);
    root = insertNode(root, 70);
    printTreeInOrder(root);
    return 0;
}