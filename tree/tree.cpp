#include<iostream>
using namespace std;


struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int item) {
    node* n = new node();
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* Insert(node* root, int item) {

    if (root == NULL) {
        root = newNode(item);
    }
    else if (item < root->data) {
        root->left = Insert(root->left, item);
    }
    else {
        root->right = Insert(root->right, item);
    }

    return root;
}

void printTreePreOrder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}
void printTreeInOrder(node* root) {
    if (root == NULL) {
        return;
    }
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}
void printTreePostOrder(node* root) {
    if (root == NULL) {
        return;
    }
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->data << " ";
}

int findMin(node* root) {
    if (root->left == NULL)
    {
        return root->data;
    }
    else {
        return findMin(root->left);
    }

}

int findMax(node* root) {
    if (root->right == NULL)
    {
        return root->data;
    }
    else {
        return findMax(root->right);
    }
}

int main() {
    node* root = NULL;
    root = Insert(root, 25);
    root = Insert(root, 15);
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 60);

    printTreePreOrder(root);
    cout << endl;
    printTreeInOrder(root);
    cout << endl;
    printTreePostOrder(root);
    cout << endl;
    cout << findMin(root);
    cout << endl;
    cout << findMax(root);
}