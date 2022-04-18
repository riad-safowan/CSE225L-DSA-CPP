#include<iostream>
#include<vector>
using namespace std;

#define MX 500

int memo[MX];

bool canSum(int target, vector<int> numbers) {
    if (target == 0) return true;
    if (target < 0) return false;
    if (memo[target] == 1) return true;
    if (memo[target] == -1) return false;

    for (int i = 0; i < numbers.size(); i++)
    {
        int remainder = target - numbers.at(i);
        if (canSum(remainder, numbers) == true) {
            memo[target] = 1;
            return true;
        }
    }
    memo[target] = -1;
    return false;
}

int main() {
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(8);
    nums.push_back(4);
    cout << canSum(8, nums) << endl;
    cout << canSum(51, nums);
    return 0;
}