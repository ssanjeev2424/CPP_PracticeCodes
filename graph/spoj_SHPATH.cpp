#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define inf 1e14
#define ll long long
#define MAXN 200001
bool mark[MAXN];
int n, m, dest, source;
int par[200001];

//https://www.spoj.com/problems/SHPATH/

struct comp {
	bool operator()(const pair<int,int> &x, const pair<int,int> &y) const {
		return x.first > y.first;
	}
};

void dijkstra(int v, vector<ll> &d, vector<vector<pair<int, ll> > > &adj){
	fill(d.begin(), d.end(), inf);
	fill(mark, mark + n + 1, false);
	fill(par, par + n + 1, -1);
	
	d[v] = 0; 
	int u;
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<int,int> > > pq; //or use comp in place of greater
	//pq stores {MinWeightTillNow, Node}
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		if(u == dest) break;
		pq.pop();
		if(mark[u])
			continue;
		
		mark[u] = true;
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				par[p.first] = u;
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
		//for(int i=0; i<n; i++) cout<<d[i]<<" "; cout<<endl;
	}
}

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		vector<vector<pair<int, ll> > > g(n+1);
		unordered_map<string,int> names; string str;
		for(int i=0; i<n; i++) {
			cin>>str; cin>>m;
			names[str] = i+1;
			for(int j=0; j<m; j++) {
				ll u, v, w;
				cin>>v>>w; v--;
				g[i].pb({v, w});
			}
		}
		
		int q; cin>>q; string s1, s2;
		for(int i=0; i<q; i++) {
			cin>>s1>>s2;
			source = names[s1]-1;
			dest = names[s2]-1;   
			vector<ll> d(n+1);
			dijkstra(source, d, g);
			cout<<d[dest]<<endl;
		}
	}
	return 0;
}
