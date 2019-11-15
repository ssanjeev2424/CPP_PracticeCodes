#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007

lli dp[2005][2005][2][2][2][2];
//odd is 1, if prev term was odd number(index(1 based)) term
vector<int> num;
int m, d, len;
string a, b;

lli call(int pos, int rem, int odd, int f, int start, int ok)
{                                                   
if(pos==len) return (rem==0 && ok);

lli &ret = dp[pos][rem][odd][f][start][ok];
if(ret != -1) return ret;
lli res = 0;

int LMT; if(f==0) LMT = num[pos]; else LMT = 9;

if(!start)
	{
	for(int dgt=1; dgt<=LMT; dgt++)
		{
		int nf = f, nOk = ok, nRem = rem;
		if(f==0 && dgt<num[pos]) nf = 1;
		nRem = (rem*10 + dgt)%m;
		
		if(dgt == d) nOk = 0; //odd position
		res = (res + call(pos+1, nRem, 1, nf, 1, nOk)%MOD)%MOD;
		}
	res = (res + call(pos+1, 0, 0, 1, 0, 1)%MOD)%MOD;
	}
else
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf = f, nOk = ok, nRem = rem;
		if(f==0 && dgt<num[pos]) nf = 1;
		nRem = (rem*10 + dgt)%m;
		
		if(odd&1) //even position(current)
			{
			if(dgt != d) nOk = 0;
			res = (res + call(pos+1, nRem, 0, nf, 1, nOk)%MOD)%MOD;
			}
		else //odd position(current)
			{
			if(dgt == d) nOk = 0;
			res = (res + call(pos+1, nRem, 1, nf, 1, nOk)%MOD)%MOD;
			}
		}
	}

return ret = res;
}

lli solve(string str)
{
num.clear();
for(int i=0;i<str.length();i++)
	num.push_back(str[i] - '0');

memset(dp,-1,sizeof(dp));
len = str.length();

lli res = call(0,0,0,0,0,1);
//cout<<"************************num: "<<str<<" ans: "<<res<<endl;
return res;
}

//https://codeforces.com/contest/628/problem/D

int main()
{
cin >> m >> d;
cin >> a >> b;

lli res = (solve(b) - solve(a))%MOD;	 // solve(b) - solve(a)

int rem = 0;
for(int i=0;i<a.length();i++) // checking for only "a"
	{
	int dgt = a[i] - '0';
	if((i&1) && dgt!=d) { rem=1; break; }
	if(!(i&1) && dgt==d) { rem=1; break; }
	rem = (rem*10 + dgt)%m;
	}
if(rem==0) res = (res+1)%MOD;

cout<<res<<endl; 
return 0;
}
