#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli dp[10000001]; lli solve(lli);

int main() {
	memset(dp, -1, sizeof(dp)); lli x;
	while(cin>>x) // see the input format.. no 't' mentioned
		cout<<solve(x)<<endl;
	return 0;
}

lli solve(lli x) {
	if(x <= 4) return x;
	
	if(x < 10000001 && dp[x] != -1) return dp[x];
	
	if(x < 10000001)
		return dp[x] = max(x, solve(x/2)+solve(x/3)+solve(x/4));
	
	return max(x, solve(x/2)+solve(x/3)+solve(x/4));
}
