#include<iostream>
using namespace std;

void swap(long double* a, long double* b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}

void sort(long double array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++) if (array[j] > array[j + 1])
            swap(&array[j], &array[j + 1]);

}

int main() {
    int n;
    cin >> n;
    long double l;
    cin >> l;
    long double a[n];

    long double minimumRadius;
    for (int i = 0; i < n; i++)
    {
        long double value;
        cin >> value;
        a[i] = value;
    }

    sort(a, n);
    long double largestDistance = a[0] * 2;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] > largestDistance)
            largestDistance = a[i + 1] - a[i];

    }
    if ((l - a[n - 1]) * 2 > largestDistance)
        largestDistance = (l - a[n - 1]) * 2;

    minimumRadius = largestDistance / 2;
    cout << to_string(minimumRadius);

    return 0;
}