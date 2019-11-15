#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> node[10001];
bool visited[10001];

int dfs(int,int);

int main() {
	int n,e,a,b,ans=0;
	cin>>n>>e;
		
	for(int i=0;i<=n;i++)
		visited[i] = false;
	
	for(int i=0;i<e;i++) {
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	ans = dfs(1,-1);
	if(ans == n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}

int dfs(int curr, int par) {
	visited[curr] = true;
	int ans = 1;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		
		if(visited[child] && child != par) return 0;
			
		if(child != par)
			ans += dfs(child, curr);
	}
	return ans;
}
