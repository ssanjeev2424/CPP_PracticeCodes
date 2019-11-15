#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> node[10001];
bool visited[10001]; int dp[10001];

int dfs(int curr) {
	visited[curr] = true;
	
	int ans = 1;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		if(!visited[child])
			ans += dfs(child);
	}
	return ans;
}

int main() {
	int t,n,e,a,b,ans; //cin>>t;
	//while(t--) {
		cin>>n>>e;
		
		ans = 0;
		for(int i=0;i<e;i++) {
			cin>>a>>b;
			node[a].push_back(b);
			//node[b].push_back(a);
		}
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) visited[j] = false;
			ans = max(ans, dfs(i));
		}
		
		cout<<ans<<endl;
	//}
	return 0;
}
