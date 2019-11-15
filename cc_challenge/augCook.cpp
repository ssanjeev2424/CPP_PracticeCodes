#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n; int lSum=0,rSum=0,left[n]={0},right[n]={0},x,y,ans,temp;
	string str;
	for(int i=0;i<n;i++)
		{
		cin>>str;
		
		for(int j=0;j<n/2;j++)
			if(str[j]=='1')
				left[i]++;
		lSum += left[i];
		
		for(int j=n/2;j<n;j++)
			if(str[j]=='1')
				right[i]++;
		rSum += right[i];
		}
	
	ans = abs(lSum-rSum);
	
	for(int i=0;i<n;i++)
		{
		x = left[i]; y = right[i];
		
		if(x != y)
			{
			lSum -= x; lSum += y;
			rSum -= y; rSum += x;
			
			if((temp=abs(lSum-rSum)) < ans)
				ans = temp;
			
			lSum -= y; lSum += x;
			rSum -= x; rSum += y;
			}
		}
	cout<<ans<<endl;
	}
return 0;
}

/*
cin>>n>>m>>k>>l>>r; ans = INT_MAX;
	
	
	for(int i=0;i<n;i++)
		{
		cin>>Ci>>Pi;
		
		if(m >= abs(k-Ci)) temp = k;
		else
			{
			if(Ci > k) temp = Ci - m;
			else temp = Ci + m;
			}
		
		if(l <= temp && temp <= r)
			if(Pi < ans)
				ans = Pi;
		}
	if(ans == INT_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;
*/
