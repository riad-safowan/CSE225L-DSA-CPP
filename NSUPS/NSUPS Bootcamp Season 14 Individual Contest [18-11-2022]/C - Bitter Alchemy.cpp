#include <iostream>
using namespace std;

int main()
{
    int n, x, m;
    cin >> n >> x;
    int sm = 10000;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (sm > m)
            sm = m;
        total++;
        x -= m;
    }
    total += (x / sm);
    cout << total << "\n";
}