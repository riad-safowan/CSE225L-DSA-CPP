#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    set<string> words;
    set<string>::iterator it;
     stringstream ss;
    while (cin >> s) {
        if(s == "*") break;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';
        }

        ss.clear();
        ss << s;
        while (ss >> t)
            words.insert(t);
    }

    for (it = words.begin(); it != words.end(); it++)
        cout << *it << endl;  
}