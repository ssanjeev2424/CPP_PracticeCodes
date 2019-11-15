#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
int t,m,x,y; cin>>t; bool safe[101];
while(t--)
	{
	cin>>m>>x>>y; memset(safe,false,sizeof(safe));
	int ghar, ans = 100, range  = x*y;
	//cout<<"Input taken..\n";
	for(int i=0;i<m;i++)
		{
		cin>>ghar;
		for(int k=max(1,ghar-range);k<=min(100,ghar+range);k++)
			{
			if(safe[k]) continue;
			
			safe[k] = true;
			ans--;
			}
		}
	if(ans<0) ans=0;
	cout<<ans<<endl;
	}
return 0;
}
