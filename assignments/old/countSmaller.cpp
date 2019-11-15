#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

void countSmaller(int *arr, int n, int x)
{
int l=0, r=n-1, ans=0;

while(l<r)
	{
	int mid = (l+r)/2;
	if(arr[mid] < x)
		ans+=mid-l+1,l=mid+1;
	else
		r = mid;
	}
if(l==r && arr[l]<x) ans++;
cout<<ans<<endl;
}

//https://www.geeksforgeeks.org/count-smaller-elements-in-sorted-array-in-cpp/
int main()
{
int t; cin>>t;
while(t--)
	{
	int n,x; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"Enter the element: "; cin>>x;
	countSmaller(arr,n,x);
	}
	
return 0;
}
