#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t,n,k,temp; cin>>t;
while(t--)
	{
	cin>>n>>k; int arr[n+1], XOR[n+1];
	
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	XOR[1] = arr[1]; XOR[0] = 0;
	for(int i=2;i<=n;i++)
		XOR[i] = XOR[i-1]^arr[i];
	
	int ans = k;
	
	for(int i=1;i<=n;i++)
		if((temp=k^arr[i]) > ans) ans = temp;
	
	for(int step=1;step<n;step++)
		{
		int i = 1, j = step + 1;
		
		while(j<=n)
			{
			if(temp=(k^(XOR[j]^XOR[i-1])) > ans)
				ans = temp;
			
			i++; j++;
			}
		}
	cout<<ans<<endl;
	}
return 0;
}
