#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > node[100001]; //edge from node[i]->node[i][0].first
int parent[100001], n, e;            // of weight node[i][0].second
vector< pair<int, int> > mst;   
bool visited[100001];

typedef struct Edges {
	int l;
	int r;
	int W;
	
	Edges(int a, int b, int c) {
		l = a; r = b;
		W = c;
	}
} E;

struct comp {
	bool operator()(const Edges &x, const Edges &y) const {
		return x.W > y.W;
	}
};

priority_queue<Edges, vector<Edges>, comp> edges; //priority queue to get the min cost edges

void make_set(int u) {
	parent[u] = u;
}

int find_set(int u) {
	if(parent[u] == u)
		return u;
	
	return parent[u] = find_set(parent[u]);
}

int Union(int a, int b) {
	int x = a, y = b;
	
	a = find_set(a);
	b = find_set(b);
	
	if(a == b) return 0;  // returns 0 if a cycle is forming
	
	parent[b] = a;
	return 1;
}

int main() {
	cout<<"Enter #Nodes: "; cin>>n;
	cout<<"Enter #Edges: "; cin>>e;
	cout<<"Enter Edges with corresponding weights....\n";
	
	int temp, a, b, w, x, y, Min = INT_MAX;
	
	for(int i=0; i<e; i++) {
		cin>>a>>b>>w;
		node[a].push_back({b, w});
		node[b].push_back({a, w});
		
		if(w < Min) {
			Min = w;
			x = a; y = b;   // minimum cost edge
		}
	}
	
	int minWeight = 0;
	for(int i=1; i<=n; i++) { // 1-indexed based
		make_set(i);
		visited[i] = false;
	}
	
	edges.push(Edges(x, y, Min)); //pushing the min cost edge in priority Queue
	       
	while(!edges.empty()) {
		Edges curr = edges.top();
		visited[curr.l] = visited[curr.r] = true;
		
		temp = Union(curr.l, curr.r);
		
		if(temp) {
			minWeight += curr.W;
			mst.push_back({curr.l, curr.r});  //adding edge to the final MST
		}
		
		edges.pop(); 
		
		for(int i=0; i<(node[curr.l]).size(); i++) {
			int secNode = (node[curr.l][i]).first;
			int weight = (node[curr.l][i]).second;
			
			if(!visited[secNode])
				edges.push(Edges(curr.l, secNode, weight));
		}
		
		for(int i=0; i<(node[curr.r]).size(); i++) {
			int secNode = (node[curr.r][i]).first;
			int weight = (node[curr.r][i]).second;
			
			if(!visited[secNode])
				edges.push(Edges(curr.r, secNode, weight));
		}
	}
	
	cout<<"\n                  ==PRIM'S ALGO==";
	cout<<"\nMST weight: "<<minWeight<<endl<<"Edges are...\n";
	for(int i=0; i<mst.size(); i++)      
		cout<<mst[i].first<<" <--> "<<mst[i].second<<endl;
		
	return 0;
}
