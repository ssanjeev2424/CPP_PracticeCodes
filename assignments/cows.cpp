#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--)
{
int n,c,ans=0; cin>>n>>c;
int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
sort(arr, arr+n);

int Min = 0, Max = arr[n-1] - arr[0], mid, last, count;

while(Min<=Max)
	{
	mid = (Min+Max)/2;
	//cout<<"Min:"<<Min<<" Max:"<<Max<<" mid:"<<mid;
	last = arr[0], count = 1;
	for(int i=1;i<n;i++)
		{
		if(arr[i]-last >= mid)
			{
			count++;
			last = arr[i];
			}
		if(count==c) break;
		}
	
	if(count==c)
		{
		ans = (mid>ans)?mid:ans;
		Min = mid + 1;
		}
	else
		Max = mid - 1;
	//cout<<" ans:"<<ans<<endl;
	}

cout<<ans<<endl;
}
return 0;
}
