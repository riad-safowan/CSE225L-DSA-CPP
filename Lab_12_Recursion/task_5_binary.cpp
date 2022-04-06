#include<iostream>
using namespace std;

int findSmallest(int a[], int size, int smallest) {
    if (size == 1)
        return smallest;
    if (a[size - 1] > a[size - 2])
        smallest = a[size - 2];
    smallest = findSmallest(a, size - 1, smallest);
    return smallest;
}

int minimumElement(int a[], int size) {
    if (size == 1)
        return a[0];
    return findSmallest(a, size, a[size - 1]);
}

int main() {
    int a[5] = { 10, 1,  15, 2 ,3 };
    cout << minimumElement(a, 5);
    return 0;
}