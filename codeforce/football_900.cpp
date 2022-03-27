#include<iostream>
using namespace std;

int main() {
    string w;
    cin >> w;
    if ((w.length() <= 100 && w.length() >= 2))
    {
        int count = 0;
        bool team;
        (w.at(0) == '0') ? team == false : team == true;
        for (int i = 0; i < w.length(); i++)
        {
            if (w.at(i) == '0')
            {
                if (team == false)
                {
                    count++;
                }
                else {
                    team = false;
                    count = 1;
                }
            }
            else {
                if (team == true)
                {
                    count++;
                }
                else {
                    team = true;
                    count = 1;
                }
            }
            if (count == 7)
            {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    return 0;
}
