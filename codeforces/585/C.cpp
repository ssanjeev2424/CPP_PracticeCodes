#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

// {s[i], t[i]} convention
// {a,b} can be swapped with another {a,b}, in 1 swap, both will get mapped
// similarly {b,a} can be swapped with another {b,a}
// if one {a,b} and one {b,a} is left, it will take 2 swaps to solve it

int main() {
	int n, arr[2], swaps = 0; cin>>n;
	string s, t; cin>>s>>t; arr[0] = arr[1] = 0;
	
	vector<int> ab, ba, ans;
	
	for(int i=0; i<n; i++) {
		arr[s[i]-'a']++;
		arr[t[i]-'a']++;
	}
	
	if(n == 1) {
		if(s[0] == t[0]) cout<<0<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	//cout<<"a: "<<arr[0]<<" b:"<<arr[1]<<endl;
	if((arr[0]&1)) { // #a's is odd
		cout<<-1<<endl;
		return 0;
	}
	
	for(int i=0; i<n; i++) {
		if(s[i] == t[i]) continue;
		
		if(s[i] == 'a') ab.emplace_back(i+1);
		else ba.emplace_back(i+1);
	}
	vector<int>::iterator it;
	while(ab.size() >= 2) {
		swaps++;
		ans.emplace_back(ab[0]);
		ans.emplace_back(ab[1]);
		
		it = ab.begin(); ab.erase(it, it+2);
	}
	
	while(ba.size() >= 2) {
		swaps++;
		ans.emplace_back(ba[0]);
		ans.emplace_back(ba[1]);
		
		it = ba.begin(); ba.erase(it, it+2);
	}
	
	if(ab.size()) {
		swaps += 2;
		ans.emplace_back(ab[0]);
		ans.emplace_back(ab[0]);
		
		ans.emplace_back(ab[0]);
		ans.emplace_back(ba[0]);
	}
	
	cout<<swaps<<endl;
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
		cout<<ans[++i]<<endl;
	}
	
	return 0;
}
