#include<iostream>
#include<vector>
using namespace std;

#define MX 500

// vector<int> howSum(int target, vector<int> numbers) {
//     vector<int> v;
//     if (target == 0) {
//         return v;
//     }
//     if (target < 0) {
//         v.clear();
//         v.push_back(-1);
//         return v;
//     }
//     for (int i = 0; i < numbers.size(); i++)
//     {
//         int remainder = target - numbers.at(i);
//         v = howSum(remainder, numbers);
//         if (v.empty() || v.at(0) != -1)
//         {
//             v.push_back(numbers.at(i));
//             return v;
//         }
//     }

//     v.clear();
//     v.push_back(-1);
//     return v;
// }

vector<int> memo[MX];

vector<int> howSum(int target, vector<int> numbers) {
    vector<int> v;
    if ((v.empty() || memo[target].at(0) != -1) && memo[target] != v) {
        return memo[target];
    }
    if (target == 0) {
        return v;
    }
    if (target < 0) {
        v.clear();
        v.push_back(-1);
        return v;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        int remainder = target - numbers.at(i);
        v = howSum(remainder, numbers);
        if (v.empty() || v.at(0) != -1)
        {
            v.push_back(numbers.at(i));
            memo[target] = v;
            return v;
        }
    }

    v.clear();
    v.push_back(-1);
    memo[target] = v;
    return v;
}

int main() {
    vector<int> nums;

    nums.push_back(30);
    nums.push_back(45);
    nums.push_back(12);

    vector<int> results = howSum(73, nums);
    if (results.at(0) == -1)
    {
        cout << "Not possible" << endl;
    }
    else {
        for (int i = 0; i < results.size(); i++)
        {
            cout << results.at(i) << " ";
        }
    }
    return 0;
}