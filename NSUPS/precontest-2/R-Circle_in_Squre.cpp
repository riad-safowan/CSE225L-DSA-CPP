#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        double r;
        cin >> r;
        double full_area = r * r * 4;
        double cicle_area = acos(-1) * r * r;
        printf("Case %d: %.2lf\n",i, (full_area - cicle_area));
    }
}