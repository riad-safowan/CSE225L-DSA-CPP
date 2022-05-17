#include<bits/stdc++.h>
using namespace std;
int gcdd(int m, int n) {
    int a, b;
    if (m >= n)
    {
        a = m;
        b = n;
    }
    else {
        b = m;
        a = n;
    }

    int r = b;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}
int main()
{
    int n, element_i, g;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &element_i);
        g = (i == 0 ? element_i : gcdd(g, element_i));
    }

    printf("%d\n", g*n);
    return 0;
}

// int main() {
//     int s;
//     cin >> s;
//     int a[s];

//     for (int i = 0; i < s; i++)
//         cin >> a[i];

//     int smallest = abs(a[0] - a[1]);
//     for (int i = 0; i < s; i++)
//         for (int j = 0; j < s; j++)
//         {
//             if (i != j) {
//                 int v = abs(a[i] - a[j]);   
//                 if (v < smallest) smallest = v;
//             }
//         }
    
//     cout << smallest * s;
// }