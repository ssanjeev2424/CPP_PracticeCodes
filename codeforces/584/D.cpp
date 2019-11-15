#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//https://codeforces.com/contest/1209/problem/D

vector<int> node[200001];
bool visited[200001];

int dfs(int curr) { // returns the size of connected component
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
	int n, k, a, b, nodes = 0; cin>>n>>k;
	memset(visited, true, sizeof(visited));
	
	for(int i=1; i<=k; i++) {
		cin>>a>>b;
		
		node[a].push_back(b);
		node[b].push_back(a);
		
		if(visited[a]) {
			visited[a] = false;
			//nodes++;
		}
		
		if(visited[b]) {
			visited[b] = false;
			//nodes++;
		}
	}
	
	//nodes = min(nodes, k);
	//1 connected component of size x can be used for x-1 guests, arranged in some order we don't care
	
	int ans = 0;
	for(int i=1; i<=n; i++)
		if(!visited[i]) {
			int temp = dfs(i);
			ans += temp - 1;   
	    }                           
	cout<<(k - ans)<<endl; // "ans" guests can be satisfied

	return 0;
}

/*
 Solution using DSU..
 
 int p[100005];
int n;
int ans;
 
int find(int u) {
	if(p[u] == u)
		return u;
	return p[u] = find(p[u]);
}
 
void merge(int u, int v) {
	int pu = find(u);
	int pv = find(v);
	
// Think....
	
	if(pu != pv) {
		p[pu] = pv;
	} else {
		ans++;
	}
}
int main() {
	fast;
	int k;
	cin>>n>>k;
	int u, v;
	
	for(int i=0; i<=n; i++)
		p[i] = i;
	
	ans = 0;
	for(int i=0; i<k; i++){
		cin>>u>>v;
		merge(u, v);
	}
 
	cout<<ans<<endl;	
	return 0;
}

*/
