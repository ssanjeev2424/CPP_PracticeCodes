#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<pair<lli,lli> > node[50001]; lli sum;
lli dfs(int,int,lli);

int main() {
	lli t,n,e,a,b,len; cin>>t;
	while(t--) {
		cin>>n; sum = 0;
		for(int i=0; i<=n;i++) node[i].clear();
		
		for(int i=1;i<n;i++) {
			cin>>a>>b>>len;
			node[a].push_back({b, len}); // edge(a,b) -->> weight(len)
			node[b].push_back({a, len});
		}
		
		lli temp = dfs(1,-1, 0);
		
		cout<<sum<<endl;
	}
	return 0;
}

lli dfs(int curr, int par, lli w) {
	lli max1 = 0, max2 = 0, temp;
	
	for(int i=0; i<node[curr].size(); i++) {
		pair<lli,lli> child = node[curr][i];
		
		if(child.first == par) continue;
		
		temp = dfs(child.first, curr, child.second);
		if(temp >= max1) {
			max2 = max1;
			max1 = temp;
		}
		else if(temp > max2)
			max2 = temp;
	}
	
	if(max1 + max(w,max2) > sum) sum = max1 + max(w,max2);
	return w + max1;
}
