#include<iostream>
#include<set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<long long> s;
    while (n--)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1: {
            long long d;
            cin >> d;
            s.insert(d);
            break;
        }
        case 2: {
            long long d;
            cin >> d;
            if (s.find(d) != s.end())
            {
                s.erase(d);
            }
            break;
        }
        case 3: {
            long long d;
            cin >> d;
            if (s.find(d) != s.end())
            {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            break;
        }
        }
    }
}