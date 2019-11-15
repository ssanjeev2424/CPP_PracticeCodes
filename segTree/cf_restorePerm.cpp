#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// https://codeforces.com/contest/1208/problem/D
// https://codeforces.com/blog/entry/69357
const ll N = 200005;
ll tree[4*N], lazy[4*N];
ll arr[N], ans[N];

void build(ll,ll,ll); ll query(ll,ll,ll); void update(ll,ll,ll,ll,ll,ll);

int main() {
	fast;
	ll n; cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	
	build(1, n, 1);
	//for(int i=1; i<15; i++) cout<<tree[i]<<" "; cout<<endl;
	
	for(int i=1; i<=n; i++) {
		ll idx = query(1, n, 1);
		ans[idx] = i;           
		//cout<<"i: "<<i<<" idx:"<<idx<<endl;
		
		update(1, n, idx, idx, 1, 1e15);
		update(1, n, idx+1, n, 1, -i);
	}
	
	for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

void build(ll l, ll r, ll idx) { // contains the min value for a range
	if(l == r) {                // 0 <= value <= 1e15
		tree[idx] = arr[l];
		lazy[idx] = 0;
		return;
	}
	
	ll mid = (l + r)/2;
	build(l    , mid, 2*idx);
	build(mid+1,   r, 2*idx+1);
	
	lazy[idx] = 0;
	tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}

// returns the index of rightmost 0
// if both the childs are 0, goes to right child as we want the rightmost
// lazy[idx] contains the -ve value which needs to be substracted
ll query(ll l, ll r, ll idx) {
	if(l == r) return l;
	
	if(lazy[idx]) {
		tree[idx] += lazy[idx];
		
		if(l != r) {
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		
		lazy[idx] = 0;
	}
	
	ll mid = (l + r)/2;
	
	if(!(tree[2*idx+1] + lazy[2*idx+1]))
		return query(mid+1, r, 2*idx+1);
	
	return query(l, mid, 2*idx);
}

// updates the range with value val
void update(ll l, ll r, ll lb, ll ub, ll idx, ll val) {
	if(lazy[idx]) {
		tree[idx] += lazy[idx];
		
		if(l != r) {
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		
		lazy[idx] = 0;
	}
	
	if(l > ub || r < lb) return;
	
	if(l >= lb && r <= ub) {
		tree[idx] += val;
		
		if(l != r) {
			lazy[2*idx] += val;
			lazy[2*idx+1] += val;
		}
		return;
	}
	
	ll mid = (l + r)/2;
	update(l, mid, lb, ub, 2*idx, val);
	update(mid+1, r, lb, ub, 2*idx+1, val);
	
	tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}















