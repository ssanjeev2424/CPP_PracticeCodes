#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/PIGBANK/
//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/


int dp[10001];

int main() {
	fast;
	int t, n, e, f, W; cin>>t;
	while(t--) {
		cin>>e>>f; 
		W = f - e;
		for(int i=1; i<=W; i++) dp[i] = M;
		dp[0] = 0;
		
		cin>>n;
		int p[n], w[n];
		for(int i=0; i<n; i++) cin>>p[i]>>w[i];
		
		for(int i=1; i<=W; i++) {
			for(int j=0; j<n; j++) {
				if(w[j] <= i && dp[i-w[j]] != M)
					dp[i] = min(dp[i], dp[i-w[j]] + p[j]);
			}
		}
		
		if(dp[W] != M) 
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
	return 0;
}
