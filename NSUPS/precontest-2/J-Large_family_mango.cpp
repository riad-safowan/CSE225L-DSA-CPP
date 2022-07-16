#include<bits/stdc++.h>
using namespace std;

int main() {


    while (true) {
        int numOfMango;
        cin >> numOfMango;
        if (numOfMango == 0) break;

        double p = 0, c = 0, g = 0;

        p = c = numOfMango / 7;
        numOfMango = numOfMango % 7;

        while (numOfMango)
        {
            if (numOfMango <= 1) {
                p += (double)numOfMango / 2;
                numOfMango = 0;
            }
            else if (numOfMango >= 5) {
                c++;
                numOfMango -= 5;
            }
            else {
                g = numOfMango - 1;
                numOfMango -= 1;
            }
        }
        printf("%.1f %.1f %.1f %.1f\n", g, p, p, c);
    }
}