#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll dp[21][(1<<21)]; int n; ll solve(int, int); int arr[21][21];

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		//memset(dp, -1, sizeof(dp));
		cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0; j<(1<<n); j++) dp[i][j] = -1;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) cin>>arr[i][j];
		
		ll ans = solve(0, 0);
		cout<<ans<<endl;
	}
	return 0;
}

ll solve(int idx, int mask) {
	if(idx == n)
		return mask == ((1<<n)-1);
	
	if(dp[idx][mask] != -1) return dp[idx][mask];
	
	ll ans = 0;
	
	for(int i=0; i<n; i++) {
		if(!arr[idx][i]) continue;
		
		if((mask&(1<<i)) == 0)
			ans += solve(idx+1, mask|(1<<i));
	}
	
	return dp[idx][mask] = ans;
}
