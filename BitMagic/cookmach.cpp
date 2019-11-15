#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t,x,b,ans; cin>>t;
while(t--)
	{
	cin>>x>>b;
	ans = 0;
	while(x&(x-1))
		{
		ans++;
		x = x>>1;
		}
	if(x < b)
		{
		while(x != b)
			{
			ans++;
			x = x<<1;
			}
		}
	else
		{
		while(x != b)
			{
			ans++;
			x = x>>1;
			}
		}
	cout<<ans<<endl;
	}
return 0;
}
