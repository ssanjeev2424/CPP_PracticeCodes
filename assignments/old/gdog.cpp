#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
int t,n,k; cin>>t;
while(t--)
	{
	cin>>n>>k;
	int ans = n%k;
	if(ans==k-1) { cout<<k-1<<endl; continue; }
	
	k--;
	while(k>1)
		{
		if(n%k > ans) ans = n%k;
		if(n%k == k-1) break;
		k--;
		}
	cout<<ans<<endl;
	}
return 0;
}
