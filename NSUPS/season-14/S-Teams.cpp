#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long power(long long B, long long N) {
	if (N == 0) return 1LL;
	if (N == 1) return B;
	
	long long V = power(B, N/2) %MOD;
	V = (V * V) %MOD;
	if (N & 1)
		V = (V * B) %MOD;
	return V;
}

int main(){
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        long long n;
        cin>>n;
        long long r = power(2,n-1)*n %MOD;
        printf("Case #%lld: %lld\n", i, r);
    }
    
}