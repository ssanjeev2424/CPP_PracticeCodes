#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://codeforces.com/contest/1249
//codeforces.com/blog/entry/70779

int main() {
	fast;
	int n, k; cin>>n>>k;
	vector<pair<int,int> > seg(n); int cnt[202] = {0};
	for(int i=0; i<n; i++) {
		cin>>seg[i].first>>seg[i].second;
		cnt[seg[i].first]++; cnt[seg[i].second+1]--;
	}
	
	for(int i=1; i<201; i++) cnt[i] += cnt[i-1];
	
	vector<int> ans(n);
	for(int i=1; i<201; i++) {
		while(cnt[i] > k) {
			int pos = -1;
			for(int j=0; j<n; j++) {
				if(!ans[j] && (seg[j].first <= i && i <= seg[j].second) && (pos == -1 || seg[j].second > seg[pos].second))
					pos = j;
			}
			
			for(int j=seg[pos].first; j<=seg[pos].second; j++)
				cnt[j]--;
			
			ans[pos] = 1;
		}
	}
	
	cout<<accumulate(ans.begin(), ans.end(), 0)<<endl;
	for(int i=0; i<n; i++) if(ans[i]) cout<<i+1<<" "; cout<<endl;
	return 0;
}
