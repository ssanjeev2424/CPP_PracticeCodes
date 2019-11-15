#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// https://www.spoj.com/problems/HISTOGRA/
// Using Stock Span, in reverse way. i.e maximum number of consecutive days
// just before and after the given day, where price of stock is greater
// than or equal to its price on the given day 

int stockL[100001], stockR[100001], arr[100001], n;
void solve();

int main() {
	fast;
	while(cin>>n) {
		if(!n) break;
		for(int i=1; i<=n; i++) cin>>arr[i];
		solve();
	}
	return 0;
}

void solve() {
	stack<int> stk; stk.push(-1); stk.push(1);
	stockL[1] = 1;
	int idx, ans, cnt;   //cnt stores #elememts need to be popped
	
	for(int i=2; i<=n; i++) {                  // left side
		idx = i - 1, ans = 1, cnt = 0;
		
		while(idx >= 1 && arr[idx] >= arr[i]) {
			ans += stockL[idx];
			idx -= stockL[idx];
			cnt++;
		}
		
		for(int j=0; j<cnt; j++) stk.pop();
		
		stk.push(ans);
		stockL[i] = ans;
	}
	
	while(!stk.empty()) stk.pop();
	
	stk.push(-1); stk.push(1); stockR[n] = 1;
	
	for(int i=n-1; i>=1; i--) {              // right side
		idx = i + 1, ans = 1, cnt = 0;
		
		while(idx <= n && arr[idx] >= arr[i]) {
			ans += stockR[idx];
			idx += stockR[idx];
			cnt++;
		}
		
		for(int j=0; j<cnt; j++) stk.pop();
		
		stk.push(ans);
		stockR[i] = ans;
	}
	
	ll res = 0, temp;
	for(int i=1; i<=n; i++) {
		temp = (stockL[i]+stockR[i]-1) * 1ll * arr[i];  // width * height
		
		if(temp > res) res = temp;
	}
	
	cout<<res<<endl;
}
