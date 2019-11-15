#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> node[100001];
bool visited[100001];

void dfs(int curr) {
	visited[curr] = true;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		if(!visited[child])
			dfs(child);
	}
}

int main() {
	int t,n,e,a,b,ans; cin>>t;
	while(t--) {
		cin>>n>>e;
		if(!e) { cout<<n<<endl; continue; }
		for(int i=0;i<n;i++) {
			node[i].clear();
			visited[i] = false;
		}
		
		ans = 0;
		for(int i=0;i<e;i++) {
			cin>>a>>b;
			node[a].push_back(b);
			node[b].push_back(a);
		}
		
		for(int i=0;i<n;i++)
			if(!visited[i]) {
				ans++;
				dfs(i);
			}
		
		cout<<ans<<endl;
	}
	return 0;
}
