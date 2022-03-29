#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{
    long long sum = 0;
    int p1 = 1, p2=0;
    vector<int> v;
    for (int i = 0; i <= n; i++) {
     
        if (sum == s) {
            v.push_back(p1);
            v.push_back(p2);
            return v;
        }
        else if (sum > s) {
            sum -= arr[p1 - 1];
            p1++;
            i--;
        }
        else if (sum < s) {
            sum += arr[i];
            p2 = i + 1;
        }
           cout <<i<<" "<< sum << " " << p1 << " " << p2<<endl;
    }

    v.push_back(-1);
    return v;
}

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,100,1 };
    vector<int> result = subarraySum(arr, 11, 109);
    cout << result.at(0) << " " << result.at(1);
}