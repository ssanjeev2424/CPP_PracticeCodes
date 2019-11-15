#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int n,k,limit;
int solve(int,int);
lli dp[4096][100];

int main()
{
int t; cin>>t;
while(t--)
	{
	cin>>n>>k; limit = pow(2,n)-1;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0)<<endl;
	}
return 0;
}

int solve(int mask, int inv)
{
if(inv > k)
	return dp[mask][inv] = 0;
if(mask==limit)
	return dp[mask][inv] = (inv==k)?1:0;
if(dp[mask][inv] != -1)
	return dp[mask][inv];

int temp, ans = 0;
for(int i=0;i<n;i++)
	{
	if(!((1<<i)&mask))
		{
		temp = mask | (1<<i);
		
		int newInv = inv;
		for(int j=i+1;j<n;j++)
			{
			if( ((1<<j)&mask) )
				newInv++;
			}
		
		ans += solve(temp,newInv);
		}
	}
return dp[mask][inv] = ans;
}
