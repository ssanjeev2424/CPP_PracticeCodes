#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf (1<<20)
struct query
	{
	int l,r,c;
	};

lli knapSack(int vajan[], lli munaafa[], int aukaat, int idx, int len);
lli dp[100001][501],l,r,c,minn,tree[400020],arr[100005];
lli knap[100005][505];
int comp(const void *p1, const void *p2) //for Increasing order of cost
	{                                    // "c" in qsort
	struct query *f = (struct query *)p1;
	struct query *s = (struct query *)p2;
	
	if(f->c < s->c) return -1;
	if(f->c > s->c) return 1;
	return 0;
	}

void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	tree[node]=inf;
	if(start==end)
		return;
	init(2*node,start,(start+end)/2);
	init(2*node+1,((start+end)/2)+1,end);
	return;
}
void update(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		tree[node]=min(tree[node],c);
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,((start+end)/2)+1,end);
	return;
}
lli traverse(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
		return inf;
	if(start==end && start==l)
	{
		minn=min(minn,tree[node]);
		return minn;
	}
	if(start!=end)
	{
		lli tl=traverse(2*node,start,(start+end)/2);
		lli tr=traverse(2*node+1,((start+end)/2) + 1,end);
		minn=min(minn,min(tree[node],min(tl,tr)));
	}
	else
		minn=min(minn,tree[node]);
	return minn;
}
 
int main()
{
int t; cin>>t;
//struct query q[100005];

while(t--)
	{
	int n,k,m; lli ans = 0;
	int minCost[100005];
	cin>>n>>k>>m;
	minCost[n] = arr[n] = inf;
	
	for(int i=0;i<n;i++)
		{ cin>>arr[i]; ans += arr[i]; }
	
	init(1,0,n-1);	
		
	int /*l,r,*/idx=0;
	for(int i=0;i<m;i++)
		{
		cin>>l>>r>>c;
		l--; r--;
		update(1,0,n-1);
		}
	for(int i=0;i<n;i++)
		{
		l=r=i; minn = inf;
		minCost[i] = traverse(1,0,n-1);
		}
	
	/*qsort(q, m ,sizeof(struct query), comp);//acc to cost

	for(int i=0;i<n;i++) //filling up the minCost array
		{
		if(arr[i] < 0)
			{
			for(int j=0;j<m;j++)
				{
				if(i>=q[j].l && i<=q[j].r)
					{
					arr[idx] = -arr[i];
					minCost[idx++] = q[j].c;
					break;
					}
				}
			}
		}*/
	for(int i=0;i<n;i++)
		{
		if(arr[i]<0 && minCost[i]!=inf)
			arr[idx]=-1*arr[i], minCost[idx++]=minCost[i];
		}
	
		
	//problem reduces to 0-1 KNAPSACK, i.e BUDGET:k, we want to include
	// as many -ve rating dishes as we could, that too optimally so that
	// the profit(-ve rating reduced is maximum)
	
	for(int i=0;i<=idx;i++)
		for(int j=0;j<=k;j++)
			dp[i][j] = -1;
	
	lli boj = knapSack(minCost,	arr, k, 0, idx);
	
	/*for(int i=0;i<=idx;i++)
		{
		for(int w=0;w<=k;w++)
			{
			if(i==0 || w==0)
				knap[i][w] = 0;
			else
				{
				lli temp = minCost[i-1]; //weight of current
				if(temp <= w)
					{
					if(arr[i-1]+knap[i-1][w-temp] > knap[i-1][w])
						knap[i][w] = arr[i-1]+knap[i-1][w-temp];
					else
						knap[i][w] = knap[i-1][w];
					}
				else
					knap[i][w] = knap[i-1][w];
				}
			}
		}*/
		
	//cout<<ans+knap[idx][k]<<endl;
	cout<<ans+boj<<endl;	
	}
return 0;
}
//vajan-minCost array, munaafa-array arr, chanda- -ve values captured,
// aukaat-k, 
lli knapSack(int vajan[], lli munaafa[], int aukaat, int idx, int len)
{
if(idx==len || aukaat==0) return 0;

if(dp[idx][aukaat] != -1) return dp[idx][aukaat];

lli ans1=0,ans2=0;

ans1 = knapSack(vajan,munaafa,aukaat,idx+1,len);
if(vajan[idx] <= aukaat)
	ans2 = munaafa[idx] + knapSack(vajan,munaafa,aukaat-vajan[idx],idx+1,len);

return dp[idx][aukaat] = max(ans1,ans2);
}
