#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void bin(ll x) {
	string s = "";
	while(x) {
		if(x&1) s = "1" + s;
		else s = "0" + s;
		
		x >>= 1;
	}
	cout<<"Binary: "<<s<<endl;
}

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		ll l, r, x, one = 1,ans = 0; cin>>l>>r;
		
		ll bits = 0, i; x = r;
		while(x) {
			bits++;
			x >>= 1;
		}
		
		for(i=bits-1; i>=0; i--) {       //mind the overflow, so use 1ll
			if((l&(1ll<<i)) == (r&(1ll<<i))) {
				ans += (ll)(l&(1ll<<i));
				//cout<<i<<" ";
				//cout<<"ans: "; bin(ans);
			}
			else
				break;
		}
		if(i >= 0) ans += (ll)pow(2, i+1) - (ll)1;
		//bin(l); bin(r); bin(ans);
		cout<<ans<<endl;
	}
	return 0;
}

/*
cin>>n;
		int Min = 110, Max = 0, MinIdx, MaxIdx, x;
		for(int i=0; i<n; i++) {
			cin>>x;
			
			if(x > Max) Max = x, MaxIdx = i;
			if(x < Min) Min = x, MinIdx = i;
		}
		
		if(MaxIdx > MinIdx) cout<<Min<<" "<<Max<<endl;
		else cout<<Max<<" "<<Min<<endl;
		
		
		
		ll n; cin>>n;
		
		if(n%10 != 0 && n != 1) {
			cout<<"No\n";
			continue;
		}
		
		int zeroes = 0, twos = 0;
		while(n%10 == 0) {
			zeroes++;
			n /= 10;
		}
		
		if((n&(n-1))) {
			cout<<"No\n";
			continue;
		}
		
		while(n != 1) {
			twos++;
			n >>= 1;
		}
		//cout<<"----------------";
		if(zeroes < twos) cout<<"No\n";
		else cout<<"Yes\n";
*/
