#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<int> par(200001), siz(200001);

int find_par(int u) {
	if(u == par[u]) return u;
	return par[u] = find_par(par[u]);
}

void Union(int a, int b) {
	a = find_par(a); b = find_par(b);
	
	if(a != b) {
		if(siz[a] < siz[b]) swap(a, b);     
		siz[a] += siz[b]; par[b] = a;
	}
}

int main() {
	//fast;
	int t, n, x; cin>>t;
	while(t--) {
		cin>>n; 
		for(int i=1; i<=n; i++) {
			par[i] = i; siz[i] = 1;
		}
		
		for(int i=1; i<=n; i++) {
			cin>>x;
			Union(x, i);
		}
	
		for(int i=1; i<=n; i++) {
			int p = i;
			while(par[p] != p) p = par[p];
			cout<<siz[p]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
