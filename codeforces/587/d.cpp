#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	lli n, Max = -1, lesser = 0, x; cin>>n; lli arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		
		if(arr[i] > Max) Max = arr[i];
	}
	
	lli GCD = 0;                 // GCD
	for(int i=0; i<n; i++)
		if(arr[i] != Max)
			GCD = __gcd(Max-arr[i], GCD);
	
	
	lli count = 0;
	for(int i=0; i<n; i++)
		if(arr[i] != Max)
			count += (Max - arr[i])/GCD;
	
	cout<<count<<" "<<GCD<<endl;
	
	return 0;
}
