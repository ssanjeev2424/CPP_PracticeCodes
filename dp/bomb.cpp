#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//https://wordpresscom77092.wordpress.com/2017/11/04/hdu-bomb/#more-326
lli dp[20][2][2][2][2]; lli a,b,len;
// prev=1 if prev is 4, found is 1, if 49 pattern is found
vector<int> num;

lli call(int pos, int start, int prev, int f, int found)
{
if(pos == num.size()) return found;

lli &ret = dp[pos][start][prev][f][found];

if(ret != -1) return ret;

lli res = 0;

int LMT;
if(f==0) LMT = num[pos];
else LMT = 9;

if(!start) //start=0, no dgt is selected
	{
	for(int dgt=1;dgt<=LMT;dgt++)
		{
		int nf = f, nFound = found, nPrev = 0;
		if(f==0 && dgt<num[pos]) nf = 1;
		if(found==0 && prev==1 && dgt==9) nFound = 1;
		if(dgt==4) nPrev = 1;
		
		res += call(pos+1, 1, nPrev, nf, nFound);
		}
	res += call(pos+1,0,0,1,0);
	}
else
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf = f, nFound = found, nPrev = 0;
		if(f==0 && dgt<num[pos]) nf = 1;
		if(found==0 && prev==1 && dgt==9) nFound = 1;
		if(dgt==4) nPrev = 1;
		
		res += call(pos+1, 1, nPrev, nf, nFound);
		}
	}


return ret = res;
}

lli solve(lli n)
{
num.clear();
while(n)
	{
	num.push_back(n%10);
	n /= 10;
	}
	
reverse(num.begin(), num.end());
memset(dp,-1,sizeof(dp));
lli res =  call(0,0,0,0,0);
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	cin>>a;
	if(a<49) cout<<0<<endl;
	else cout<<solve(a)<<endl;
	}
return 0;
}
