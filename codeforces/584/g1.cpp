#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define M 1000000007

int arr[200005], freq[200005] = {0}, last[200005];
 
int main() {
	fast;
	int	n, q; cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		freq[arr[i]]++; last[arr[i]] = i;
	}	
 
	int l, r, mx, ans = 0;
	
	for(int i=0; i<n; i++) {
		mx = 0;
		l = i; r = last[arr[i]];
		
		for(int j=i; j<=r; j++) {
			mx = max(mx, freq[arr[j]]);
			r = max(r, last[arr[j]]);
			i = r;
		}
		
		ans += (r - l + 1) - mx;
	}
 
	cout<<ans<<endl;
	return 0;
}

