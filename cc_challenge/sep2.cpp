#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define MAXM 1000001

//https://www.codechef.com/problems/FUZZYLIN, very nice question
// used sparse table & binary search

int st[100001][18], arr[100001], Log[100001], temp, n; 
lli K[MAXM];
void makeTable(); int queryGCD(int,int); int gcd(int, int);
void addToMultiples(int, lli); int binSearch(int,int,int); void solve(); 

int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>arr[i];

//*****************Log Calculation*****************	
	Log[1] = 0;
	for(int i=2; i<=n; i++)
		Log[i] = Log[i/2] + 1;
//*************************************************	
	memset(K, 0, sizeof(K)); //will store it for every k
	
	makeTable();
	solve();
	
	int q, k; cin>>q;
	for(int i=0; i<q; i++) {
		cin>>k;
		cout<<K[k]<<endl;
	}
	return 0;
}

void solve() {

	for(int l=0; l<n; l++) {
		for(int r=l; r<n; r++) {
			temp = queryGCD(l, r);
			
			if(temp >= MAXM) continue;//as k < MAXM, won't affect any query
			
			lli cnt = binSearch(r+1, 1, n-1-r); //how much to the right,
			                        // gcd remains the same
			K[temp] += (lli)(1 + cnt);//as gcd remains same till this point
			r += cnt; //move the pointer
		}
	}
	
	for(int i=MAXM-1; i>=1; i--) {
		if(K[i])        //add the answer to all its multiples as well
			addToMultiples(i, K[i]); // ex: if 4 divides k, 2 will as well
	}    // so if k=4 is asked, all its divisor values should be added
}

int binSearch(int start, int l, int r) {
	
	int ans = 0, mid;
	
	while(l <= r) {
	
		mid = (l + r)/2;
		
		int gcd1 = queryGCD(start, start+mid-1);
		
		int gcd2 = gcd(gcd1, temp);
		
		if(gcd2 == temp) {
			ans = mid;  // ans till now, satisfied till this point
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	
	return ans;
}

void addToMultiples(int num, lli val) {

	for(int i=2*num; i<MAXM; i+=num)
		K[i] += val;
}

void makeTable() {
	for(int i=0; i<n; i++)
		st[i][0] = arr[i];
	
	for(int j=1; j<=17; j++)
		for(int i=0; (i + (1<<j)) <= n; i++) 
			st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int queryGCD(int l, int r) {
	int gap = r - l + 1;
	
	int j = Log[gap];
	
	return gcd(st[l][j], st[r - (1<<j) + 1][j]);
}

int gcd(int a, int b) {
	if(b == 0) return a;
	
	return gcd(b, a%b);
}
