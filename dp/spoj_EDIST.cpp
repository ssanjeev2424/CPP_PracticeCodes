#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/EDIST/

int dp[2001][2001], len1, len2;
string a, b;
int solve(int, int);

int main() {
	fast;
	int t,n; cin>>t;
	while(t--) {
		cin>>a>>b;
		len1 = a.length(), len2 = b.length();
		memset(dp, -1, sizeof(dp));
		
		int dist = solve(0, 0);
		
		cout<<dist<<endl;
	}
	return 0;
}

int solve(int x, int y) {                  
	if(x == len1) return len2 - y;
	
	if(y == len2) return len1 - x;
	
	if(dp[x][y] != -1) return dp[x][y];
	
	if(a[x] == b[y]) return dp[x][y] = solve(x+1, y+1); // both equal
	
	int ans1 = 1 + solve(x+1, y+1); // replace a[x] to b[y]
	int ans2 = 1 + solve(x, y+1);  // delete b[y]
	int ans3 = 1 + solve(x+1, y); // delete a[x]
	
	return dp[x][y] = min(ans1, min(ans2, ans3));
}
