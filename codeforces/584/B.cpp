#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int n; cin>>n; string str; cin>>str;
	int a[n], b[n], ans = 0, temp;
	for(int i=0; i<n; i++) cin>>a[i]>>b[i];
	
	for(int t=0; t<1002; t++) {   //time, using tutorial
		temp = 0; // lights at time t
		
		for(int i=0; i<n; i++) { //checking the status of each light
			
			if(t < b[i]) temp += (str[i] - '0');
			else {
				int span = t - (b[i] - 1);
				
				if(span % a[i] == 0) {
					if((span/a[i])&1) temp += 1 - (str[i] - '0');
					else temp += (str[i] - '0');
				}
				else {
					if((span/a[i])&1) temp += (str[i] - '0');
					else temp += 1 - (str[i] - '0');
				}
			}
		}
		
		if(temp > ans) ans = temp;
	}
	
	cout<<ans<<endl;
	return 0;
}
