#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
/* return an array such that, each element is the multiplication of every 
 other element, except itself

1 2 3 4 5
output: 120 60 40 30 24
*/

int main()
{
int t; cin>>t;
while(t--)
	{
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	
	int preMul[n], temp;
	
	preMul[0] = 1;
	for(int i=1;i<n;i++) //prefix Multiplication
		preMul[i] = preMul[i-1]*arr[i-1];
	
	temp = 1;
	for(int i=n-2;i>=0;i--) //New array
		{
		temp *= arr[i+1];
		preMul[i] = preMul[i]*temp;
		}
	
	for(int i=0;i<n;i++) // O(n) space is used, the new array 
		cout<<preMul[i]<<" "; cout<<endl;  // which is returned
	}
return 0;
}
