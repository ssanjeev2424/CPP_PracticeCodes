#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

typedef struct Node {
	int mask;
} T;

const int N = 100003;
T tree[4*N]; char arr[N];
int chars, cnt;

void build(int,int,int); void query(int,int,int,int,int);
void update(int,int,int,int,char); 

int main() {
	fast;
	string s; cin>>s; int n = s.length();
	for(int i=1; i<=n; i++)
		arr[i] = s[i-1];
	
	build(1, n, 1);
	
	int q, x, pos, l, r; char c; cin>>q;
	for(int i=0; i<q; i++) {
		cin>>x;
		if(x == 1) {
			cin>>pos; cin>>c;
			update(1, n, 1, pos, c);
		}
		else {
			chars = cnt = 0;
			cin>>l>>r;
			query(1, n, l, r, 1);
			while(chars) {
				cnt++;
				chars &= (chars-1);
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

void build(int l, int r, int idx) {
	if(l == r) {
		tree[idx].mask = (1<<((int)arr[l] - 'a'));
		return;
	}
	
	int mid = (l + r)/2;
	build(l    , mid, 2*idx);
	build(mid+1, r  , 2*idx+1);
	
	tree[idx].mask = tree[2*idx].mask | tree[2*idx+1].mask;	
}

void update(int l, int r, int idx, int pos, char x) {
	if(l == r) {
		if(pos == l)
			tree[idx].mask = (1<<((int)x - 'a'));
		return;
	}
	
	if(l > pos || r < pos) return;
	
	int mid = (l + r)/2;
	update(l, mid, 2*idx, pos, x);
	update(mid+1, r, 2*idx+1, pos, x);
	
	tree[idx].mask = tree[2*idx].mask | tree[2*idx+1].mask;
}

void query(int l, int r, int lb, int ub, int idx) {
	if(l > ub || r < lb) return;
	
	if(lb <= l && r <= ub) {
		chars |= tree[idx].mask;
		return;
	}
	
	int mid = (l + r)/2;
	query(l, mid, lb, ub, 2*idx);
	query(mid+1, r, lb, ub, 2*idx+1);
}
