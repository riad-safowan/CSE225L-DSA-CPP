#include<bits/stdc++.h>
using namespace std;

string getBin(int d) {
    string s;
    while (d > 0)
    {
        if (d % 2 == 1){
            d--;
            s.append("1");
        }
        else 
            s.append("0");
        d /= 2;
    }
    return s;
}

int getResult(int n1, int n2) {
    string s1 = getBin(n1);
    string s2 = getBin(n2);

    int result = 0;
    int x = 1;
    if (s1.length() < s2.length()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s1[i] != s2[i])
            result += x;
        x *= 2;
    }
    for (int i = s2.length(); i < s1.length(); i++) {
        if (s1[i] == '1')
            result += x;
        x *= 2;
    }
    return result;
}

int main() {
    ifstream input;
    input.open("input.txt");
    if (input)
    {
        while (input.good()) {
            int n1, n2;
            input >> n1 >> n2;
            cout << getResult(n1, n2)<<endl;
        }
    }
}