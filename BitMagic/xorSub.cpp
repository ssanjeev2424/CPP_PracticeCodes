#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
//int arr[1001], dp[1001][1001];

int main()
{
int t,n,k,ans,temp; cin>>t;
while(t--)
	{
	cin>>n>>k; int dp[1024]={0};
	for(int i=0;i<n;i++) 
	{
	cin>>temp;
	for(int i=1;i<=1023;i++)
		if(dp[i])
			dp[i^temp] = 1;
	dp[temp] = 1;
	}
// dp[i]=1 means XOR a subset leads to value "i", basically checks all subset, value of XOR can't exceed 1023, here
	ans = k;
	for(int i=1;i<1024;i++)
		if(dp[i])
			if((i^k) > ans)
				ans = (i^k);
	cout<<ans<<endl;
	}	
return 0;
}
