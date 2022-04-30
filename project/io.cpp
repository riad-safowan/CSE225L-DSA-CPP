#include <bits/stdc++.h>
using namespace std;
#define MX_LINES 100

int main() {
    ifstream input;
    input.open("input.txt");
    if (input)
    {
        map<string, int> array[MX_LINES];
        set<string> words;
        int line = 0;
        string word;

        while (input.good()) {
            input >> word;
            for (auto& ch : word)
                ch = tolower(ch);

            int last_i = word.length() - 1;
            if (word[last_i] == '.') {
                word.erase(last_i);
                array[line++][word]++; words.insert(word);
                continue;
            }
            if (word[last_i] == ',')
                word.erase(last_i);
            array[line][word]++; words.insert(word);
        }

        ofstream output;
        output.open("output.csv");

        output << "line\\word,";
        for (auto word : words)
            output << word << ", ";
        output << endl;

        for (int i = 0; i < line; i++)
        {
            output << i << ", ";
            for (auto word : words)
                output << array[i][word] << ", ";
            output << endl;
        }
    }
}
