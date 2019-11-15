#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int n; cin>>n; lli arr[n];
for(int i=0;i<n;i++) cin>>arr[i];

for(int i=0;i<n;i++)
	{
	lli fives = 0, twos = 0, temp = arr[i];
	while(temp%5==0 && temp)
		{
		temp /= 5;
		fives++;
		}
	temp = arr[i];
	while(temp%2==0 && temp)
		{
		temp /=2;
		twos++;
		}
	for(int j=fives-twos;j>0;j-=2)
		arr[i] *= 4;
	cout<<arr[i]<<endl;
	}
	
return 0;
}
