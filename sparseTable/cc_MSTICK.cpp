#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

double stMax[100001][20], stMin[100001][20], arr[100001];
int Log[100001], n;
void makeMaxTable(); void makeMinTable();
double queryMin(int,int); double queryMax(int,int);

int main() {
	int q, l, r;
	cin>>n; 
	double ans;
	
	Log[1] = 0;
	for(int i=2; i<=n; i++)
		Log[i] = Log[i/2] + 1;
		
	for(int i=0; i<n; i++) cin>>arr[i];
	
	makeMaxTable();
	makeMinTable();
	
	cin>>q;
	for(int i=0; i<q; i++) {
		cin>>l>>r;
		
		ans = 0;
		ans = queryMin(l, r);
		//cout<<"range min: "<<ans<<endl;
		double outside = 0, inside = 0;
		if(l) outside = max(outside, queryMax(0, l-1));
		if(r != n-1) outside = max(outside, queryMax(r+1, n-1));
		//cout<<"outside max: "<<outside<<endl;
		ans = ans + max(outside, (queryMax(l, r) - ans)/(double)2);
		printf("%0.1lf\n",ans);
	}
	
	return 0;
}

double queryMin(int l, int r) {
	int gap = r - l + 1;
	
	int j = Log[gap];

	return min(stMin[l][j], stMin[r - (1<<j) + 1][j]);
}

double queryMax(int l, int r) {
	int gap = r - l + 1;
	
	int j = Log[gap];

	return max(stMax[l][j], stMax[r - (1<<j) + 1][j]);
}

void makeMaxTable() {
	
	for(int i=0; i<n; i++)
		stMax[i][0] = arr[i]; // sum from [i,i]
	
	for(int j=1; j<=20; j++)
		for(int i=0; (i + (1 << j)) <= n; i++)
			stMax[i][j] = max(stMax[i][j-1], stMax[i + (1 << (j - 1))][j-1]);
}

void makeMinTable() {
	
	for(int i=0; i<n; i++)
		stMin[i][0] = arr[i]; // sum from [i,i]
	
	for(int j=1; j<=20; j++)
		for(int i=0; (i + (1 << j)) <= n; i++)
			stMin[i][j] = min(stMin[i][j-1], stMin[i + (1 << (j - 1))][j-1]);
}

