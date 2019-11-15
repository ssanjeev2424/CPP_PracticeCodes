#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<int> node[500003];
ll val[500003] = {0};
void dfs(int,int,ll);

int main() {
	//fast;
	ll n, q, a, b, x, y; char c; cin>>n>>q;
	for(int i=1; i<n; i++) {
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i=1; i<=n; i++) cin>>val[i];
	
	for(int i=0; i<q; i++) {
		dfs(1, -1, 0);
		
		cin>>c;
		if(c == '?') {
			cin>>x;
			cout<<val[x]<<endl;
		}
		else {
			cin>>x>>y;
			val[x] += y;
		}
		
		//cout<<"sec #"<<i<<": ";
		//for(int i=1; i<=n; i++) cout<<val[i]<<" \n"[i==n];
	}
	return 0;
}

void dfs(int curr, int par, ll x) {
	if(!node[curr].size() || (node[curr].size()==1 && node[curr][0]==par)){
		val[curr] += x;
		return;
	}
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		
		if(child != par)
			dfs(child, curr, val[curr]);
	}
	
	val[curr] = x;
}
