#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/BYTESM2/

int dp[101][101], arr[101][101], h, w;
int solve(int,int);

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		cin>>h>>w;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++) cin>>arr[i][j];
		
		if(w == 1) {
			int ans = 0;
			for(int i=0; i<h; i++) ans += arr[i][0];
			cout<<ans<<endl;
			continue;
		}
		
		memset(dp, -1, sizeof(dp));
		
		int ans = 0;
		for(int i=0; i<w; i++)
			ans = max(ans, solve(0, i));
		
		cout<<ans<<endl;
	}
	return 0;
}

int solve(int i, int j) {
	if(i == h) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(j == w - 1) {
		
		int ans1 = arr[i][j] + solve(i+1, j-1);
		int ans2 = arr[i][j] + solve(i+1, j);
		return dp[i][j] = max(ans1, ans2);
	}
	
	if(j == 0) {
		
		int ans1 = arr[i][j] + solve(i+1, j);
		int ans2 = arr[i][j] + solve(i+1, j+1);
		return dp[i][j] = max(ans1, ans2);
	}
	
	return dp[i][j] = arr[i][j] + max(solve(i+1,j), max(solve(i+1, j+1), solve(i+1, j-1)));
}
