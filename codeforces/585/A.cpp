#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int a1, a2, k1, k2, n, Min = 0, Max = 0;
	cin>>a1>>a2>>k1>>k2>>n;
	
	int noElimination = (k1 - 1)*a1 + (k2 - 1)*a2;
	if(n <= noElimination) cout<<0<<" ";
	else cout<<(n - noElimination)<<" ";
	
	if(k1 > k2) { //k1 should be the lesser one
		swap(a1, a2);
		swap(k1, k2);
	}
	
	if(k1*a1 >= n) cout<<n/k1<<endl;
	else {
		n -= a1*k1;
		cout<<(a1 + n/k2)<<endl;
	}
	return 0;
}
