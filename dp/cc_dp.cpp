#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mini INT_MIN
lli calvin(int*,int,int,int,char); lli maxi(lli,lli,lli);
lli dp[1000007][2];

int main()
{
int n,k; cin>>n>>k; int arr[n+1]; memset(dp,-1,sizeof(dp));
for(int i=1;i<=n;i++) cin>>arr[i];
int arrLen = sizeof(arr)/sizeof(arr[0]);

cout<<calvin(arr,0,k,arrLen,'F');
//cout<<endl<<INT_MIN-1;
return 0;
}

lli calvin(int *arr, int sum, int idx, int len, char phase)
{
//https://www.codechef.com/INOIPRAC/problems/INOI1301
if(len==1) return 0;

if(phase=='B') 
	{
	if(idx==1)
		return 0;
		
	if(dp[idx][1] != -1) return dp[idx][1];
		
	int smallAns1=mini,smallAns2=mini;
	if(idx-1 > 0)
		smallAns1 = arr[idx-1] + calvin(arr,sum,idx-1,len,phase);
	if(idx-2 > 0)
		smallAns2 = arr[idx-2] + calvin(arr,sum,idx-2,len,phase);
		
	return dp[idx][1] = (smallAns1>=smallAns2)?smallAns1:smallAns2;
	}

if(dp[idx][0] != -1) return dp[idx][0];

int ans1=mini, ans2=mini, ans3=mini, ans4=mini, ans5=mini;

if(idx+1 < len)
	ans1 = arr[idx+1] + calvin(arr,sum,idx+1,len,phase);
if(idx+2 < len)
	ans2 = arr[idx+2] + calvin(arr,sum,idx+2,len,phase);
if(idx-1 > 0)
	ans3 = arr[idx-1] + calvin(arr,sum,idx-1,len,'B');
if(idx-2 > 0)
	ans4 = arr[idx-2] + calvin(arr,sum,idx-2,len,'B');
if(idx==1)
	ans5 = calvin(arr,sum,idx,len,'B');
return dp[idx][0] = maxi(ans1,ans2,maxi(ans3,ans4,ans5));
}

lli maxi(lli a, lli b, lli c)
{
if(a>=b && a>=c) return a;
return (b>=c)?b:c;
}
