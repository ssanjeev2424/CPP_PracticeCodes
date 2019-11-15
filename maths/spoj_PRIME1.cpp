#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

bool prime(int x) {
	if(x == 1) return false;
	
	for(int i=2; i<=sqrt(x); i++)
		if(x%i == 0) return false;
	return true;
}

int main() {
	fast;
	int t, l, r; cin>>t;
	while(t--) {
		cin>>l>>r;
		for(int i=l; i<=r; i++)
			if(prime(i)) cout<<i<<endl;
		cout<<endl;
	}
	return 0;
}
