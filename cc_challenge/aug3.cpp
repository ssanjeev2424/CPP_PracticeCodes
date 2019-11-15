#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> num;

lli call(int pos, int prev, lli sum, int f, int e)
{
if(pos==num.size()) return sum;

int LMT; lli res = 0;
if(f==0) LMT = num[pos]; else LMT = 9;

for(int dgt=0;dgt<=LMT;dgt++)
	{
	int nf = f;
	if(f==0 && dgt<num[pos]) nf = 1;
	
	lli nSum = sum;
	if(prev!=dgt)
		nSum = (sum + (dgt*((lli)pow(10,e)%M))%M )%M;

	res = (res + call(pos+1,dgt,nSum,nf,e-1))%M;
	}
return res;
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
lli res = call(0,-1,0,0,num.size()-1);
return res;
}

int main()
{
int t; cin>>t;
while(t--)
	{
	lli nl,l,nr,r; cin>>nl>>l>>nr>>r;
	
	lli ans = 0; lli prev,idx;
	for(lli i=l;i<=r;i++)
		{
		prev = i%10, idx=0;
		lli y = i;
		y /= 10;
		while(y)
			{
			if(prev!=y%10)
				{
				ans = (ans + (prev*(lli)pow(10,idx))%M)%M;
				prev = y%10;
				}
			y /= 10;
			idx++;
			}
		ans = (ans + (prev*(lli)pow(10,idx))%M)%M;
		}
	cout<<ans<<endl;
	}
return 0;
}
