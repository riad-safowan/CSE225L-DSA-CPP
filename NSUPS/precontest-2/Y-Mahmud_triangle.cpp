// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     long long a[100000];
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>a[i];
//     sort(a+1,a+1+n);
//     int flag = 0;
//     for(int i=2;i<=n-1;i++){
//         if(a[i]+a[i-1]>a[i+1])
//             flag = 1;
//     }
//     if(flag)cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n;
    set<int>s;
    while (n--)
    {
        cin >> v;
        s.insert(v);
    }

    set<int>::iterator it = s.end();
    int f, sl, l;
    l = *it;
    it--;
    sl = *it;
    it = s.begin();
    f = *it;

    if (l + sl > f) cout << "YES\n";
    else cout << "NO\n";
}