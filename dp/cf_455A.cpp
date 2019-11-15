#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int n;
lli arr[100001], dp[100001][2], cnt[100001];
lli solve(int,int);

int main() {
	cin>>n; 
	
	for(int i=0; i<100001; i++) {
		cnt[i] = 0;
		dp[i][0] = dp[i][1] = -1;
	}
	
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		cnt[arr[i]]++;
	}
		
	sort(arr, arr+n);
	
	lli ans = max(solve(n-1, 0), solve(n-1, 1));
	cout<<ans<<endl;
	
	return 0;
}

lli solve(int idx, int higher) {
	if(idx < 0) return 0;
	
	if(dp[idx][higher] != -1) return dp[idx][higher];
	
	if(higher)  {
		if(idx != n-1 && arr[idx+1] == arr[idx] + 1)
			return dp[idx][higher] = solve(idx - cnt[arr[idx]], 0);
	}
	
	lli ans1 = cnt[arr[idx]]*arr[idx] + solve(idx - cnt[arr[idx]], 1);
	lli ans2 = solve(idx - cnt[arr[idx]], 0);
	
	return dp[idx][higher] = max(ans1, ans2);
}
