#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/BUSYMAN/

bool comp(pair<int,int> &f, pair<int,int> &s) {
	if(f.second == s.second) return f.first >= s.first;
	
	return f.second < s.second;
}

int main() {
	fast;
	int t, n, a, b, maxA, maxB; cin>>t;
	while(t--) {
		vector< pair<int,int> > inter;
		cin>>n; maxA = maxB = -1;
		for(int i=0; i<n; i++) {
			cin>>a>>b;
			inter.push_back({a, b});
			
			if(a > maxA) maxA = a; if(b > maxB) maxB = b;
		}
		
		sort(inter.begin(), inter.end(), comp); //acc to end times..
		
		for(auto x: inter) cout<<"("<<x.first<<","<<x.second<<")"<<endl;
		
		int ans = 0, end = -1;
		
		for(int i=0; i<n; i++) {
			if(end > maxA) break;
			
			if(inter[i].first < end) continue;
			
			ans++; end = inter[i].second;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
