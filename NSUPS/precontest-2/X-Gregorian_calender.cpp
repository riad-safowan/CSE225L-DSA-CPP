#include<bits/stdc++.h>
using namespace std;

// int dayOfWeek(int d, int m, int y)
// {
//     static int t[] = { 0, 3, 2, 5, 0, 3,
//                        5, 1, 4, 6, 2, 4 };
//     y -= m < 3;
//     return (y + y / 4 - y / 100 +
//         y / 400 + t[m - 1] + d) % 7;
// }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int year;
        cin >> year;

        year--;                         
        int day = (year + year / 4 - year / 100 + year / 400 + 1) % 7;
        if (day == 0)
            printf("sunday\n");
        else if (day == 1)
            printf("monday\n");

        else if (day == 2)
            printf("tuesday\n");

        else if (day == 3)
            printf("wednesday\n");

        else if (day == 4)
            printf("thursday\n");

        else if (day == 5)
            printf("friday\n");

        else if (day == 6)
            printf("saturday\n");
    }
}