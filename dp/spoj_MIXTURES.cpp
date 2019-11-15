#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/MIXTURES/   -->> Matrix Multiplication
                                              // Application, GOOD ONE

int arr[101];
int color[101][101], smoke[101][101];

int main() {
	fast;
	ll t, n, ans; //cin>>t;
	while(cin>>n) {
		for(int i=0; i<n; i++) { 
			cin>>arr[i];
			color[i][i] = arr[i];
			smoke[i][i] = 0;
		}
		
		if(n == 1) {
			cout<<0<<endl;
			continue;
		}
		
		ans = 0;
		
		smoke[0][1] = arr[0]*arr[1]; color[0][1] = (arr[0]+arr[1])%M;
		for(int i=1; i<n-1; i++) {
			color[i][i+1] = (arr[i]+arr[i+1])%M;
			smoke[i][i+1] = arr[i]*arr[i+1];
		}
		
		for(int gap=2; gap<n; gap++) {
			int i=0, j = gap;
			
			while(j < n) {
				int y = (1<<30), temp, temp2;
				
				for(int k=i; k<j; k++) {
					temp = (color[i][k] + color[k+1][j])%M;
					temp2 = color[i][k]*color[k+1][j] + smoke[i][k] + smoke[k+1][j];
					
					if(temp2 < y) {  //choosing the min smoke val for [i,j]
						color[i][j] = temp;
						smoke[i][j] = y = temp2;
					}
				}
				
				i++; j++;
			}
		}
		
		cout<<smoke[0][n-1]<<endl;
	}
	return 0;
}
