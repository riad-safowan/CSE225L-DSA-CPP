#include<iostream>
using namespace std;
#define MX 1500
struct  work
{
    int start;
    int end;
};

int main() {
    int t, p1, p2, p3, t1, t2;
    cin >> t >> p1 >> p2 >> p3 >> t1 >> t2;
    int total;
    work w[MX];
    for (int i = 0; i < t; i++)
    {
        int l, r;
        cin >> l >> r;
        w[i] = work{ l,r };
    }

    for (int i = 0; i < t; i++)
    {
        int s = w[i].start;
        int e = w[i].end;
        int tim = e - s;
        total = total + (tim * p1);
        if (i != t - 1)
        {
            int s2 = w[i + 1].start;
            if (s2 - e > t1)
                total = total + (t1 * p1);
            else {
                total = total + ((s2 - e) * p1);
            }
        }
    }
    for (int i = 0; i < t - 1; i++)
    {
        int s = w[i].end;
        int e = w[i + 1].start;
        int tim = (e - s) - t1;
        if (tim > 0) {
            if (tim > t2) {
                total += t2 * p2;
                tim -= t2;
                if (tim > 0)
                    total += tim * p3;
            }
            else {
                total += tim * p2;
            }
        }
    }
    cout << total;
}