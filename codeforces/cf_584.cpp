#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> num; int n, ok;
void solve(int);

int main() {
	int t; cin>>t;
	while(t--) {
		num.clear(); ok = 0;
		cin>>n; string str; cin>>str;
		for(int i=0; i<n; i++)
			num.push_back(str[i]-'0');
		
		for(int i=0; i<=9; i++) {
			if(ok) break;
			
			solve(i);
		}
		
		if(!ok) cout<<"-"<<endl;
	}
	return 0;
}

void solve(int dgt) {               // using tutorial
	bool greater1 = false;
	
	vector<int> seq;
	int d1, d2 = dgt;
	
	for(int i=0; i<n; i++) {
		if(num[i] < dgt)
			seq.push_back(1);
		
		else if(num[i] > dgt) {
			if(!greater1) greater1 = true;
			
			seq.push_back(2);
		}
		
		else {
			if(greater1) seq.push_back(1);
			else seq.push_back(2);
		}
	}
	
	int x = 0, flag = 1;
	
	for(int i=0; i<n; i++) { // for color 1
		if(seq[i] == 2) continue;
		
		if(num[i] >= x) x = num[i];
		else {
			flag = 0;
			break;
		}
	}
	
	if(!flag) return;
	
	for(int i=0; i<n; i++) { // for color 2
		if(seq[i] == 1) continue;
		
		if(num[i] >= x) x = num[i];
		else {
			flag = 0;
			break;
		}
	}
	
	if(!flag) return;
	
	ok = 1;
	for(auto i:seq)
		cout<<i;
	cout<<endl;
}

/*

int n, ans = 0; cin>>n;
	int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];
	bool colored[n] = {false};
	sort(arr, arr + n);
	
	for(int i=0; i<n; i++) {
		if(!colored[i]) {
			ans++;
			colored[i] = true;
			for(int j = i+1; j<n; j++)
				if(arr[j]%arr[i] == 0) colored[j] = true;
		}
	}
	
	cout<<ans<<endl;
*/
