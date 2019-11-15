#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--)
	{
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
		{
		if(m.count(arr[i])) m[arr[i]]++;
		else m[arr[i]] = 1;
		}
	int moves = INT_MAX;
	for(auto x: m)
		{
		if(n-x.second < moves) moves = n - x.second;
		}
	cout<<moves<<endl;
	}
return 0;
}
