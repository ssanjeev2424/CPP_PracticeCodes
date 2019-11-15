#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--) //for subTask 1 only
	{
	int n,z; cin>>n>>z; int num[1001] = {0};
	int arr[n]; for(int i=0;i<n;i++) { cin>>arr[i]; num[arr[i]]++; }
	
	sort(arr, arr+n);
	
	int Min = arr[0], Max = arr[n-1];
	if(Min==Max) { cout<<arr[0]<<endl; continue; }
	
	int ans = INT_MAX, temp, sum;
	for(int i=0;i<n;i++)
		{
		sum = 0;
		for(int j=0;j<n;j++)
			{
			if(arr[j]<=arr[i]) continue;
			
			sum += arr[i];
			}
		sum += arr[i];
		ans = min(ans, sum);
		}
	if(ans > Max) ans = Max;
	cout<<ans<<endl;	
	}
return 0;
}
