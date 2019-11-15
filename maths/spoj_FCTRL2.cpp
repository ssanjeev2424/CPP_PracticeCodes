#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/FCTRL2/
//https://www.geeksforgeeks.org/factorial-large-number/

int arr[200], num[3];

int main() {
	fast;
	int t, n, idx, x, j, carry; cin>>t;
	while(t--) {
		cin>>n;
		
		memset(arr, 0, sizeof(arr));
		arr[0] = 1; idx = 1;
		
		for(int i=2; i<=n; i++) {
			carry = 0;
			
			for(j=0; j<idx; j++) {
				x = arr[j]*i + carry;
				
				arr[j] = x%10;
				carry = x/10;
			}
			
			while(carry) {
				arr[idx++] = carry%10;
				carry /= 10;
			}
		}
		
		for(int i=idx-1; i>=0; i--) cout<<arr[i];
		cout<<endl;
	}
	return 0;
}
