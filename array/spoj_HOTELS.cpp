#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/HOTELS/  -->> SLIDING WINDOq GOOD ONE

int main() {
	fast;
	ll n, m, i, j; cin>>n>>m; ll arr[n];
	for(i=0; i<n; i++) cin>>arr[i];
	
	ll ans = 0, temp, x, y;
	
	for(i=0; i<n; i++) {
		ans += arr[i];
		if(ans > m) { 
			ans -= arr[i];
			break;
		}	
	}
	
	if(i == n) {
		cout<<ans<<endl;
		return 0;
	}
	
	temp = ans, j = 0;
	
	while(i < n) {
	
		if(ans == m) break;
				
		for(; i<n && j<i; ) {
			
			temp -= arr[j]; j++;
			
			while(temp + arr[i] <= m && i < n)
				temp += arr[i++];
			
			if(temp > ans) ans = temp;
		}
		
		if(j == i) {
			i++;
			temp = 0;
			while(arr[i] > m && i < n) i++;
			j = i;
			
			if(i == n) break;
			for(; i<n; i++) {
				temp += arr[i];
				if(temp > m) {
					temp -= arr[i];
					break;
				}
			}
			
			if(temp > ans) ans = temp;
			
			if(i == n) break;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
