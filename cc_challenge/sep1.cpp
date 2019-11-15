#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007

lli nCr[52][52]; lli binCoeff(int,int);
void multiply(lli F[2][2], lli M[2][2]);
void power(lli F[2][2], lli n);

lli fib(lli n) {
	lli F[2][2] = { {1,1}, {1,0} };
	if(n == 0) return 0;
	
	power(F, n - 1);
	return F[0][0];
}

int main() {
	double n, k, x; double ans = 1, temp; cin>>n>>k; 
	for(int i=0; i<n; i++) cin>>x; // for subtask 1
	
	for(double i=k; i>=1; i--) {
		temp = (1 + ((n - (i-1))/i)*ans);
		ans = temp;
		//cout<<"i: "<<i<<" ans: "<<ans<<endl;
	}
	lli ans2 = (lli)ans;
	cout<<ans2%MOD<<endl;
	return 0;
}

lli binCoeff(int n, int r) {
	if(r > n/2) r = n - r;
	
	if(r == 0) return nCr[n][r] = 1;
	
	if(nCr[n][r] != -1) return nCr[n][r];
	
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=min(i,r); j++) {
			if(i==0 || j==i)
				nCr[i][j] = 1;
			else
				nCr[i][j] = binCoeff(i-1,j-1) + binCoeff(i-1,j);
		}
	}
	return nCr[n][r];
}

void multiply(lli F[2][2], lli M[2][2]) {

	lli x =  (F[0][0]*M[0][0])%10 + (F[0][1]*M[1][0])%10; 
	lli y =  (F[0][0]*M[0][1])%10 + (F[0][1]*M[1][1])%10; 
	lli z =  (F[1][0]*M[0][0])%10 + (F[1][1]*M[1][0])%10; 
	lli w =  (F[1][0]*M[0][1])%10 + (F[1][1]*M[1][1])%10; 
	  
	F[0][0] = x%10; 
	F[0][1] = y%10; 
	F[1][0] = z%10; 
	F[1][1] = w%10; 
} 

void power(lli F[2][2], lli n) {
	
	if(n == 0 || n == 1) return;
	
	lli M[2][2] = {{1,1},{1,0}}; 

	power(F, n/2);
    multiply(F, F);
    
    if(n&1) multiply(F, M); 
} 

/*

int t, n, k; cin>>t;
	memset(nCr, -1, sizeof(nCr));
	
	while(t--) {
		cin>>n>>k; int arr[n]; lli ans = 0;
		for(int i=0; i<n; i++) cin>>arr[i];
		sort(arr, arr+n);
		
		int x = arr[k-1], inside = 0, outside = 0;
		
		for(int i=k; i<n; i++) {
			if(arr[i] == x) outside++;
			else break;
		}
		
		if(!outside) {
			cout<<1<<endl;
			continue;
		}
		
		for(int i = k-1; i>=0; i--) {
			if(arr[i] == x) inside++;
			else break;
		}
		
		int r = min(inside, outside);
		
		for(int i=0; i<=r; i++)
			ans += binCoeff(inside,i)*binCoeff(outside,i);
		
		cout<<ans<<endl;
	}
	
	int t; cin>>t;
	while(t--) {
		lli n, x; cin>>n;
		
		int bits = 0; x = n;
		while(x) {
			bits++;
			x = x>>1;
		}
		lli termNumber = pow(2, bits-1); termNumber--;
		lli fibo = fib(termNumber);
		//cout<<"Fib: "<<fibo<<" ans: ";
		cout<<fibo%10<<endl;
	}
*/
