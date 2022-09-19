#include<iostream>
using namespace std;

int main() {
    string input;
    int number;
    while (true) {
        cin >> input;
        if (input == "*")
            return 0;
        else if (input == "Hajj")
            cout << "Case " << ++number << ": Hajj-e-Akbar"<< endl;
        else
            cout << "Case " << ++number << ": Hajj-e-Asghar" << endl;
    }
}

