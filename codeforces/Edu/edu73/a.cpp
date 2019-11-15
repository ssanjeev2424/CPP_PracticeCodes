#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> num;
bool solve(vector<int> &, int);

int main() {
	int t,n,x, flag; cin>>t;
	while(t--) {
		cin>>n; flag = 0; num.clear();
		
		for(int i=0; i<n; i++) {
			cin>>x;
			
			if(x == 2048) flag = 1;
			else if(x < 2048)
				num.emplace_back(x);
		}
		
		if(flag) {
			cout<<"YES\n";
			continue;
		}
		
		sort(num.begin(), num.end());
		
		if(solve(num, 2048)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

bool solve(vector<int> &vec, int rem) {
	if(!rem) return true;
	
	if(!vec.size()) return false;
	
	rem -= vec[vec.size()-1];
	vec.pop_back();
	
	return solve(vec, rem);
}
