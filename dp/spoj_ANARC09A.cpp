#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int dp[2001][2001], len, ans;
string inp;
int solve(int,int);

int main() {
	fast;
	int k = 1;
	while(cin>>inp) {
	
		if(inp.length() == 0) {
			cout<<0<<endl;
			continue;
		}
		
		if(inp[0] == '-') break;
		
		len = inp.length();
		for(int i=0; i<len; i++)
			for(int j=0; j<len; j++) dp[i][j] = -1;
		ans = solve(0, 0);
		cout<<k++<<". "<<ans<<endl;
	}
	return 0;
}

int solve(int idx, int open) {
	if(len - idx < open) return (1<<20);
	
	if(idx == len - 1) {
		if(open != 1) return (1<<20);
		
		if(inp[idx] == '}') return 0;
		
		return 1;
	}
	
	if(dp[idx][open] != -1) return dp[idx][open];
	
	if(inp[idx] == '}') {
		if(!open) return dp[idx][open] = 1 + solve(idx+1, 1);
		
		int ans1 = 1 + solve(idx+1, open+1);
		int ans2 = solve(idx+1, open-1);
		return dp[idx][open] = min(ans1, ans2);
	}
	
	//case '{'
	if(!open) return dp[idx][open] = solve(idx+1, 1);
	
	int ans1 = 1 + solve(idx+1, open-1);
	int ans2 = solve(idx+1, open+1);
	return dp[idx][open] = min(ans1, ans2);
}
