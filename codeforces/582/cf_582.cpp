#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) 

int main() { // #582 Div 3
	fast; int n;
	cin>>n; string a,b; string chosen = "";
	cin>>a>>b;
	string perm[6] = { "bcab", "cabc", "cbac",
					   "abca", "acba", "bacb" }; 
	if(n > 1) {
		for(int i=0;i<6;i++) {
			int j=0;
			while(j<3) {
				if(perm[i].substr(j,2)==a || perm[i].substr(j,2)==b)
					break;
				j++;
			}	
			if(j == 3) {
				chosen = perm[i].substr(0,3);
				break;
			}
		}
	}
	else {
		for(int i=0;i<6;i++) {
			int j=0;
			while(j<2) {
				if(perm[i].substr(j,2)==a || perm[i].substr(j,2)==b)
					break;
				j++;
			}
			if(j == 2) {
				chosen = perm[i].substr(0,3);
				break;
			}
		}
	}
	
	if(!chosen.length()) cout<<"NO\n";
	else {
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<chosen;
		cout<<endl;
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int n, odd = 0, even = 0, x; cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x;
		if(x&1) odd++;
		else even++;
	}
	
	cout<<min(odd,even)<<endl;
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t,n, ans = 0, least; cin>>t;
	while(t--) {
		cin>>n; int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		least = arr[n-1];
		
		for(int i=n-2; i>=0 ; i--) {
			if(arr[i] > least) ans++;
			else if(arr[i] < least) least = arr[i];
		}
	cout<<ans<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t; cin>>t; lli n,m;
	while(t--) {
		cin>>n>>m;
		lli tens = (n/m)/10, oo = (n/m)%10;
		lli sum1 = 0, sum2 = 0;
		int i = 1;
		for(; i<=oo; i++) {
		lli x = (m*i)%10;
		sum1 += x; sum2 += x;
		}
		for(;i<10;i++)
			sum1 += (m*i)%10;
		
		cout<<(sum1*tens + sum2)<<endl;
	}
	return 0;
}
*/
