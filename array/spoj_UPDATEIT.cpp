#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
//https://www.spoj.com/problems/UPDATEIT/

int main() {
	fast;
	int t, n, q, l, r, val, idx; cin>>t;
	while(t--) {
		cin>>n>>q; int arr[n] = {0};
		for(int i=0; i<q; i++) {
			cin>>l>>r>>val;
			arr[l] += val;
			if(r < n - 1) 
				arr[r+1] -= val;
		}
		
		for(int i=1; i<n; i++)
			arr[i] += arr[i-1];  //difference array
			
		cin>>q;
		for(int i=0; i<q; i++) {
			cin>>idx;
			cout<<arr[idx]<<endl;
		}
	}
	return 0;
}
