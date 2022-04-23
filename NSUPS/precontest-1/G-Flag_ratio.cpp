#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        double h = l * 6.0 / 10;
        double r = l * 2.0 / 10;
        double r_area = acos(-1) * r * r;
        double g_area = l * h - r_area;
        printf("%.2lf %.2lf\n", r_area, g_area);
    }
}