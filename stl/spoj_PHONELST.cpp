#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	//fast;
	int t, n, x, y; cin>>t; string str;
	while(t--) {
		cin>>n; bool ok = true;
		unordered_set<string> s; string arr[n];
		
		for(int i=0; i<n; i++) cin>>arr[i];
		
		sort(arr, arr + n);
		
		for(int i=0; i<n; i++) {
			str = "";
			
			if(ok) {
				for(int j=0; j<arr[i].length(); j++) {
					str += arr[i][j];
					
					if(s.count(str)) {
						ok = false;
						break;
					}
				}	
				s.insert(arr[i]);
			}
		}
		
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
