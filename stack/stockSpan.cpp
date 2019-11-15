#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int n; cin>>n;
int arr[n+1]; for(int i=1;i<=n;i++) cin>>arr[i];

int stock[n+1], stock2[n+1], total[n+1], end;
stack<int> stk;
stk.push(-1); stk.push(1); stock[1] = 1;

for(int i=2;i<=n;i++)
	{
	int ans = 1, idx = i-1, cnt = 0;
	while(arr[idx] <= arr[i] && idx > 0)
		{
		ans += stock[idx];
		cnt++;
		idx -= stock[idx];
		}
	
	for(int j=0;j<cnt;j++)
		stk.pop();
	stk.push(ans);
	stock[i] = ans;
	}
cout<<"\n<==From left==>\n";
for(int i=1;i<=n;i++) cout<<stock[i]<<" ";
cout<<endl<<"\n<==From right==>\n";

while(!stk.empty()) stk.pop();

stk.push(-1); stk.push(1); stock2[n] = 1;

for(int i=n-1;i>=1;i--)
	{
	int ans = 1, idx = i+1, cnt = 0;
	while(arr[idx] <= arr[i] && idx <= n)
		{
		ans += stock2[idx];
		cnt++;
		idx += stock2[idx];
		}
	
	for(int j=0;j<cnt;j++)
		stk.pop();
	stk.push(ans);
	stock2[i] = ans;
	}
	
for(int i=1;i<=n;i++) cout<<stock2[i]<<" ";
cout<<endl<<"\n<==Total==>\n";
for(int i=1;i<=n;i++) cout<<stock[i]+stock2[i]-1<<" ";
cout<<endl; 
// time: O(n) because every element is pushed and popped atmost once
return 0;
}
