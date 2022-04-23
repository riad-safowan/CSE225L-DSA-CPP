#include<iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, r, b;
        scanf("%d%d%d", &n, &r, &b);
        int total = r + b;
        int ra = (r + b) / (b + 1);
        char asn[n];
        for (int j = 0; j < total;)
        {
            for (int k = 0; k < ra; k++)
            {
                if (r-- > 0)
                {
                    asn[j] = 'R';
                    j++;
                }
            }
            if (j < (total))
            {
                asn[j] = 'B';
                j++;
                b--;
            }
            ra = (r + b) / (b + 1);
        }
        for (int x = 0; x < n; x++)
        {
            cout << asn[x];
        }
        cout << endl;
    }
}