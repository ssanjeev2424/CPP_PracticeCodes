#include <bits/stdc++.h>
using namespace std;

void lca1(); bool findPath(int,int,vector<int> &v,int);
vector<int> child[50]; int arr[50];

int main()
{
lca1();
return 0;
}

void lca1()
{
int n,a,b,n1,n2; cin>>n;
for(int i=1;i<=n;i++) cin>>arr[i];
for(int i=1;i<n;i++)
	{
	cin>>a>>b;
	child[a].push_back(b); child[b].push_back(a);
	}
vector<int> path1, path2;
cout<<"Enter the two node numbers(not their values): ";
cin>>n1>>n2;

if( !findPath(1,-1,path1,n1) || !findPath(1,-1,path2,n2) )
	{ cout<<"Invalid Input\n"; return; }


for(int p=0;p<path1.size();p++) cout<<path1[p]<<" ";
cout<<endl;
for(int p=0;p<path2.size();p++) cout<<path2[p]<<" ";
cout<<endl;

int i;
for(i=0;i<path1.size() && i<path2.size(); i++)
	if(path1[i] != path2[i]) break;
cout<<"LCA is:"<<arr[path1[i-1]]<<" #Node:"<<path1[i-1]<<endl;
}

bool findPath(int curr,int par,vector<int> &path,int node)
{
path.push_back(curr);

if(curr==node) return true;

for(int i=0;i<child[curr].size();i++)
	{
	if(child[curr][i]==par) continue;
	
	if( findPath(child[curr][i],curr,path,node) )
		return true;
	}

path.pop_back();
return false;
}



