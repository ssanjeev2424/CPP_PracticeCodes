#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int digits(int);

int main()
{
int n,m,l,v,k,sumD,idx; cin>>n; string arr[n+1]; int dgts[n+1];
for(int i=0;i<n;i++)
	{ 
	cin>>arr[i]; 
	dgts[i] = arr[i].length(); 
	}
cin>>m; string str = "";
for(int i=0;i<m;i++)
	{
	cin>>l>>v>>k; sumD = 0; str = "";
	
	idx = l;
	 
	while(idx<=n && k>sumD)
		{
		sumD += dgts[idx-1];
		str += arr[idx-1];
		
		idx += v;
		}
	if(idx>n && k>sumD) cout<<"So sad\n";
	else cout<<str[k-1]<<endl;
	}
return 0;
}

int digits(int x)
{
int d=0;
while(x)
	{
	d++;
	x /= 10;
	}
return d;
}
