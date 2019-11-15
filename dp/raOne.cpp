#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli dp[10][10][2][50][50]; lli a,b,len;
vector<int> num;

lli call(int pos, int start, int f, int odd, int even)
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

lli solve(lli n)
{
//cout<<"For number:"<<n<<endl;
num.clear();
while(n)
	{
	num.push_back(n%10);
	n /= 10;
	}
	
reverse(num.begin(), num.end());
memset(dp,-1,sizeof(dp));
len = num.size()-1;
lli res =  call(0,0,0,0,0);
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	cin>>a>>b;
	if(a<=10) cout<<solve(b)<<endl;
	else cout<<(solve(b)-solve(a-1))<<endl;
	}
return 0;
}
