#include<bits/stdc++.h>
using namespace std;
void bell(); int modu(long long,int);

int main()
{
bell();
return 0;
}

void bell()
{
int n;
cin>>n;

long long a[n+1][n+1];
a[0][0]=1;
for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
		{
		if(j==1) a[i][j] = a[i-1][i-1];
		else a[i][j] = a[i][j-1] + a[i-1][j-1];
		}
cout<<"Nth Bell no:"<<a[n][1]<<endl;
cout<<"Nth Bell no MOD 10^9+7:"<<modu(a[n][1],1000000007)<<endl;
}

int modu(long long num,int m)
{
if(num<m) return num;
if(num==m) return 0;

int smallAns = modu(num/2,m)%m;

if(num%2==0) return (2*smallAns)%m;

return (2*smallAns+1)%m;
}
