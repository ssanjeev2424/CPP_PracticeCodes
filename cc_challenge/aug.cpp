#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n;
	int preSum[n+1] = {0}, health[n+1], C, idx, flag = 0;
	for(int i=1;i<=n;i++)
		{
		cin>>C;
		
		idx = max(1, i-C); preSum[idx]++;
		idx = i+C+1; if(idx<=n) preSum[idx]--;
		}
	
	for(int i=1;i<=n;i++) cin>>health[i];
	
	for(int i=2;i<=n;i++)
		preSum[i] += preSum[i-1];
	
	/*for(int i=1;i<=n;i++)
		cout<<preSum[i]<<" "; cout<<endl;*/
	
	sort(preSum+1, preSum+n+1);
	sort(health+1, health+n+1);
	
	for(int i=1;i<=n;i++)
		if(preSum[i] != health[i])
			{
			cout<<"NO\n";
			flag = 1;
			break;
			}
	
	if(!flag) cout<<"YES\n";
	}
return 0;
}

/*

int n, ans = 0, temp; cin>>n;
	int a[n], b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	for(int i=0;i<n;i++)
		{
		temp = 20*a[i] - 10*b[i];
		if(temp > ans) ans = temp;
		}
	cout<<ans<<endl;
	
lli n,k; cin>>n>>k;
	
	if(k==1) { cout<<"NO\n"; continue; }
	
	if( (n/k)%k==0 ) cout<<"NO\n";
	else cout<<"YES\n";
*/
