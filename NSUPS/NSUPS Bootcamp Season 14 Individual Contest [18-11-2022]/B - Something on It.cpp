#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int t = 700;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'o')
            t += 100;

    cout << t << "\n";
}