#include <bits/stdc++.h>
using namespace std;
#define MX_LINES 100

int main() {
    map<string, int> array[MX_LINES];
    set<string> words;
    int line = 0;

    ifstream input;
    input.open("input.txt");
    ofstream output;
    output.open("output.csv");

    if (input)
    {
        string word;
        while (input.good()) {
            input >> word;
            for (int i = 0; i < word.length(); i++)
                word[i] = tolower(word[i]);

            for (int i = 0; i < word.length(); i++)
            {
                if (word[word.length() - 1] == ',')
                    word.erase(word.length() - 1);
                else if (word[word.length() - 1] == '.') {
                    word.erase(word.length() - 1);
                    line++;
                }
            }
            array[line][word]++;
            words.insert(word);
        }

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
