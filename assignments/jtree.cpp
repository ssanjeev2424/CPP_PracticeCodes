#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli joseph(int,int); lli dfs(int,int);
int child[100001]; bool pathFound[100001];
vector<pair<int,int> > tickets[100001];
lli dp[100001];

int main()
{
lli n,m,a,b,c,q,h; cin>>n>>m;

for(int i=1;i<n;i++)
	{
	cin>>a>>b;
	child[a] = b;
	pathFound[a] = false;
	dp[a] = -1;
	}

for(int i=1;i<=m;i++)
	{
	cin>>a>>b>>c;
	tickets[a].push_back({b,c});
	}

cin>>q;
for(int i=0;i<q;i++)
	{
	cin>>h;
	lli ans = dfs(h,0);
	cout<<ans<<endl;
	}

return 0;
}

lli dfs(int node, int k)
{
if(node==1) return 0;

if(k) return dfs(child[node],k-1);

if(dp[node] != -1) return dp[node];

lli ans = tickets[node][0].second + dfs(child[node], tickets[node][0].first-1);
for(int i=1;i<tickets[node].size();i++)
	ans = min(ans, tickets[node][i].second + dfs(child[node],tickets[node][i].first-1));

return dp[node] = ans;
}

lli joseph(int curr, int k)
{
if(curr==1) return 0;

if(k==0) //curr must be included
	{
	lli ans = tickets[curr][0].second + joseph(child[curr],tickets[curr][0].first-1);
	
	for(int i=1;i<tickets[curr].size();i++)
		ans = min(ans, tickets[curr][i].second + joseph(child[curr],tickets[curr][i].first-1));
	
	return ans;
	}

//curr may or may not be included

lli ans = joseph(child[curr],k-1); //curr not included

for(int i=0;i<tickets[curr].size();i++) //considering all the tickets from curr
	ans = min(ans, tickets[curr][i].second + joseph(child[curr],tickets[curr][i].first-1));
	
return ans;
}
