#include<iostream>
using namespace std;

int main() {
    string text;
    int n;
    while (true) {
        cin >> text;
        if (text == "*")
            return 0;
        else if (text == "Hajj")
            cout << "Case " << ++n << ": Hajj-e-Akbar";
        else
            cout << "Case " << ++n << ": Hajj-e-Asghar";
    }
}

