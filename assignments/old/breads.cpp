#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--)
	{
	lli n, k, count = 0; cin>>n>>k;
	lli arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	set<pair<lli,lli> > s;
	for(int i=0;i<n;i++)
		{
		lli temp = arr[i];
		if(arr[i]>=k)
			{
			count += arr[i]/k;
			if(arr[i]%k==0) continue;
			temp = arr[i]%k;
			}
		
		auto itr = s.lower_bound({temp,1});
		if(itr==s.end()) //new bag should be added
			{
			lli rem = k - temp - 1; // 1 gets wasted
			auto itr2 = s.lower_bound({rem,1});
			
			if(itr2==s.end() || (*itr2).first > rem)
				s.insert({rem,1});
			else
				{
				s.insert({rem,(*itr2).second+1});
				s.erase(itr2);	
				}
			}
		else //lowerBound found
			{
			if((*itr).first <= temp+1) //here 1 bag will be removed
				{
				count++;
				if((*itr).second==1) s.erase(itr);
				else
					s.insert({temp,(*itr).second-1}), s.erase(itr);
				}
			else
				{
				lli rem = (*itr).first - temp - 1;
				
				auto itr2 = s.lower_bound({rem,1});
			
				if(itr2==s.end() || (*itr2).first > rem)
					s.insert({rem,1});
				else
					{
					s.insert({rem,(*itr2).second+1});
					s.erase(itr2);	
					}
				}
			}
			
		}
		for(auto x: s)
			count += x.second;
		
		cout<<count<<endl;
	}
return 0;
}
