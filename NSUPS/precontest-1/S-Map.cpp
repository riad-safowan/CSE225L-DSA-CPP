#include<bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1: {
            string name;
            int marks;
            cin >> name >> marks;
            try {
                marks += m[name];
            }
            catch (exception e) {}
            m[name] = marks;
            break;
        }
        case 2: {
            string name;
            cin >> name;
            m[name] = 0;
            break;
        }
        case 3: {
            string name;
            cin >> name;
            try {
                cout << m.at(name) << endl;
                break;
            }
            catch (exception e) {
                cout << 0 << endl;
                break;
            }
        }
        }
    }
}