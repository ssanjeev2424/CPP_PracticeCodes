#include <bits/stdc++.h>
using namespace std;

int dims[101][2], dp[101][101], n;

int MatrixChainMul(int i, int j) {

	if (j == i) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX, cost;

	for (int k=i; k<j; k++)
	{
		cost = MatrixChainMul(i, k);
		cost += MatrixChainMul(k+1, j);

		cost +=	dims[i][0] * dims[k][1] * dims[j][1];

		if (cost < ans) ans = cost;
	}
	return dp[i][j] = ans;
}

int main() {
	// Matrix M[i] has dimension dims[i][0] x dims[i][1] for i = 1..n
	cout<<"Enter #Matrices: "; cin>>n;
	cout<<"Enter dimensions:\n";
	for(int i=1; i<=n; i++)	cin>>dims[i][0]>>dims[i][1];
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++) dp[i][j] = -1;
		
	cout<<"Minimum cost is "<<MatrixChainMul(1, n)<<endl;
	return 0;
}
