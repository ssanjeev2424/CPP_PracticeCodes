#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

void solve();
lli dp[802][802], sum[802][802], arr[802];
int n;

int main()
{
int t,i,j; cin>>t;
while(t--)
	{
	cin>>n; j=0;
	for(i=0; i<n; i++) cin>>arr[i];
	for(; j<n-1; j++,i++) arr[i] = arr[j];
	/*for(int i=0;i<2*n-1;i++)
		cout<<arr[i]<<" ";
	cout<<endl;*/
	solve();
	}
return 0;
}

void solve()
{
for(int i=0;i<2*n-1;i++)
	dp[i][i] = 0, sum[i][i] = arr[i];

for(int i=0;i<2*n-2;i++)
	dp[i][i+1] = sum[i][i+1] = arr[i] + arr[i+1]; //step=2

for(int step=2; step<n; step++) // O(n^2)
	{
	int i = 0; int j = i + step;
	while(i<n)
		{
		sum[i][j] = sum[i][j-1] + arr[j];
		if(j<n-1) sum[i+n][j+n] = sum[i][j];
		i++; j++;
		} 
	}

/*for(int step=1;step<n;step++)
	{
	int i = 0, j = i + step;
	while(i<n)
		{
		cout<<"Sum["<<i<<"]["<<j<<"]: "<<sum[i][j]<<endl;
		i++; j++;
		}
	}*/

for(int step=2; step<n-1; step++)
	{
	int i = 0; int j = i + step;
	
	while(i<n)
		{
		lli ans = LONG_MAX, temp;
		int k = i;
		
		while(k<j)
			{
			temp = (dp[i][k] + dp[k+1][j]) + (sum[i][k] + sum[k+1][j]);
			if(temp < ans) ans = temp;
			k++;
			}
			
		if(j<n-1)
			dp[i][j] = dp[i+n][j+n] = ans;
		else
			dp[i][j] = ans;
		
		i++; j++;
		}
	}
//cout<<dp[3][4]<<" "<<dp[5][5]<<" "<<sum[3][4]<<" "<<sum[5][5]<<endl;
int i = 0; int j = i + n - 1;
lli res = LONG_MAX;
while(i<n)
	{
	lli ans = LONG_MAX, temp;
	int k = i;
	
	while(k<j)
		{
		temp = (dp[i][k] + dp[k+1][j]) + (sum[i][k] + sum[k+1][j]);
		if(temp < ans) ans = temp;
		k++;
		}
	dp[i][j] = ans;
	if(ans < res) res = ans;
	i++; j++;
	}
/*for(int step=1;step<n;step++)
	{
	int i = 0, j = i + step;
	while(i<n)
		{
		cout<<"dp["<<i<<"]["<<j<<"]: "<<dp[i][j]<<endl;
		i++; j++;
		}
	}*/
cout<<res<<endl;
}
