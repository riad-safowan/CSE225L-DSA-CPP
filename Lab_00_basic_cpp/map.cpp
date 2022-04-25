#include<iostream>
#include<map>
using namespace std;
int main() {
    map<string, string> m;
    // m.insert(pair<string, string>("asdf asdf", "jkl asdf"));
    string s, l,s2;
    // cin>>s>>l;
    getline(cin, s);
  
    getline(cin, l);
    // m.insert(make_pair(s, l));

    // string s2;
    // cin>>s2;
  
    getline(cin, s2);
    cout << "s1: " << s << " s2: " << s2 << endl;
    // cout << m.at(s2);

    // string a, b, c, d, e;
    // getline(cin, a);
    // cout << a << endl;
    // getline(cin, b);
    // cout << b << endl;
    // getline(cin, c);
    // cout << c << endl;
    // getline(cin, d);
    // cout << d << endl;

}