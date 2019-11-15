#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli dp[20][2][2]; lli a,b,ans; int pro,len1,len2;
vector<int> num1,num2;

void call(int pos, int start, int f)
{
if(pos == num.size()) return (even-odd)==1;

lli &ret = dp[pos][start][f][odd][even];

if(ret != -1) return ret;

lli res = 0;

int LMT;
if(f==0) LMT = num[pos];
else LMT = 9;

if(!start) //start=0, no dgt is selected
	{
	for(int dgt=1;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		if((len-pos+1)&1) //means it will be odd from right
			res += call(pos+1, 1, nf, dgt, 0);
		else
			res += call(pos+1, 1, nf, 0, dgt);
		}
	res += call(pos+1,0,1,0,0);
	}
else
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		
		if((len-pos+1)&1)
			res += call(pos+1, start+1, nf, odd+dgt, even);
		else
			res += call(pos+1, start+1, nf, odd, even+dgt);
		}
	}

return ret = res;
}

void solve(lli n, lli m)
{
while(n)
	{
	num1.push_back(n%10);
	n /= 10;
	}
while(m)
	{
	num2.push_back(m%10);
	m /= 10;
	}	
reverse(num1.begin(), num1.end()); reverse(num2.begin(), num2.end());
memset(dp,-1,sizeof(dp));
len1 = num1.size(), len2 = num2.size();

call(0,0,0,0,0);
}

int main()
{
cin>>a>>b;
solve(a,b);
cout<<ans<endl;
}
return 0;
}
