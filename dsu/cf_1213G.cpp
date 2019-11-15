#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//https://codeforces.com/contest/1213/problem/G

vector<int> parent, size;

int find_par(int u) { //returns the parent of node u
	if(u == parent[u]) return u;
	
	return parent[u] = find_par(parent[u]); //path compression
}

lli ans;

lli calc(int noOfNodes) {  //question related
	return (noOfNodes * 1ll * (noOfNodes - 1) / 2); // nC2 
}

void Union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	
	if(size[a] < size[b]) swap(a, b); // 'a' must be bigger one acc to
	                         //our implementation, Union by Rank(size)     
	ans -= calc(size[a]);
	ans -= calc(size[b]);
	
	size[a] += size[b]; // b is joined to a
	
	ans += calc(size[a]);
	
	//cout<<"UNION("<<a<<","<<b<<"): "<<ans<<endl;
	
	parent[b] = a; //as b is joined to a.
}

int main() {
	int n, m; cin>>n>>m; ans = 0;
	
	parent = size = vector<int>(n, 1);
	iota(parent.begin(), parent.end(), 0); //initializes parents 
	//https://www.geeksforgeeks.org/std-iota-in-cpp/
	
	vector<pair<int, pair<int,int> > > e(n-1); //edges
	// weight -->> (u, v)
	
	for(int i=0; i<n-1; i++) { //edges
		cin>>e[i].second.first>>e[i].second.second>>e[i].first;
		
		--e[i].second.first; //as we are using 0-based indexing,
		--e[i].second.second; //but input is 1-index based
	}
	
	/*for(int i=0; i<n-1; i++) { //edges
		cout<<e[i].second.first<<" "<<e[i].second.second<<" "<<e[i].first<<endl;
	}*/
	
	vector<pair<int,int> > query(m); // value of q, its index
	vector<lli> res(m);  // answer to the query, acc to its index
	
	for(int i=0; i<m; i++) {
		cin>>query[i].first;
		query[i].second = i;
	}
	
	sort(e.begin(), e.end());
	sort(query.begin(), query.end());
	
	int idx = 0; 
	for(int i=0; i<m; i++) {
		while(idx < n-1 && e[idx].first <= query[i].first) {
			int u = e[idx].second.first; // end vertices of current edge
			int v = e[idx].second.second;
			
			Union(u, v); //cout<<"****\n";
			idx++;
		}
		//cout<<"^^^^^^^^^^^^^^^^\n";
		res[query[i].second] = ans;
	}
	
	for(int i=0; i<m; i++) cout<<res[i]<<" ";
	cout<<endl;
	
	return 0;
}


















