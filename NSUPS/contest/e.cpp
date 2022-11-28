#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, in;
        cin >> n >> s;
        multiset<int> a;
        multiset<int>::iterator it = a.begin();
        for (int i = 0; i < n; i++)
        {
            cin >> in;
            a.insert(in);
        }
        bool d = false;
        int l = 1, bar = 0;
       
        while (!d)
        {
           while (bar<s)
           {
            if(s-bar>=*it){
                bar+=*it; 
                a.erase(it);
                it=a.begin();
            }else{
                it++;
            }
           
           }
           
        }

    }
}