#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli dp[20][150][2][2]; lli a,b;
vector<int> num;

lli call(int pos, lli sum, int start, int f)
{
if(pos==num.size()) return sum;

if(dp[pos][sum][start][f] != -1) return dp[pos][sum][start][f];

lli res = 0;

int LMT;
if(f==0) LMT = num[pos];
else LMT = 9;

if(!start)
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		res += call(pos+1, sum+dgt, 0, nf);
		}
	}
else
	{
	for(int dgt=1;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		res += call(pos+1, sum+dgt, 0, nf);
		}
	res += call(pos+1, 0, 1, 1);
	}
//cout<<"pos:"<<pos<<" f:"<<f<<" ans:"<<res<<endl;
return dp[pos][sum][start][f] = res;
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

lli res =  call(0,0,1,0);
//cout<<"num: "<<n<<" ans: "<<res<<endl;
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	cin>>a>>b;
	if(a==0) cout<<solve(b)<<endl;
	else cout<<(solve(b)-solve(a-1))<<endl;
	}
return 0;
}
