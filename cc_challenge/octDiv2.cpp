#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll row[100001], col[100001];

int main() {
	fast;
	ll t, n, m, q, x, y, oddR, evenR, oddC, evenC; cin>>t;
	while(t--) {
		cin>>n>>m>>q;
		for(int i=1; i<=n; i++) row[i] = 0;
		for(int i=1; i<=m; i++) col[i] = 0;
		
		oddR = oddC = 0;
		evenR = n, evenC = m;
		
		for(int i=0; i<q; i++) {
			cin>>x>>y;
			row[x]++; col[y]++;
			
			if(row[x]&1) {
				oddR++; evenR--;
			}
			else {
				oddR--; evenR++;
			}
			
			if(col[y]&1) {
				oddC++; evenC--;
			}
			else {
				oddC--; evenC++;
			}
		}
		
		ll ans = (oddC * evenR) + (oddR * evenC);
		cout<<ans<<endl;
	}
	return 0;
}
