#include <bits/stdc++.h>
using namespace std;

#define SIZE 26

// function to print the character and its frequency
// in order of its occurrence
void characterFrequency(string str)
{
    int n = str.size();

    int freq[SIZE];

    // initialize all elements of freq[] to 0
    memset(freq, 0, sizeof(freq));

    // accumulate frequency of each character in 'str'
    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    for (int i = 0; i < n; i++) {

        if (freq[str[i] - 'a'] != 0) {

            cout << str[i] << freq[str[i] - 'a'] << " ";

            freq[str[i] - 'a'] = 0;
        }
    }
}

// Driver program to test above
int main()
{
    string str = "happychegging";
    characterFrequency(str);
    return 0;
}