#include <bits/stdc++.h>
using namespace std;

void buildTree(int*,int,int,int); int tree[100001*4],lazy[100001*4];
void update(int,int,int,int,int); int sum(int,int,int,int,int);

int main()
{
int n,q,bit,a,b; cin>>n>>q;
int arr[n] = {0};
buildTree(arr,0,n-1,0);

for(int i=0;i<q;i++)
	{
	cin>>bit>>a>>b;
	
	if(bit==1)
		cout<<sum(a,b,0,n-1,0)<<endl;
	else
		update(0,n-1,a,b,0);
	}
return 0;
}

int sum(int lb, int ub, int l, int r, int idx)
{
if(lazy[idx] != 0)
	{
	tree[idx] = (r-l+1) - tree[idx];
	if(l != r)
		{
		lazy[2*idx+1] = 1 - lazy[2*idx+1];
		lazy[2*idx+2] = 1 - lazy[2*idx+2];
		}
	lazy[idx] = 0;
	}

if(l>ub || r<lb) return 0;

if(lb<=l && r<=ub) return tree[idx];

int mid = (l+r)/2;

return sum(lb,ub,l,mid,2*idx+1)+sum(lb,ub,mid+1,r,2*idx+2);
}

void update(int l, int r, int startR, int endR, int idx)
{
if(lazy[idx] != 0)
	{
	tree[idx] = (r-l+1) - tree[idx];
	if(l != r)
		{
		lazy[2*idx+1] = 1 - lazy[2*idx+1];
		lazy[2*idx+2] = 1 - lazy[2*idx+2];
		}
	lazy[idx] = 0;
	}
if(r<startR || l>endR) return;

if(startR<=l && r<=endR)
	{
	if(l != r)
		{
		lazy[2*idx+1] = 1 - lazy[2*idx+1];
		lazy[2*idx+2] = 1 - lazy[2*idx+2];
		}
	tree[idx] = (r-l+1) - tree[idx];
	return;
	}

int mid = (l+r)/2;
update(l,     mid, startR, endR, 2*idx+1);
update(mid+1, r,   startR, endR, 2*idx+2);
tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
}

void buildTree(int *arr, int l, int r, int idx)
{
if(l==r)
	{
	tree[idx] = arr[l];
	lazy[idx] = 0;
	return;
	}

int mid = (l+r)/2;
buildTree(arr, l,     mid, 2*idx+1);
buildTree(arr, mid+1, r,   2*idx+2);

lazy[idx] = 0;
tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
}
