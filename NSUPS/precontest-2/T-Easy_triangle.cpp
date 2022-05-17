#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for (int i = 1;i <= t;i++) {
        long long int s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (s1 + s2 <= s3 || s2 + s3 <= s1 || s1 + s3 <= s2 || (s1 <= 0 || s2 <= 0 || s3 <= 0))
            printf("Case %d: Invalid\n", i);
        else if (s1 == s2 && s2 == s3)
            printf("Case %d: Equilateral\n", i);
        else if (s1 == s2 || s2 == s3 || s1 == s3)
            printf("Case %d: Isosceles\n", i);
        else
            printf("Case %d: Scalene\n", i);
    }
    return 0;
}
