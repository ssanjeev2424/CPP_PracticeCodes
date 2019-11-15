#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int dp[1101][1101][3];

int solve(int h, int a, int x) {
	if(h <= 0 || a <= 0) return 0;
	
	if(dp[h][a][x] != -1) return dp[h][a][x];
	
	int ans = 0;
	
	if(x) ans = 1 + solve(h+3, a+2, 0);
	if(x != 1) ans = max(ans, 1 + solve(h-5, a-10, 1));
	if(x != 2) ans = max(ans, 1 + solve(h-20, a+5, 2));
	
	return dp[h][a][x] = ans; 
}

int main() {
	fast;
	int t, h, a; cin>>t;
	while(t--) {
		cin>>h>>a;
		for(int i=0; i<=h+100; i++)
			for(int j=0; j<=a+100; j++) 
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		
		int ans = solve(h+3 ,a+2, 0);
		cout<<ans<<endl;
	}
	return 0;
}
