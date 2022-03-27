#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.length() > 10)
        {
            string t = "";
            t = t + s.at(0);
            t = t + to_string(s.length() - 2);
            t = t + s.at(s.length() - 1);
            cout << t << "\n";
        }
        else
            cout << s << "\n";
    }

    return 0;
}