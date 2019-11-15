#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

unordered_set<int> elem[4001];
int arr[1001], t, n;

void build(int,int,int); unordered_set<int> find(int,int,int,int,int);

int main()
{
cin>>t;
while(t--)
	{
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<=4*n;i++) elem[i].clear();
	
	build(0,n-1,0);
	
	/*for(int i=0;i<5;i++)
	{
	int a,b; cin>>a>>b;
	unordered_set<int> s = find(0,n-1,a,b,0);
	for(auto x: s)
		cout<<x<<" ";
	cout<<endl;
	}*/
	
	lli count = 0;
	
	for(int step=0;step<n-1;step++)
		{
		int i=0, j=i+step;
		
		while(j<n-1)
			{
			unordered_set<int> s1 = find(0,n-1,i,j,0);
			
			int rem = n-1-j;
			for(int step2=0;step2<rem;step2++)
				{
				int k=j+1; int l = k+step2, flag;
				
				while(l<n)
					{
					flag = 0;
					unordered_set<int> s2 = find(0,n-1,k,l,0);
					for(auto x: s2)
						if(s1.count(x)) { flag=1; break; }
					
					if(!flag) count++;
					
					k++; l++;
					}
				}
			i++; j++;
			}
		}
	cout<<count<<endl;
	}
return 0;
}

unordered_set<int> find(int l, int r, int lb, int ub, int idx)
{
unordered_set<int> s;

if(r<lb || ub<l) return s;

if(lb<=l && r<=ub) return elem[idx];

int mid = (l+r)/2;
unordered_set<int> s1 = find(l,     mid, lb, ub, 2*idx+1);
unordered_set<int> s2 = find(mid+1, r,   lb, ub, 2*idx+2);

for(auto x: s1)
	s.insert(x);
for(auto x: s2)
	s.insert(x);

return s;
}

void build(int l, int r, int idx)
{
if(l>r) return;

if(l==r)
	{
	elem[idx].insert(arr[l]);
	return;
	}

int mid = (l+r)/2;
build(l,     mid, 2*idx+1);
build(mid+1, r,   2*idx+2);

for(auto x: elem[2*idx+1])
	elem[idx].insert(x);
for(auto x: elem[2*idx+2])
	elem[idx].insert(x);
}
