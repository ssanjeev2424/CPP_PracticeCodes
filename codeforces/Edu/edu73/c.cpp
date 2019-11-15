#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int t, c, m, x, ans; cin>>t;
	while(t--) {
		cin>>c>>m>>x; ans = 0;
		
		if(x >= min(c, m)) {
			cout<<min(c, m)<<endl;
			continue;
		}
		
		ans += x;  // x < min(c, m)
		c -= x; m -= x;
		//cout<<"........"<<ans<<" c:"<<c<<" m: "<<m<<endl;
//**************************************************
		int gap = abs(c - m);
		
		if(gap >= min(c, m)) {
			cout<<ans + min(c, m)<<endl;
			continue;
		}
		
		ans += gap;
		
		if(c > m) {
			c -= 2*gap;
			m -= gap;
		}
		else {
			m -= 2*gap;
			c -= gap;
		}
		
		//cout<<"-----------"<<ans<<" c:"<<c<<" m: "<<m<<endl;
//***************************************************		
		if(c%3 <= 1)    // c == m
			cout<<ans + (c/3)*2<<endl;
		else 
			cout<<ans + (c/3)*2 + 1<<endl;
	}
	return 0;
}
