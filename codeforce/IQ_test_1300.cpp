#include <iostream>
using namespace std;

int a[1001];
int main()
{
    int n, i, num1 = 0, num2 = 0, cnt2 = 0, cnt1 = 0;
    cin >> n;
    for (i = 0;i < n;i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            cnt1++;
            num1 = i;
        }
        else
        {
            cnt2++;
            num2 = i;
        }
    }

    if (cnt1 == 1)
        cout << num1 + 1 << endl;
    if (cnt2 == 1)
        cout << num2 + 1 << endl;

}