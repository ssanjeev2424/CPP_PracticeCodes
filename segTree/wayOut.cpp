#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void tractor();

int main()
{
int t; cin>>t;
while(t--)
	tractor();
return 0;
}

void tractor()
{
lli n,h;   cin>>n>>h;
lli arr[n+2] = {0};
int a,b;

for(int i=0;i<n;i++)
	{
	cin>>a>>b;
	arr[a] += 1;
	arr[b+1] += -1;
	}

for(int i=1;i<=n;i++) //prefix Sum
	arr[i] += arr[i-1];

lli sum = 0, ans;	
for(int i=0;i<h;i++)
	sum += arr[i];
	
ans = sum;

for(int i=h;i<n;i++)
	{
	sum += arr[i] - arr[i-h];
	if(sum > ans) ans = sum;
	}
cout<<(n*h-ans)<<endl;
}
