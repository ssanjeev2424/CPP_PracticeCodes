#include <bits/stdc++.h>
using namespace std; //dfs, backEdge
#define WHITE 0
#define GREY 1
#define BLACK 2
//https://codeforces.com/contest/1217/problem/D

vector<int> node[5001]; int color[5001], cycle;
vector<pair<int, int> > edges;      //{a, b}
set<pair<int, int> > backEdges;
void dfs(int);
//set<pair<int, pair<int, int> > > s;

int main() {
	int n, m, a, b; cin>>n>>m; cycle = 0;
	memset(color, WHITE, sizeof(color));
	
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		node[a].push_back(b);
		edges.push_back({a, b});
	}
	
	for(int i=1; i<=n; i++)
		if(color[i] == WHITE)
			dfs(i);
	
	cout<<(1+cycle)<<endl;
	
	if(cycle) {
		for(int i=0; i<m; i++) {
			if(backEdges.find(edges[i]) == backEdges.end()) cout<<1<<" ";
			else cout<<2<<" ";
		}
		cout<<endl;
	}
	else
		for(int i=1;i<=m;i++) cout<<1<<" \n"[i == m];
	
	return 0;
}

void dfs(int curr) {
	color[curr] = GREY;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		
		if(color[child] == WHITE)
			dfs(child);
		
		else if(color[child] == GREY) {
			cycle = 1;
			//cout<<"curr: "<<curr<<" ***  child: "<<child<<endl;
			backEdges.insert({curr, child});
		}
	}
	color[curr] = BLACK;
}
