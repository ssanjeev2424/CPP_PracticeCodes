#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//https://cp-algorithms.com/data_structures/sparse-table.html

int st[1000001][26], arr[1000001], n;
void makeTable(); int query(int,int);

int main() {
	int t, q, l, r; cin>>t;
	while(t--) {
		cin>>n; 
		for(int i=0; i<n; i++) cin>>arr[i];
		for(int i=0; i<n; i++) 
			for(int j=0; j<26; j++) 
				st[i][j] = 0;
		
		makeTable();
		
		cout<<"Enter no of queries: "; cin>>q;
		for(int i=0; i<q; i++) {
			cin>>l>>r; // we want the sum of arr[l] to arr[r] (inclusive)
			int sum = query(l, r); // 0-indexed 
			if(sum != -1) cout<<sum<<endl;
		}
	}
	return 0;
}

int query(int l, int r) {
	int p = 0, gap = r - l + 1;
	
	int ans = 0;
	for(int i = 22; i>=0; i--) {
		if((1<<i) <= r - l + 1) {
			ans += st[l][i];
			l += (1<<i);
		}
	}
	
	//min(st[l][log(r - l + 1)], st[r - (1<<(log(r - l + 1))][log(r - l + 1)];
	return ans;
}

void makeTable() {
	
	for(int i=0; i<n; i++)
		st[i][0] = arr[i]; // sum from [i,i]
	
	for(int j=1; j<=26; j++)
		for(int i=0; (i + (1 << j)) <= n; i++)
			st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j-1];
}
