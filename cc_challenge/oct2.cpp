#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<int> node[100001], nodes[100001];
int parent[100001], size[100001], edges[100001], degree[100001], n;
int repr[100001], evenList[100001], oddList[100001];

int find_set(int u) {
	if(u == parent[u])
		return u;
	
	return parent[u] = find_set(parent[u]);
}

void merge(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	
	if(a != b) {
		if(size[a] < size[b]) swap(a, b);  // a -->> Bigger one
		
		for(auto x: nodes[b])
			nodes[a].push_back(x);
		
		edges[a] += edges[b] + 1;           // #Edges in component
		size[a] += size[b];                 // #Nodes in component
		parent[b] = a;
	}
	else {
		edges[a]++;
	}
}

int main() {
	fast;
	int t, m, a, b; cin>>t;
	while(t--) {
		cin>>n>>m;
		
		if(m&1) {
			for(int i=1; i<=n; i++) {
				node[i].clear(); nodes[i].clear();
				parent[i] = i; size[i] = 1;         // make_set()
				edges[i] = degree[i] = repr[i] = 0;
				oddList[i] = evenList[i] = 0;
				nodes[i].push_back(i);
			}
			
			for(int i=0; i<m; i++) {
				cin>>a>>b;
		
				node[a].push_back(b);
				node[b].push_back(a);
				degree[a]++; degree[b]++;
				merge(a, b);
			}
		}
		else {
			for(int i=0; i<m; i++) cin>>a>>b;
			
			cout<<1<<endl;
			for(int i=1; i<=n; i++) cout<<1<<" "; cout<<endl;
			continue;
		}
		
		int odd = 0, even = 0, oddIdx = 0, evenIdx = 0;
		for(int i=1; i<=n; i++) {
			int x = parent[i];
			if(repr[x]) continue;
			
			repr[x] = 1;
			if(edges[x]&1) {
				odd++;
				oddList[oddIdx++] = x;
			}
			else {
				even++;
				evenList[evenIdx++] = x;
			}
		}
		
		bool flag = false; int setNum, nodeNum;
		
		for(int i=0; i<oddIdx; i++) {
			int x = oddList[i];
			
			// need to find an odd degree node in this component
			
			for(auto v: nodes[x]) {
				if(degree[v]&1) {
					flag = true;
					setNum = x; nodeNum = v;
					break;
				}
			}
			if(flag) break;
		}
		
		if(!flag) {
			int x = oddList[0];
			int f = nodes[x][0];
			int s = node[f][0];
			
			cout<<3<<endl;
			for(int i=1; i<=n; i++) {
				if(i == f) cout<<2<<" ";
				else if(i == s) cout<<3<<" ";
				else cout<<1<<" ";
			}
			cout<<endl; continue;
		}
		
		cout<<2<<endl;
		for(int i=1; i<=n; i++) {
			if(i == nodeNum) cout<<2<<" ";
			else cout<<1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
