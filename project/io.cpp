#include <bits/stdc++.h>
using namespace std;
#define MX_LINES 80

bool compare(string x, string y)
{
    return x < y;
}

string to_lower_case(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main() {

    map<string, int> array[MX_LINES];
    map<string, int> map;
    int line = 0;

    ifstream input;
    input.open("input.txt");
    if (input)
    {
        string data;
        while (input.good()) {
            input >> data;
            data = to_lower_case(data);
            for (int i = 0; i < data.length(); i++)
            {
                if (data[data.length() - 1] == ',') {
                    data.erase(data.length() - 1);
                }
                else if (data[data.length() - 1] == '.') {
                    data.erase(data.length() - 1);
                    line++;
                }
            }
            map[data]++;
            array[line][data]++;
        }

        vector<string> words;
        for (auto const& pair : map) {
            words.push_back(pair.first);
        }
        sort(words.begin(), words.end(), compare);

        ofstream output;
        output.open("output.csv");

        output << "line\\word,";
        for (int i = 0; i < words.size(); i++)
        {
            output << words[i] << ", ";
        }
        output << endl;

        for (int i = 0; i < line; i++)
        {
            output << i << ", ";
            for (int j = 0; j < words.size(); j++)
            {
                output << array[i][words[j]] << ", ";
            }
            output << endl;
        }
    }
    else cout << "Error at file opening";
}
