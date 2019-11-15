#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void solve(ll x) {
	string str = "";
	while(x) {
		if(x%3 == 0) str = "0" + str;
		else if(x%3 == 1) str = "1" + str;
		else str = "2" + str;
		
		x /= 3;
	}
	int i;
	int zero = -1, two = -1, greater = 0;
	for(i=0; i<str.length(); i++) {
		if(str[i] == '0') zero = i;
		if(str[i] == '2') {
			if(zero == -1) greater = 1;
			else two = i;
			
			break;
		}
	}
	
	if(greater) cout<<(ll)pow(3, str.length())<<endl;
	else if(two != -1){
		str[zero] = '1';
		for(i=zero+1; i<str.length(); i++) str[i] = '0';
		
		ll ans = 0, idx = 0;
		for(i=str.length()-1; i>=0; i--, idx++) {
			if(str[i] == '1') ans += (ll)pow(3, idx);
		}
		cout<<ans<<endl;
	}
	else {
		ll ans = 0, idx = 0;
		for(i=str.length()-1; i>=0; i--, idx++) {
			if(str[i] == '1') ans += (ll)pow(3, idx);
		}
		cout<<ans<<endl;
	}
}

int main() {
	fast;
	int t; cin>>t; ll n;
	while(t--) {
		cin>>n;
		solve(n);
	}
	return 0;
}
