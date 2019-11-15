#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

void binary(lli);

int main()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n; int arr[n+1][n+1];
	binary(1000000000);
	//cout<<(lli)pow(2,31)<<endl;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	
	
	}
return 0;
}

void binary(lli x)
{
string str = "";

while(x)
	{
	if(x%2==0) str = "0" + str;
	else str = "1" + str;
	x = x>>1;
	}
str = "0" + str;
cout<<str<<endl;
}
