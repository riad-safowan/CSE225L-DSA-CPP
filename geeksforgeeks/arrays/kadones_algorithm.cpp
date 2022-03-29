#include <iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n) {

    long long sum = arr[0], sumTemp = 0;

    for (int i = 0; i < n; i++) {
        sumTemp += arr[i];
        if (sumTemp > sum)
        {
            sum = sumTemp;
        }

        if (sumTemp < 0)
            sumTemp = 0;
    }
    return sum;
}

int main()
{
    int arr[] = { 1,2,3,-2,5 };
    long long result = maxSubarraySum(arr, 5);
    cout << result;
}