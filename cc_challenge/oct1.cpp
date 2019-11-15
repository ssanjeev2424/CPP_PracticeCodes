#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int cnt[1000001];

int main() {
	fast;
	int t, n, Max, x; cin>>t;
	while(t--) {
		cin>>n; Max = 0;
		memset(cnt, 0, sizeof(cnt));
		
		for(int i=0; i<n; i++) {
			cin>>x;
			Max = max(Max, cnt[x]);
			
			for(int j=1; j<=sqrt(x); j++) {
				if(x % j == 0) {
					if(x/j == j)
						cnt[x/j]++;
					else {
						cnt[j]++;
						cnt[x/j]++;
					}
				}
			}
		}
		
		cout<<Max<<endl;
	}
	return 0;
}

/*
ll arr[10001];

int t; cin>>t; ll n, k;
	while(t--) {
		cin>>n>>k;
		for(int i=0; i<n; i++) cin>>arr[i];
		
		ll x = (k / n) % 3ll;
		//cout<<"x: "<<x<<endl;
		if(x == 1) {
			for(int i=0; i<=(n-1)/2; i++) {
				int q = n - 1 - i;
				
				ll temp = arr[i];
				arr[i] = arr[i]^arr[q];
				arr[q] = temp;
			}
		}
		else if(x == 2){
			for(int i=0; i<=(n-1)/2; i++) {
				int q = n - 1 - i;
				
				ll temp = arr[q];
				arr[q] = arr[i]^arr[q];
				arr[i] = temp;
			}
		}
		
		if(k >= n && (n&1)) arr[n/2] = 0; 
		
		//cout<<"Intermediate: ";
		//for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;
		
		k = k % n;
		//cout<<"Final k: "<<k<<endl;
		for(int i=0; i<k; i++) {
				int q = n - 1 - i;
				
				arr[i] = arr[i]^arr[q];
		}
		
		//cout<<"Final: ";
		for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;
	}
*/
