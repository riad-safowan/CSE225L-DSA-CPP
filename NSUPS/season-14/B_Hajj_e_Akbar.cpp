#include<bits/stdc++.h>
using namespace std;

int main() {
    string text;
    int n;
    while (true) {
        cin >> text;
        if (text == "*")
            return 0;
        string o = (text == "Hajj") ?
            "Case " + to_string(++n) + ": Hajj-e-Akbar\n" :
            "Case " + to_string(++n) + ": Hajj-e-Asghar\n";
        cout << o;
    }
}
