#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int t, n, idx = 0, odd; //cin>>t;
	//while(t--) {
		cin>>n; 
		string a = "WBW", b = "BBB", c = "WBW";
		char arr[2] = {'W', 'B'};
		
		if(n == 3) {
			cout<<a<<endl<<b<<endl<<c<<endl;
			return 0;
		}
		
		if(n&1) odd = 1;
		else odd = 0;
		
		for(int i=0; i<n; i++) {
		
			for(int j=0; j<n; j++) {
				cout<<arr[idx];
				idx = 1 - idx;
			}
			cout<<endl;
			if(!odd) idx = 1 - idx;
		}
	//}
	return 0;
}
