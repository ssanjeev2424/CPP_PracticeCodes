#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//lli dp[10][10][2][50][50];
lli a,b,len;
vector<int> num; int k;

lli call(int pos, int start, int f, unordered_set<int> s, lli n)
{
if(pos == num.size())
	{
	if(k==0) return 1;
	int count = 0;
	for(int x: s)
		{
		if(x == 0) continue;
		if(n%x == 0) count++;
		if(k && count==k) break;
		}
	return (k<=count)?1:0;
	}

lli res = 0;

int LMT;
if(f==0) LMT = num[pos];
else LMT = 9;

if(!start) //start=0, no dgt has yet been selected
	{
	for(int dgt=1;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		
		unordered_set<int> ss = s;
		if(ss.count(dgt)==0) ss.insert(dgt);
		
		lli newN = n;
		newN = newN*10 + dgt;
		
		res += call(pos+1, 1, nf, ss, newN);
		}
	res += call(pos+1, 0, 1, s, 0);
	}
else
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<num[pos]) nf = 1;
		
		unordered_set<int> ss = s;
		if(ss.count(dgt)==0) ss.insert(dgt);
		
		lli newN = n;
		newN = newN*10 + dgt;
		
		res += call(pos+1, 1, nf, ss, newN);
		}
	}

return res;
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
//memset(dp,-1,sizeof(dp));
len = num.size(); unordered_set<int> s;
lli res =  call(0 , 0, 0, s, 0);
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	cin>>a>>b>>k;
	cout<<(solve(b)-solve(a-1))<<endl;
	}
return 0;
}
