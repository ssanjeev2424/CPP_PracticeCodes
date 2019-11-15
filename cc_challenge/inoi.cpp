#include <bits/stdc++.h>
using namespace std;
#define lli long long int

template <typename type>
struct mycomp2
	{
	bool operator()(const type &first, const type &second) const {
	return first.second >= second.second;
	}
	};

void triathlon(); void wealth(); void table();
lli maxDiff, minn[100001]; bool visited[100001];
void dfs(int node, vector<int> (&v)[100001], lli *money);
void minimum(int node, vector<int> (&v)[100001], lli *money);


int main()
{
table();
return 0;
}

void table()
{
int n; cin>>n; lli arr[n+1],temp,maxSum,adder;
for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);

for(int i=1;i<=n;i++)
	{
	adder = i; maxSum = 0;
	for(int j=1;j<=n;j++)
		{
		if( (temp = arr[j]+adder) > maxSum)
			maxSum = temp;
		
		if(adder==n) adder = 1;
		else adder++;
		}
	cout<<maxSum<<" ";
	}
}

void wealth()
{
int n,root; cin>>n;
lli money[n+1]; int parent[n+1];

for(int i=1;i<=n;i++)
	scanf("%lld",&money[i]);
	
vector<int> node[100001];
for(int i=1;i<=n;i++)
	{
	visited[i] = false;
	minn[i] = INT_MAX;
	scanf("%d",&parent[i]);
	if(parent[i]==-1) root = i;
	else node[ parent[i] ].push_back(i);
	}

if(n==1) { cout<<0<<endl; return; }
maxDiff = INT_MIN;
visited[root] = true;
minimum(root,node,money);   dfs(root,node,money);

cout<<maxDiff<<endl;
}

void dfs(int node, vector<int> (&v)[100001], lli *money)
{
if(v[node].size()==0) return;

for(int i=0;i<v[node].size();i++)
	{
	int child = v[node][i];
	lli temp;
	if( (temp = money[node]-minn[child]) > maxDiff )
		maxDiff = temp;
	
	dfs(child,v,money);
	}
}

void minimum(int node, vector<int> (&v)[100001], lli *money)
{
if(minn[node] != INT_MAX) return;

lli mini = money[node];

if(v[node].size()==0)
	{
	minn[node]=mini;
	return;
	}

for(int i=0;i<v[node].size();i++)
	{
	int child = v[node][i];
	minimum(child,v,money);
	mini = min( mini,minn[child] );
	}

minn[node]=mini;
}

void triathlon()
{
int n,a,b,c;
cin>>n;
int arr[n+1][2], cobol[n+1];

set< pair<int,int>, mycomp2<pair<int,int> > > s;
for(int i=1;i<=n;i++)
	{
	cin>>a>>b>>c;
	cobol[i] = a; int temp = b+c;
	s.insert({i, temp});
	}
int idx = 1;
for(auto &i : s)
	{
	arr[idx][0] = cobol[i.first];
	arr[idx++][1] = i.second;
	//cout<<i.first<<"-->>"<<i.second<<endl;
	}
/*cout<<"************************\n";
for(int i=1;i<=n;i++)
	{
	cout<<arr[i][0]<<"-->>"<<arr[i][1]<<endl;
	}*/

long int time[n+1]={0}, maxT=0, cobolSum=0;

for(int i=1;i<=n;i++)
	{
	if(i==n)
		{
		cobolSum += arr[i][0];
		time[n] = cobolSum + arr[n][1];
		if(time[n] > maxT) maxT = time[n];
		//cout<<"INdex: "<<i<<" time: "<<time[n]<<endl;
		break;
		}
	
	if(arr[i][1] != arr[i+1][1])
		{
		cobolSum += arr[i][0];
		time[i] = cobolSum + arr[i][1];
		if(time[i] > maxT) maxT = time[i];
		//cout<<"INdex: "<<i<<" time: "<<time[i]<<endl;
		continue;
		}
	
	int prev; //long int tempSum = cobolSum;
	while( (arr[i][1]==arr[i+1][1]) && i<n )
		{
		cobolSum += arr[i][0];
		prev = i;
		i++;
		}
	cobolSum += arr[prev+1][0];
	time[prev+1] = cobolSum + arr[prev+1][1];
	if(time[prev+1] > maxT) maxT = time[prev+1];
	//cout<<"INdex: "<<i+1<<" time: "<<time[i+1]<<endl;
	if(prev==n-1) break;
	}

cout<<maxT<<endl;
}




















