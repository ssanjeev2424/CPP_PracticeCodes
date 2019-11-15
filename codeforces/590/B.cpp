#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int n, k, i, temp; cin>>n>>k; int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	
	set<int> s;
	deque<int> Q;
	
	for(i=0; i<n && Q.size()<k; i++) {
		if(s.find(arr[i]) != s.end()) continue;
		Q.push_front(arr[i]);
		s.insert(arr[i]);
	}
	
	for(; i<n; i++) {
		if(s.find(arr[i]) != s.end()) continue;
		
		temp = Q.back();
		Q.pop_back();
		s.erase(temp);
		
		Q.push_front(arr[i]);
		s.insert(arr[i]);
	}
	
	cout<<Q.size()<<endl;
	for(auto x: Q) cout<<x<<" ";
	cout<<endl;
	return 0;
}
