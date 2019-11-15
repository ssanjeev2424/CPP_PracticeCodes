#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/TRT/

ll dp[2001][2001], arr[2001], n;
ll solve(ll, ll);

int main() {
	fast;
	cin>>n;
	for(int i=0; i<n; i++) cin>>arr[i];
	memset(dp, -1, sizeof(dp));
	
	ll ans = solve(0, n-1);
	cout<<ans<<endl;
	return 0;
}

ll solve(ll x, ll y) {
	if(dp[x][y] != -1) return dp[x][y];
	
	if(x == y) return dp[x][y] = ((n - y) + x)*arr[x];
	
	ll ans1 = ((n - y) + x)*arr[x] + solve(x+1, y); //leftmost chosen
	ll ans2 = ((n - y) + x)*arr[y] + solve(x, y-1); //rightmost
	
	return dp[x][y] = max(ans1, ans2);
}
