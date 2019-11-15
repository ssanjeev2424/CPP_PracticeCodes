#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli dp[200001][2], n, pipe, pillar;
lli solve(int,int); string str;

int main() {
	int t; cin>>t;
	while(t--) {
		memset(dp, -1, sizeof(dp));
		cin>>n>>pipe>>pillar; cin>>str;
		
	lli ans = solve(0, 0);
	cout<<ans<<endl;
	}
	return 0;
}

lli solve(int idx, int h) {
	if(idx == n - 2) {
		if(h == 0)
			return 3*pillar + 2*pipe;
		return 5*pillar + 3*pipe;
	}
	
	if(dp[idx][h] != -1) return dp[idx][h];
	
	if(h==1) {
		if(str[idx+1] == '1')
			return dp[idx][h] = 2*pillar + pipe + solve(idx+1, 1);
		
		lli ans1, ans2;
		ans1 = 3*pillar + 2*pipe + solve(idx+1, 0);
		ans2 = 2*pillar + pipe + solve(idx+1, 1);
		return dp[idx][h] = min(ans1, ans2);
	}
	//curr height = 1
	if(str[idx+1] == '0')
		return dp[idx][h] = pillar + pipe + solve(idx+1, 0);
	
	return dp[idx][h] = pillar + 2*pipe + solve(idx+1, 1);
}

/*

int t,buns,beef,chick,costH,costC,ans; cin>>t;
	while(t--) {
		cin>>buns>>beef>>chick; cin>>costH>>costC; ans = 0;
		
		if(costH >= costC) {
			if(beef*2 <= buns) {
				ans += beef*costH;
				buns -= beef*2;
			}
			else {
				int x = buns/2;
				ans += x*costH;
				buns -= x*2;
			}
			
			if(buns > 1) {
				if(chick*2 <= buns) {
				ans += chick*costC;
				buns -= chick*2;
			}
			else {
				int x = buns/2;
				ans += x*costC;
				buns -= x*2;
			}
			}
		}
		else {
			if(chick*2 <= buns) {
				ans += chick*costC;
				buns -= chick*2;
			}
			else {
				int x = buns/2;
				ans += x*costC;
				buns -= x*2;
			}
			if(buns > 1) {
				if(beef*2 <= buns) {
					ans += beef*costH;
					buns -= beef*2;
				}
				else {
					int x = buns/2;
					ans += x*costH;
					buns -= x*2;
				}
			}
		}
		
		cout<<ans<<endl;
	}

int n, m, ans = 0; cin>>n>>m;
	int A[n+1][m+1], B[n+1][m+1] = {{0}}; //cout<<B[1][2];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>A[i][j];
			
	vector<pair<int,int> > moves;
	
	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			if(A[i][j]==1 && A[i+1][j]==1 && A[i][j+1]==1 && A[i+1][j+1]==1) {
				B[i][j] = B[i+1][j] = B[i][j+1] = B[i+1][j+1] = 1;
				moves.push_back({i,j});
				ans++;
			} 
		}
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(A[i][j] != B[i][j]) {
				cout<<-1<<endl;
				return 0;
			}
	cout<<ans<<endl;
	for(auto x: moves)
		cout<<x.first<<" "<<x.second<<endl;


*/
