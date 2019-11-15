#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast; int n;
	cin>>n; string s;
	map<string, int> a, b;
	
	for(int i=0; i<n; i++) {
		cin>>s;
		sort(s.begin(), s.end());
		a[s]++;
	}
	for(int i=0; i<n; i++) {
		cin>>s;
		sort(s.begin(), s.end());
		b[s]++;
	}
	
	int fact[n+1]; fact[0] = 1;
	for(int i=1; i<=n; i++) fact[i] = fact[i-1]*i;
	
	int ans = 1;
	for(auto x: a) {
		if(x.second != b[x.first]) {
			cout<<0<<endl;
			return 0;
		}
		ans *= fact[x.second];
	}
	cout<<ans<<endl;
	return 0;
}
