#include <bits/stdc++.h>
using namespace std;
#define M 1e9+7
void reposts(); void tree1();
void dfs1(int,int,vector<int> (&v)[20], int*);
void dfs_2a(int,int,vector<int> (&v)[20], int*);
void dfs_2b(int,int,vector<int> (&v)[20], int*);
int test[3], dp1[20], in[20], out[20], dp2[20];

int main()
{
int &t = test[1];
t = 5;
test[2] = M-6;
tree1();
//cout<<test[1]<<" "<<test[2]<<endl;
return 0;
}

void tree1()
{
int n,a,b; cin>>n; int arr[n+1];
for(int i=1;i<=n;i++) cin>>arr[i];

vector<int> node[20];
for(int i=1;i<n;i++)
	{
	cin>>a>>b;
	node[a].push_back(b);
	node[b].push_back(a);
	}
memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
memset(in,-1,sizeof(in));   memset(out,-1,sizeof(out));

// Dp on tree video 1
/*dfs1(1,-1,node,arr); cout<<"Max sum from root to Leaf:"<<dp1[1]<<endl; 
for(int i=1;i<=14;i++)
	cout<<i<<":"<<dp1[i]<<" ";
cout<<endl;*/


// Dp on tree video 2
dfs_2a(1,-1,node,arr);
dfs_2b(1,-1,node,arr);

for(int i=1;i<=n;i++)
	{
	dp2[i] = max(in[i], out[i]);
	cout<<dp2[i]<<" ";
	}
cout<<endl;
}

void dfs_2a(int u, int par, vector<int> (&vec)[20], int *arr)
{
in[u] = 0;

for(int v:vec[u])
	{
	if(v==par) continue;
	dfs_2a(v,u,vec,arr);
	in[u] = max(in[u], 1+in[v]);
	}
}

void dfs_2b(int u, int par, vector<int> (&vec)[20], int *arr)
{
int mx1 = -1, mx2 = -1;

//finding top 2 maximum values of in[v]
for(int v:vec[u])
	{
	if(v==par) continue;
	if(in[v] >= mx1) { mx2=mx1; mx1=in[v]; }
	else if(in[v] > mx2) mx2 = in[v];
	}

for(int v:vec[u])
	{
	if(v==par) continue;
	
	int use = mx1;
	
	if(mx1 == in[v])
		use = mx2;
	
	out[v] = max(1+out[u], 2+use);
	
	dfs_2b(v,u,vec,arr);
	}
}

void dfs1(int curr, int par, vector<int> (&v)[20], int *arr)
{
int sum = 0;

for(int i=0;i<v[curr].size();i++)
	{
	if(v[curr][i]==par) continue;
	dfs1(v[curr][i],curr,v,arr);
	sum = max(sum,dp1[v[curr][i]]);
	}
dp1[curr] = sum + arr[curr];
}

//http://codeforces.com/problemset/problem/522/A
void reposts()
{
int n, max = 1;
unordered_map<string,int> m;
m["POLYCARP"] = 1;
string a,b,c;
cin>>n;
for(int i=0;i<n;i++)
	{
	cin>>a>>b>>c;
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	transform(c.begin(), c.end(), c.begin(), ::toupper);
	m[a] = m[c] + 1;
	//cout<<a<<":"<<m[a]<<endl;
	if(m[a] > max) max = m[a];
	}
cout<<max<<endl;
}
/* DP on Trees

*/
