#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int n, w = 1, ans = 0; cin>>n; // w = width of rectangle..
	
	while(true) {
		if(n/w > w-1) {
			ans += (n/w) - (w-1);
			w++;
		}
		else
			break;
	}
	
	cout<<ans<<endl;
	return 0;
}
