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

int indexx = 0;
int times[MX];


//DFT
void printTreePreOrder(node* root) {
    if (root == NULL) return;
    times[indexx++] = root->data;
    // cout << root->data << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);

    times[indexx++] = root->data;

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

//BST
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

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    else if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL, root->right == NULL)
        {
            delete root;
            root == NULL;
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
    // deleteNode(root, 23);
    root = Insert(root, 50);
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 78);
    root = Insert(root, 70);

    printTreePreOrder(root);
    cout << endl;
    printTreeInOrder(root);
    cout << endl;
    printTreePostOrder(root);
    cout << endl;
    cout << findMin(root)->data;
    cout << endl;
    cout << findMax(root)->data;
    cout << endl;
    cout << search(root, 235);
    cout << endl;
    // deleteNode(root, 50);
    // deleteNode(root, 190);
    // deleteNode(root, 40);
    cout << endl;
    printTreeInOrder(root);

    // printTreePreOrder(root);
    // for (int i = 0; i < indexx; i++)
    // {
    //     cout << times[i] << " ";
    // }

    cout << endl << getHeight(root);
}

//height search delete balanced tree 