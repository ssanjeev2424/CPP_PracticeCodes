#include <bits/stdc++.h>
using namespace std;

string a, b, c;  int dp[101][101][101];
int solve(int,int,int);

int main() {
	int t, x, y, z; cin>>t;
	while(t--) {
	    cin>>x>>y>>z;
	    cin>>a>>b>>c;
	    for(int i=0; i<x; i++)
	        for(int j=0; j<y; j++)
	            for(int k=0; k<z; k++) dp[i][j][k] = -1;
	
	int ans = solve(x-1, y-1, z-1);
	cout<<"Length of LCS: "<<ans<<endl;
	}
	return 0;
}

int solve(int i, int j, int k) {
    if(i == -1 || j == -1 || k == -1) return 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(a[i]==b[j] && b[j]==c[k])
        return dp[i][j][k] = 1 + solve(i-1 ,j-1 ,k-1);
    
    return dp[i][j][k] = max(solve(i-1,j,k), max(solve(i,j-1,k),solve(i,j,k-1)));
}

