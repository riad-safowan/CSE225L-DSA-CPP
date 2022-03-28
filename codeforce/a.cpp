#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr){
    int size = arr.size();
    while(--size){
        cout<<size<<endl;
        if(abs(arr[0] - arr[1]) <= 1){
            int temp = arr[0] + arr[1];
            arr.erase(arr.begin(),arr.begin()+2);
            arr.insert(upper_bound(arr.begin(), arr.end(), temp),temp);
            size = arr.size();
        }else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
            
        sort(arr.begin(),arr.end());
        solve(arr);
        cout<<endl;
    }
    return 0;
}