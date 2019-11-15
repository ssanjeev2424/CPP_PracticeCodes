#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/DCOWS/

ll dp[5001][5001], b[5001], c[5001];
ll solve(int,int); ll rem(int,int);
int n, m;

int main() {
	fast;  cin>>n>>m;
	for(int i=0; i<max(m,n); i++)
		for(int j=0; j<max(m,n); j++) dp[i][j] = -1;
	
	for(int i=0; i<n; i++) cin>>b[i];
	for(int i=0; i<m; i++) cin>>c[i];
	
	sort(b, b + n);
	sort(c, c + m);
	
	ll ans = solve(0, 0);
	
	cout<<ans<<endl;
	return 0;
}

ll solve(int idx1, int idx2) {
	if(n - idx1 == m - idx2) return rem(idx1, idx2);
	
	if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
	
	ll ans1 = solve(idx1, idx2+1);
	ll ans2 = abs(b[idx1]-c[idx2]) + solve(idx1+1, idx2+1);
	
	return dp[idx1][idx2] = min(ans1, ans2);
}

ll rem(int idx1, int idx2) {
	ll ans = 0;
	while(idx1 < n)
		ans += abs(b[idx1++] - c[idx2++]);
	
	return ans;
}
