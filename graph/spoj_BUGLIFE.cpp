#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

// graph bicoloring..no two adjacents should be same
//https://www.geeksforgeeks.org/bipartite-graph/

vector<int> node[2001];
int type[2001], ok;
void dfs(int);

int main() {
	int t, n, inter, a, b; cin>>t;
	for(int sc=1; sc<=t; sc++) {
		cin>>n>>inter; ok = 1;
		
		for(int i=1;i<=n;i++) {
			node[i].clear();
			type[i] = -1;
		}
		
		for(int i=0; i<inter; i++) {
			cin>>a>>b;
			node[a].push_back(b);
			node[b].push_back(a);
		}
		
		for(int i=1; i<=n; i++) {
			if(!ok) break;
			
			if(type[i] == -1) {
				type[i] = 0;
				dfs(i);
			}
		}
		
		cout<<"Scenario #"<<sc<<":"<<endl;
		if(ok) cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;
		//for(int i=1; i<=n; i++) cout<<type[i]<<" "; cout<<endl;
	}
	return 0;
}

void dfs(int curr) {
	if(!ok) return;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		
		if(type[child] == -1) {
			type[child] = !type[curr];
			dfs(child);
		}
		else if(type[child] == type[curr]) {
			ok = 0;
			break;
		}
	}
}
