#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t, n, x; cin>>t;
	while(t--) {
		cin>>n; int sum = 0;
		for(int i=0; i<n; i++) {
			cin>>x;
			sum += x;
		}
		
		int mean = sum/n;
		if(mean*n == sum) cout<<mean<<endl;
		else cout<<mean+1<<endl;
	}
	return 0;
}
