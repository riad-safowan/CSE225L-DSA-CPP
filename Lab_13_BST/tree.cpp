#include<iostream>
#include<queue>
using namespace std;

#define MX 100

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
    if (root == NULL)
        root = newNode(item);
    else if (item < root->data)
        root->left = Insert(root->left, item);
    else
        root->right = Insert(root->right, item);
    return root;
}

struct a
{
    int data;
    int start;
    int end;
};

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

void bfsTravel(node* root) {
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* curr_node = q.front();
        cout << curr_node << " ";

        if (curr_node->left != NULL)
            q.push(curr_node->left);

        if (curr_node->right != NULL)
            q.push(curr_node->right);
        q.pop();
    }
}

node* findMin(node* root) {
    if (root->left == NULL) return root;
    else return findMin(root->left);
}

node* findMax(node* root) {
    if (root->right == NULL) return root;
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

int bigger(int n1, int n2) {
    if (n1 < n2) return n2;
    else return n1;
}

int getHeight(node* root) {
    if (root == NULL) return 0;
    else return bigger(getHeight(root->left), getHeight(root->right)) + 1;
}

node* deleteNode(node* root, int item)
{
    if (root == NULL) return root;
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
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    node* root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 78);
    root = Insert(root, 70);

    cout << "Pre-Order: ";
    printTreePreOrder(root);
    cout << endl << "In-Order: ";
    printTreeInOrder(root);
    cout << endl << "Post-Order: ";
    printTreePostOrder(root);
    cout << endl << "Min: ";
    cout << findMin(root)->data;
    cout << endl << "Max: ";
    cout << findMax(root)->data;
    cout << endl;
    search(root, 70) ? cout << "found" : cout << "not found";
    cout << endl << "Tree Height: " << getHeight(root);

    root = deleteNode(root, 50);
    root = deleteNode(root, 70);
    root = deleteNode(root, 40);

    cout << endl << "Pre-Order(after deleting): ";
    printTreePreOrder(root);
}

/*
Output:

Pre-Order: 50 40 60 78 70
In-Order: 40 50 60 70 78
Post-Order: 40 70 78 60 50
Min: 40
Max: 78
found
Tree Height: 4
Pre-Order(after deleting): 60 78

*/