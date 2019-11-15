#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// https://codeforces.com/blog/entry/69605

int highest1[200001];

int main() {
	fast;
	int t; cin>>t; string str;
	while(t--) {
		cin>>str;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '1') highest1[i] = i;
			else highest1[i] = (i == 0) ? -1 : highest1[i-1];
		}
		
		int ans = 0;
		
		for(int r=0; r<str.length(); r++) {
			int sum = 0;
			
			for(int l=r; l>=0 && r-l < 19; l--) {
				if(str[l] == '0') continue;
				
				sum += 1<<(r - l);
				
				if(sum <= r - (l == 0 ? -1 : highest1[l-1]))
					ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
