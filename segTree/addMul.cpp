#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007

void build(lli*,int,int,int); lli sum(int,int,int,int,int);
void operation(int, int, int, int, int); lli modu(lli a);
void update(int,int,int,int,int,int,int);

lli tree[4*100001];
string str[4*100001]; vector<lli> vec[4*100001];

int main()
{
int n,q; scanf("%d %d",&n,&q);
lli arr[n];
for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

build(arr,0,n-1,0);

lli bit,x,y,v;
for(int i=0;i<q;i++)
	{
	scanf("%lld",&bit);
	if(bit!=4)
		{
		scanf("%lld %lld %lld",&x,&y,&v);
		update(0,n-1,x-1,y-1,0,bit,v);
		}
	else
		{
		scanf("%lld %lld",&x,&y);
		cout<<sum(x-1,y-1,0,n-1,0)<<endl;
		}
	}

return 0;
}
//*************************UPDATE*************************

void update(int l,int r,int startR, int endR,int idx,int op,int val)
{
int len = str[idx].length();
if(len != 0)
	{
	for(int i=0;i<len;i++)
		operation(l,r,idx,str[idx][i]-'0',i);
	
	if(l != r)
		{
		str[2*idx+1] += str[idx];
		str[2*idx+2] += str[idx];
		
		for(int i=0;i<len;i++)
			{
			vec[2*idx+1].push_back(vec[idx][i]);
			vec[2*idx+2].push_back(vec[idx][i]);
			}
		}
	str[idx] = "";
	vec[idx].clear();
	}

if(r<startR || l>endR) return;

if(startR<=l && r<=endR)
	{
	if(l != r)
		{
		char s = op + '0';
		str[2*idx+1] += s;
		str[2*idx+2] += s;
		
		vec[2*idx+1].push_back(val);
		vec[2*idx+2].push_back(val);
		}
		
	if(op==1)
		tree[idx] = ( tree[idx]%MOD + ((lli)(r-l+1)*val)%MOD )%MOD;
	else if(op==2)
		tree[idx] = (tree[idx]%MOD * val )%MOD;
	else
		tree[idx] = ((lli)(r-l+1)*val)%MOD;
	
	return;
	}

int mid = (l+r)/2;
update(l,     mid, startR, endR, 2*idx+1, op, val);
update(mid+1, r,   startR, endR, 2*idx+2, op, val);

tree[idx] = ( tree[2*idx+1]%MOD + tree[2*idx+2]%MOD )%MOD;
}
//**********************SUM*************************

lli sum(int lb, int ub, int l, int r, int idx)
{
int len = str[idx].length();
if(len != 0)
	{
	for(int i=0;i<len;i++)
		operation(l,r,idx,str[idx][i]-'0',i);
	
	if(l != r)
		{
		str[2*idx+1] += str[idx];
		str[2*idx+2] += str[idx];
		
		for(int i=0;i<len;i++)
			{
			vec[2*idx+1].push_back(vec[idx][i]);
			vec[2*idx+2].push_back(vec[idx][i]);
			}
		}
	str[idx] = "";
	vec[idx].clear();
	}

if(l>ub || r<lb) return 0;

if(lb<=l && r<=ub) return tree[idx];

int mid = (l+r)/2;

return (sum(lb,ub,l,mid,2*idx+1)%MOD + sum(lb,ub,mid+1,r,2*idx+2)%MOD)%MOD;
}

//*************OPERATION********************

void operation(int l, int r, int idx, int op, int i)
{
if(op==1)
	tree[idx] = (tree[idx]%MOD + ( ((lli)(r-l+1))%MOD * (vec[idx][i]) )%MOD)%MOD;
else if(op==2)
	tree[idx] = (tree[idx]%MOD * vec[idx][i] )%MOD;
else
	tree[idx] = ((lli)(r-l+1)*vec[idx][i])%MOD;
}

//*************************BUILD*******************
void build(lli *arr, int l, int r, int idx)
{
if(l==r)
	{
	tree[idx] = arr[l];
	str[idx]  = "";
	return;
	}

int mid = (l+r)/2;
build(arr, l,     mid, 2*idx+1);
build(arr, mid+1, r,   2*idx+2);

str[idx] = "";
tree[idx] = (tree[2*idx + 1]%MOD + tree[2*idx + 2]%MOD)%MOD;
}
//********************************************************
lli modu(lli a)
{
if(a<MOD) return a;
if(a==MOD) return 0;

lli smallAns = modu(a>>1)%MOD;

if(a&1) return (smallAns+smallAns+1)%MOD;
return (smallAns+smallAns)%MOD;
}
