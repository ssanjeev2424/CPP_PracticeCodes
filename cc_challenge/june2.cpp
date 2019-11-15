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

void money(); void zeroCase(lli *, int , int);

int main()
{
int t; cin>>t;
while(t--) money();
return 0;
}

void money()
{
int n,k,x,idx=1,posD=0,negD=0; cin>>n;
lli arr[n+1],ordered[n+1][2]; //ordered contains real value, nd diff
set<pair<int,int>, mycomp2<pair<int,int> > > s;

for(int i=1;i<=n;i++)
	cin>>arr[i];
cin>>k>>x;

if(x==0)
	{
	zeroCase(arr,n,k);
	return;
	}

for(int i=1;i<=n;i++)
	{
	int diff = (arr[i]^x)-arr[i];
	if(diff>0) posD++; //means number increased after XOR
	else negD++;
	s.insert({arr[i],diff});
	}

for(auto &i:s)
	{ ordered[idx][0]=i.first; ordered[idx++][1]=i.second; }
	
lli sum = 0;

if(k==n)
	{
	lli sum1=0, sum2=0;
	for(int i=1;i<=n;i++) sum1 += arr[i];
	for(int i=1;i<=n;i++) sum2 += ordered[i][0] + ordered[i][1];
	if(sum1>=sum2) cout<<sum1<<endl;
	else cout<<sum2<<endl;
	return;
	}

if(k%2==1)
	{
	for(idx=1;idx<=posD;idx++)
		sum += ordered[idx][0] + ordered[idx][1];
	for(;idx<=n;idx++)
		sum += ordered[idx][0];
	cout<<sum<<endl;
	return;
	}

//k is even
if(posD%2==0)
	{
	for(idx=1;idx<=posD;idx++)
		sum += ordered[idx][0] + ordered[idx][1];
	for(;idx<=n;idx++)
		sum += ordered[idx][0];
	cout<<sum<<endl;
	return;
	}

//posD is odd and k is even
for(idx=1;idx<posD;idx++)
	sum += ordered[idx][0] + ordered[idx][1];
for(idx=posD+2;idx<=n;idx++)
	sum += ordered[idx][0];

lli temp;
if(posD==n) temp = ordered[posD][0];
else temp = max(ordered[posD][0]+ordered[posD+1][0], ordered[posD][0]+ordered[posD+1][0] + ordered[posD][1]+ordered[posD+1][1]);

cout<<sum+temp<<endl;
}

void zeroCase(lli *arr, int n, int k)
{
lli sum = 0;
for(int i=1;i<=n;i++)
	sum += arr[i];
cout<<sum<<endl;
}
