#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int t, n, x, maxDiff, Max, a, b, ans; cin>>t;
	while(t--) {
		cin>>n>>x; maxDiff = Max = ans = 0;
		for(int i=0; i<n; i++) {
			cin>>a>>b;
			if(a - b > maxDiff) maxDiff = a - b;
			
			if(a > Max) Max = a;
		}
		
		if(x <= Max) {
			cout<<1<<endl;
			continue;
		}
		
		if(!maxDiff) {
			cout<<-1<<endl;
			continue;
		}
		
		int rest = (x - Max);
		ans = rest/maxDiff;
		ans = rest % maxDiff == 0 ? ans + 1 : ans + 2;
		
		cout<<ans<<endl;
	} 
	return 0;
}

/*

int t,str,intel,exp; cin>>t;
	while(t--) {
		cin>>str>>intel>>exp;
		
		if(str + exp <= intel) {
			cout<<0<<endl;
			continue;
		}
		
		if(exp == 0) {
			if(str > intel) cout<<1<<endl;
			else cout<<0<<endl; continue;
		}
		
		int ans = 0;
		
		if(str >= intel) {
			int gap = (str + exp) - intel;
			if(gap > 2*exp)
				ans = exp + 1;
			else
				ans = gap/2 + gap%2;
		}
		else { // str < intel
			
			exp -= intel - str + 1; //cout<<exp<<endl;
			str = intel + 1;
			int gap = (str + exp) - intel; //cout<<gap<<endl;
			ans = gap/2 + gap%2;
		}
		cout<<ans<<endl;
	}
*/
