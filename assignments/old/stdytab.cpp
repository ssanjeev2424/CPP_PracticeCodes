#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000000

template <typename type>
struct mycomp2
	{
	bool operator()(const type &first, const type &second) const {
	return first.second >= second.second;
	}
	};

void polygons();

int main()
{
int t; cin>>t;
while(t--)
	{
	polygons();
	}
return 0;
}

void polygons()
{
int n,sides,x,y,temp; cin>>n;
set<pair<int,int>, mycomp2<pair<int,int> > > rightmost; //stores the rightmost point of a polygon

for(int i=1;i<=n;i++)
	{
	cin>>sides;
	temp=-1000000001;
	for(int j=0;j<sides;j++)
		{
		cin>>x>>y;
		if(x>temp) temp = x;
		}
	rightmost.insert({i,temp});
	}
int ans[n+1],inside=n-1;

for(auto &i:rightmost)
	ans[i.first] = inside--;
for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
cout<<endl;
}


