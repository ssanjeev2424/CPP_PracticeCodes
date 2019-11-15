#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
vector<lli> num;

lli call(int pos, int f, int start, vector<int> v)
{
if(pos==num.size())
	{
	lli ans = 0;
	set<int> s;
	for(int i=0;i<v.size();i++)
		{
		int val = 0;
		for(int j=i;j<v.size();j++)
			{
			val ^= v[j];
			
			if(s.find(val)==s.end())
				{
				ans += val;
				s.insert(val);
				}
			}
		}
	//cout<<"pos:"<<pos<<" ans:"<<ans<<endl;
	return ans;
	}

int LMT;
if(f==0) LMT = num[pos];
else LMT = 9;
lli res=0;

if(!start)
	{
	for(int dgt=1;dgt<=LMT;dgt++)
		{
		int nf = f;
		if(f==0 && dgt<LMT) nf = 1;
		vector<int> vv = v;
		vv.emplace_back(dgt);
		res = (res%M + call(pos+1,nf,1,vv)%M)%M;
		}
	res = (res%M + call(pos+1,1,0,v)%M)%M;
	}
else
	{
	for(int dgt=0;dgt<=LMT;dgt++)
		{
		int nf;
		if(f==0 && dgt<LMT) nf = 1;
		
		vector<int> vv = v;
		vv.emplace_back(dgt);
		
		res = (res%M + call(pos+1, nf, 1, vv)%M)%M;
		}
	}
return res;
}

lli solve(lli x)
{
num.clear();

while(x>0)
	{
	num.emplace_back(x%10);
	x /= 10;
	}
reverse(num.begin(), num.end());

vector<int> v;
lli res = call(0, 0, 0, v)%M;
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	lli l,r,res; cin>>l>>r;
	if(l==1) res = solve(r);
	else res = (solve(r) - solve(l-1) + M)%M;
	cout<<res<<endl;
	}
return 0;
}
