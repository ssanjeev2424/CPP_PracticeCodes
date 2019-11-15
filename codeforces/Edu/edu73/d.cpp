#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

lli dp[300005][3], h[300005], b[300005], n;
lli solve(int, lli);

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<=n; i++) for(int j=0; j<3; j++) dp[i][j] = -1;
		for(int i=0; i<n; i++)	cin>>h[i]>>b[i];
		
		lli ans = 2e18;
		for(lli i=0; i<3; i++)
			ans = min(ans, i*b[0] + solve(1, i));
		
		cout<<ans<<endl;
	}
	return 0;
}

lli solve(int idx, lli prevInc) {
	if(idx == n) return 0;
	
	if(dp[idx][prevInc] != -1) return dp[idx][prevInc];
	
	lli ans = 2e18;
	
	for(lli i=0; i<3; i++)
		if(h[idx-1]+prevInc != h[idx] + i)
			ans = min(ans, i*b[idx] + solve(idx+1, i));
	
	return dp[idx][prevInc] = ans;
}

















