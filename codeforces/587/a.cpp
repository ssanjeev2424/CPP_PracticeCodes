#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t,n, ans = 0; cin>>n;
	string str; cin>>str;
	
	for(int i=0; i<n; i+=2)
		if(str[i] == str[i+1]) {
			if(str[i] == 'a') str[i] = 'b';
			else str[i] = 'a';
			
			ans++;
		}
	
	cout<<ans<<endl;
	cout<<str<<endl;
	return 0;
}
