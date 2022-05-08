#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* makeNode(int info) {
    node* n = new node{ info,NULL,NULL };
    return n;
}

node* insert(node* root, int info) {
    if (root == NULL) {
        node* newNode = makeNode(info);
        root = newNode;
        return newNode;
    }
    else if (info < root->data) {
        root->left = insert(root->left, info);
    }
    else {
        root->right = insert(root->right, info);
    }
    return root;
}

void preOrderTraverse(node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
void inOrderTraverse(node* root) {
    if (root == NULL)
        return;
    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
}
void postOrderTraverse(node* root) {
    if (root == NULL)
        return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " ";
}

int findMin(node* root) {
    if (root->left == NULL)
        return root->data;
    else
        return findMin(root->left);
}

int findMax(node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

node* getMinNode(node* root) {
    if (root->left == NULL)
        return root;
    else
        return getMinNode(root->left);
}

node* search(node* root, int item) {
    if (root == NULL || root->data == item)
        return root;
    else if (item < root->data)
        return search(root->left, item);
    else return search(root->right, item);
}

node* deleteNode(node* root, int item) {
    if (root == NULL) return NULL;
    else if (item < root->data) root->left = deleteNode(root->left, item);
    else if (item > root->data) root->right = deleteNode(root->right, item);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            node* temp = getMinNode(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int getHeight(node* root) {
    if (root == NULL) return 0;
    else {
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if (l > r) return l + 1;
        else return r + 1;
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 12);
    root = insert(root, 13);

    cout << endl;
    preOrderTraverse(root);
    cout << endl;
    inOrderTraverse(root);
    cout << endl;
    postOrderTraverse(root);

    cout << endl << "Min: " << findMin(root);
    cout << endl << "Max: " << findMax(root);

    cout << endl << "Height: " << getHeight(root);

    root = deleteNode(root, 15);
    root = deleteNode(root, 20);
    root = deleteNode(root, 10);

    cout << endl;
    preOrderTraverse(root);
    cout << endl;
    inOrderTraverse(root);
    cout << endl;
    postOrderTraverse(root);
}