#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

typedef struct Dur {
	int d;
	int idx;
} D; 

D durab[1001];

int cmp(const void *f, const void *s) {
	int x = ((struct Dur*)f)->d;
	int y = ((struct Dur*)s)->d;
	
	return y - x;
}

int main() {
	fast;
	int t,n, i = 0, ans = 0, x; cin>>n; 
	for(int i=0; i<n; i++) {
		cin>>durab[i].d;
		durab[i].idx = i+1;
	}
	
	qsort(durab, n, sizeof(D), cmp);
	
	for(int i=0; i<n; i++)
		ans += i*durab[i].d + 1;
	
	cout<<ans<<endl;
	for(int i=0; i<n; i++)
		cout<<durab[i].idx<<" ";
	cout<<endl;
	
	return 0;
}
