#include<bits/stdc++.h>
using namespace std;
int gcd(int,int);

int main()
{
int n,n2;
cin>>n;
while(n--)
{
	int arr[50] = {0},i=0;
	cin>>n2;
	while(n2--)
	{
	cin>>arr[i++];
	}
	int result = arr[0];
	for(int j=1;j<i;j++)
		result = gcd(result,arr[j]);
	if(result!=1)
	for(int j=0;j<i;j++)
	cout<<arr[j]/result<<" ";
	else
	for(int j=0;j<i;j++)
	cout<<arr[j]<<" ";

	cout<<endl;
}
return 0;
}

int gcd(int a,int b)
{
if(a==0) return b;
return gcd(b%a,a);
}
