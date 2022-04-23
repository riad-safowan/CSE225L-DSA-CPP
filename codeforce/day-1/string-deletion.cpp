#include<iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int x = 0; x < t; x++)
    {
        string s;
        char c;
        cin >> s;
        cin >> c;
        bool doo = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                if (i % 2 == 0)
                {
                    cout << "YES"<<endl;
                    doo = false;
                    break;
                }
            }

        }
        if (doo)
        {
            cout << "NO"<<endl;
        }
    }
    return 0;
}