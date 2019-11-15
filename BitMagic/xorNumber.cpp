#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--)
	{
	lli n;
	cin>>n;
	
	if(n==1)
		cout<<2<<endl;
	else if( !((n+1)&n) ) //if it's of type "2^n - 1"
		cout<<n/2<<endl;
	else
		cout<<-1<<endl;
	}
return 0;
}
