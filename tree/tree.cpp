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
    if (root == NULL) return;

    cout << root->data << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}
void printTreeInOrder(node* root) {
    if (root == NULL) return;

    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}
void printTreePostOrder(node* root) {
    if (root == NULL) return;

    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->data << " ";
}

int findMin(node* root) {
    if (root->left == NULL) return root->data;
    else return findMin(root->left);
}

int findMax(node* root) {
    if (root->right == NULL) return root->data;
    else return findMax(root->right);
}

node* findMaxNode(node* root) {
    if (root->right == NULL) return root;
    else return findMaxNode(root->right);
}

bool search(node* root, int key) {
    if (root == NULL) return false;
    else if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

void deleteNode(node* root, int key) {
    if (root->left == NULL && root->right == NULL) return;
    //left subtree
    if (root->left->data == key) {
        //no child
        if (root->left->left == NULL && root->left->right == NULL) {
            delete root->left;
            root->left = NULL;
        }
        //left child
        else if (root->left->left != NULL && root->left->right == NULL) {
            node* temp = root->left->left;
            delete root->left;
            root->left = temp;
        }
        //right child
        else if (root->left->left == NULL && root->left->right != NULL) {
            node* temp = root->left->right;
            delete root->left;
            root->left = temp;
        }
        //todo both subtree exists
    }
    //right subtree
    else if (root->right->data == key) {
        //no child
        if (root->right->left == NULL && root->right->right == NULL) {
            delete root->right;
            root->right = NULL;
        }
        //left child
        else if (root->right->left != NULL && root->right->right == NULL) {
            node* temp = root->right->left;
            delete root->right;
            root->right = temp;
        }
        //right child
        else if (root->right->left == NULL && &root->right->right != NULL) {
            node* temp = root->right->right;
            delete root->right;
            root->right = temp;
        }
        //todo both subtree exists
    }
    else if (key < root->data) return deleteNode(root->left, key);
    else return deleteNode(root->right, key);
}

int main() {
    node* root = NULL;
    root = Insert(root, 25);
    root = Insert(root, 15);
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 40);

    printTreePreOrder(root);
    cout << endl;
    printTreeInOrder(root);
    cout << endl;
    printTreePostOrder(root);
    cout << endl;
    cout << findMin(root);
    cout << endl;
    cout << findMax(root);
    cout << endl;
    cout << search(root, 235);
    cout << endl;
    deleteNode(root, 50);
    deleteNode(root, 190);
    deleteNode(root, 40);
    cout << endl;
    printTreeInOrder(root);

}

//height search delete balanced tree 