#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t,n; cin>>t;
	while(t--) {
		cin>>n; int arr[n];
		for(int i=0; i<n; i++) cin>>arr[i];
		sort(arr, arr + n);
		
		int prev = -1, f = 0;
		for(int i=0; i<n; i++) {
			if(arr[i] - prev <= 1) {
				f = 1;
				break;
			}
			prev = arr[i];
		}
		if(f) cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
