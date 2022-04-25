#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        
        // int num;
        // cin >> num;
        // int sum = 0;
        // bool take = true;
        // while (num > 0)
        // {
        //     if (num < 10)
        //     {
        //         take = true;
        //     }
        //     if (take)
        //     {
        //         sum += num % 10;
        //         take = false;
        //     }
        //     num /= 10;
        // }
        // cout << sum << endl;

        int num;
        cin >> num;
        int last = num % 10;
        int first = num / pow(10, floor(log10(num)));
        cout << (last + first)<<endl;
    }
}
