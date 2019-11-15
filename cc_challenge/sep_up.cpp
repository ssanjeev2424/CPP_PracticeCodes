#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

lli cnt[8001], dp[1010][1010]; vector<lli> freq;

int main() {
	fast;
	int k, n, x; cin>>n>>k;
	memset(cnt, 0, sizeof(cnt));
	
	for(int i=0; i<n; i++) {
		cin>>x;
		cnt[x]++;
	}
	
	freq.push_back(0); //dummy at the beginning to adjust index
	for(int i=2; i<8000; i++)
		if(cnt[i])
			freq.push_back(cnt[i]);
	
	int len = freq.size(); // number of distinct numbers
	k = min(k, len-1); 
	//memset(dp, 0, sizeof(dp));
	
/*
dp[i][0]=1  ,∀i ≥ 0

dp[i][j]=dp[i−1][j] + dp[i−1][j−1]*cnt[i]

Here, dp[i][j] indicates the number of valid subsets of size j we can pick considering only array values  ≤i
*/
	
	dp[0][0] = 1;
	for(int i=1; i<=k; i++) dp[0][i] = 0;
	
	for(int i=1; i<freq.size(); i++) {
		dp[i][0] = 1;
		
		for(int j=1; j<=k; j++) {
			dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1]*(freq[i]%M))%M) % M;
		}
	}
	
	int ans = 0;
	for(int i=0; i<=k; i++)
		ans = (ans + dp[freq.size()-1][i])%M;
	
	cout<<ans<<endl;
	return 0;
}
