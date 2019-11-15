#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define inf 1e14
#define ll long long
#define MAXN 200001
bool mark[MAXN];
int n, m;
int par[200001];

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
	
	pq.push({d[v], v}); 			        // source node
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(mark[u]) 			           //min distance already found
			continue;
		
		mark[u] = true;
		for(auto p : adj[u]) 				//adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				par[p.first] = u;
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}

void path(int x) {
	if(x == 0) {
		cout<<1<<" ";
		return;
	}
	path(par[x]);
	cout<<x+1<<" ";
}
int main() {
	cout<<"Enter #Nodes and #Edges: ";
	cin>>n>>m;
	vector<vector<pair<int, ll> > > g(n+1); // node[a].pb({b,w}); --->> " weight of a<-->b is w "
	cout<<"Enter Edges with corresponding weights..(1-indexed)\n";
	for(int i=0; i<m; i++) {
		ll u, v, w;
		cin>>u>>v>>w;
		u--;v--;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	vector<ll> d(n+1);
	dijkstra(0, d, g);
	
	cout<<"Shortest Path from node 1 to node "<<n<<": ";
	if(par[n-1] == -1) 
		cout<<-1<<endl;
	else {
	path(n-1); cout<<endl;
	}
	cout<<"Shortest Distance of all the nodes from node 1: [node-->>distance]\n";
	for(int i=0; i<n; i++) cout<<i+1<<"-->>"<<d[i]<<endl;
	return 0;
}
