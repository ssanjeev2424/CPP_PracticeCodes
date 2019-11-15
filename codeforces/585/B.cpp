#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int arr[200001];
ll negEndingAt[200001]; // #negative subsets ending at index i
ll posEndingAt[200001]; // #positive subsets ending at index i
ll neg, pos;


int main() {
	fast;
	int n, x; cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x;
		if(x > 0) arr[i] = 1;
		else arr[i] = -1;
	}
	
	if(arr[0] > 0) {
		posEndingAt[0] = 1;  negEndingAt[0] = 0;
		pos = 1;  neg = 0;
	}
	else {
		posEndingAt[0] = 0;  negEndingAt[0] = 1;
		pos = 0;  neg = 1;
	}
	
	for(int i=1; i<n; i++) {
	
		if(arr[i] > 0) {
			posEndingAt[i] = posEndingAt[i-1] + 1;
			negEndingAt[i] = negEndingAt[i-1];
		}
		
		else {
			posEndingAt[i] = negEndingAt[i-1];
			negEndingAt[i] = posEndingAt[i-1] + 1;
		}
		
		pos += posEndingAt[i];
		neg += negEndingAt[i];
	}
	
	cout<<neg<<" "<<pos<<endl;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int st[200001][18], arr[200001], n;
void makeTable(); int query(int,int);

int main() {
	int a, neg = 0, pos = 0; cin>>n; 
	for(int i=0; i<n; i++) {
		cin>>a;
		if(a > 0) { arr[i] = 1; pos++; }
		else { arr[i] = -1; neg++; }
	}
	
	makeTable();
	
	for(int gap=1; gap<n; gap++) {
		int i = 0, j = gap;
		
		while(j < n) {
			if(query(i, j) > 0) pos++;
			else neg++;
			
			i++; j++;
		}
	}
	
	cout<<neg<<" "<<pos<<endl;
	
	return 0;
}

int query(int l, int r) {
	int p = 0, gap = r - l + 1;
	
	int ans = 1;
	for(int i = 18; i>=0; i--) {
		if((1<<i) <= r - l + 1) {
			ans *= st[l][i];
			l += (1<<i);
		}
	}
	
	//min(st[l][log(r - l + 1)], st[r - (1<<(log(r - l + 1))][log(r - l + 1)];
	return ans;
}

void makeTable() {
	
	for(int i=0; i<n; i++)
		st[i][0] = arr[i]; // sum from [i,i]
	
	for(int j=1; j<=18; j++)
		for(int i=0; (i + (1 << j)) <= n; i++)
			st[i][j] = st[i][j-1] * st[i + (1 << (j - 1))][j-1];
}
*/
