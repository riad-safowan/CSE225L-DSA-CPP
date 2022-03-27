#include<iostream>
using namespace std;


// void swap(long* a, long* b)
// {
//     long temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void sort(long array[], long n) {
//     long i, j;
//     for (i = 0; i < n - 1; i++)
//         for (j = 0; j < n - i - 1; j++) if (array[j] < array[j + 1])
//             swap(&array[j], &array[j + 1]);

// }

int main() {
    long n, count;
    cin >> n;
    long s1 = 0, s2 = 0, s3 = 0;
    long g1 = 0, g2 = 0, g3 = 0, g4 = 0;
    long groups[n];
    for (long i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        groups[i] = s;
    }

    // sort(groups, n);

    for (long i = 0; i < n; i++)
    {
        int s = groups[i];
        if (s == 4)
            g4++;
        else if (s == 3)
            g3++;
        else if (s == 2)
            g2++;
        else
            g1++;
    }
    for (long i = 0; i < 4; i++)
    {
        long n, s;
        if (i == 0)
        {
            n = g4;
            s = 4;
        }
        else if (i == 1) {
            n = g3;
            s = 3;
        }
        else if (i == 2) {
            n = g2;
            s = 2;
        }
        else {
            n = g1;
            s = 1;
        }

        for (long i = 0; i < n; i++)
        {
            if (s == 4)
                count++;
            else if (s == 3) {
                if (s3 > 0) {
                    s3--;
                }
                else {
                    count++;
                    s1++;
                }
            }
            else if (s == 2) {
                if (s2 > 0)
                    s2--;
                else if (s3 > 0) {
                    s3--;
                    s1++;
                }
                else {
                    s2++;
                    count++;
                }
            }
            else if (s == 1) {
                if (s1 > 0)
                    s1--;
                else if (s2 > 0) {
                    s2--;
                    s1++;
                }
                else if (s3 > 0) {
                    s3--;
                    s2++;
                }
                else {
                    count++;
                    s3++;
                }
            }
        }
    }


    cout << count;
    return 0;
}