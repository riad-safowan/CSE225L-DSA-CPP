#include<bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c;
    while (scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        double s = (a + b + c) / 2;
        double k = sqrt((s * (s - a) * (s - b) * (s - c)));
        double r = (a * b * c) / (4 * k);
        double totalRegion = 2 * acos(0) * r * r;
        double yellow = totalRegion - k;
        double r2 = k / s;
        double red = acos(-1) * r2 * r2;
        double blue = k - red;
        printf("%.4lf %.4lf %.4lf\n", yellow, blue, red);
    }
}