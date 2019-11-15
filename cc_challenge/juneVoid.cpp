#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
int t; cin>>t;
while(t--)
	{
	lli n,x; cin>>n>>x;
	
	int lvl = 0, node = 1;
	
	
	while(true)
		{
		if(node==x) { cout<<lvl<<endl; break; }
	
		int temp = pow(2,n-1)-1;
		
		if(x > (node + temp))
			{
			node += temp+1;
			lvl++; n--;
			}
		else
			{
			lvl++;
			node++;
			n--;
			}
		}
	}
return 0;
}
