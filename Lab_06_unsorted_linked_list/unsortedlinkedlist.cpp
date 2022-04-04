#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head;

void insertAtFirst(int item) {

    node* temp = new node();

    temp->data = item;

    temp->next = NULL;

    if (head != NULL) {

        temp->next = head;
    }

    head = temp;
}


void insetAtLast(int item) {

    node* temp = new node();
    temp->data = item;

    temp->next = NULL;

    node* index = head;

    while (index->next != NULL) {

        index = index->next;
    }

    index->next = temp;
}


void insertPosition(int item, int pos) {

    node* temp = new node();
    temp->data = item;
    temp->next = NULL;
    node* index = head;
    for (int i = 0; i < pos - 1; i++) {
        index = index->next;
    }
    temp->next = index->next;
    index->next = temp;

}

void DeleteAtFirst() {

    node* temp = head;
    head = temp->next;
    delete head;
}

/*
void DeletePosition(){
    node* index = head;

    for(int i=1; i<pos-1; i++){
        index = index->next;
    }

}
*/

void Print() {

    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintHighestElement() {


    int highest = 0;

    int sum = 0;
    node* temp = head;

    while (temp != NULL) {

        sum = sum + temp->data;
        if (temp->data > highest) {
            highest = temp->data;
        }
        cout << temp->data << " ";
        temp = temp->next;



    }

    cout << endl;
    cout << "Highest number is:";
    cout << highest << endl;

    cout << "Sum is: " << sum;

}



int main()
{

    head = NULL;


    insertAtFirst(5);
    insertAtFirst(8);
    insertAtFirst(10);



    PrintHighestElement();


    return 0;
}
