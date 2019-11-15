#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int found, n, m, arr[501][501];
void solve(int, int, vector<int> v);

int main() {
	found = 0;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin>>arr[i][j];
	
	vector<int> v;
	solve(0, 0, v);
	
	if(!found) cout<<"NIE"<<endl;
	return 0;
}

void solve(int i, int ans, vector<int> vec) {
	if(found) return;
	
	if(i == n && ans) {
		found = 1;
		
		cout<<"TAK"<<endl;
		for(auto x: vec)
			cout<<x<<" ";
		cout<<endl;
		
		return;
	}
	
	if(i == n) return;
	
	for(int j=0; j<m; j++) {
		vec.push_back(j+1);
		solve(i+1, ans^arr[i][j], vec);
		vec.pop_back();
	} 
}
