#include <bits/stdc++.h>
using namespace std;

int parent[100001], n, e;
vector< pair<int, int> > mst;  // final MST

typedef struct Edges {
	int l;
	int r;
	int W;
} E;

E edges[200005];

int cmp(const void *f, const void *s) {
	int x = ((struct Edges*)f)->W;
	int y = ((struct Edges*)s)->W;
	
	return x - y;
}

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
	
	if(a == b) return 0;  // returns 0 if there is a cycle
	
	parent[b] = a;
	return 1;
}

int main() {
	cout<<"Enter #Nodes: "; cin>>n;
	cout<<"Enter #Edges: "; cin>>e;
	cout<<"Enter Edges with corresponding weights....\n";
	
	int temp;
	
	for(int i=0; i<e; i++){
		cin>>edges[i].l>>edges[i].r>>edges[i].W;
	}
	qsort(edges, e, sizeof(E), cmp);
	
	int minWeight = 0;
	for(int i=1; i<=n; i++) // 1-indexed based
		make_set(i);
	
	for(int i=0; i<e; i++) {
		temp = Union(edges[i].l, edges[i].r);
		
		if(temp) {
			minWeight += edges[i].W;
			mst.push_back({edges[i].l, edges[i].r});
		}
	}
	
	cout<<"\n                     ==KRUSKAL'S ALGO==";
	cout<<"\nMST weight: "<<minWeight<<endl<<"Edges are...\n";
	for(int i=0; i<mst.size(); i++)
		cout<<mst[i].first<<" <--> "<<mst[i].second<<endl;
		
	return 0;
}
