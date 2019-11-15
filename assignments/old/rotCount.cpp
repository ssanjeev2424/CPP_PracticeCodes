#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

void rotCount(int *arr, int n)
{
int l = 0, r = n-1, cnt = 0;

while(l<r)
	{
	if(arr[l]<=arr[r]) break;
	
	int mid = (l+r)/2;
	if(arr[mid]>=arr[l] && arr[mid]>arr[r])
		cnt += mid-l+1, l=mid+1;
	else if(arr[mid]<arr[l])
		r = mid;
	}
cout<<cnt<<endl;
}

//https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
int main()
{
int t; cin>>t;
while(t--)
	{
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	rotCount(arr,n);
	}
return 0;
}
