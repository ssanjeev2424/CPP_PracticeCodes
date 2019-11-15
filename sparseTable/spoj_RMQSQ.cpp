#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int st[100001][20], arr[100001], Log[100001], n;
void makeTable(); int queryMin(int,int); 

int main() {
	int q, l, r;

	
	cin>>n; 
	
	Log[1] = 0;
	for(int i=2; i<=n; i++) // log pre-calculation
		Log[i] = Log[i/2] + 1;
		
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++) 
		for(int j=0; j<21; j++) 
			st[i][j] = 0;
	
	makeTable();
	
	cin>>q;
	for(int i=0; i<q; i++) {
		cin>>l>>r;
		int Min = queryMin(l, r); // 0-indexed 
		cout<<Min<<endl;
	}
	
	return 0;
}
// for min of a range, we can do it in O(1), divide the array in two parts of highest power of 2. ex: for n=7, find min(min of(0,3), min of(3,6))

int queryMin(int l, int r) {
	int gap = r - l + 1;
	
	int j = Log[gap];

	return min(st[l][j], st[r - (1<<j) + 1][j]);
}

void makeTable() {
	
	for(int i=0; i<n; i++)
		st[i][0] = arr[i]; // sum from [i,i]
	
	for(int j=1; j<=20; j++)
		for(int i=0; (i + (1 << j)) <= n; i++)
			st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
}

