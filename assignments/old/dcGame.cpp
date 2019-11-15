#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

lli arr[1000005],stock1[1000005],stock2[1000005],sum[1000005];
stack<lli> stk1,stk2;

struct Node {
	lli val;
	lli cnt;
	
	Node(lli x, lli y) {
	val = x; cnt = y;
	}
};

//struct comp {
	bool comp(Node &a, Node &b) {
	return (a.val < b.val);
	}
//};

vector<Node> vec;

int main()
{
lli n,m,k,max=0; cin>>n>>m;
for(int i=1;i<=n;i++)	cin>>arr[i];
memset(stock1, 0, sizeof(stock1));
memset(stock2, 0, sizeof(stock2));

stk1.push(-1); stk1.push(1); stock1[1] = 1;

for(int i=2;i<=n;i++)
	{
	lli ans = 1, idx = i - 1, cnt = 0;
	while(arr[idx] <= arr[i] && idx > 0)
		{
		ans += stock1[idx];
		cnt++;
		idx -= stock1[idx];
		}
	for(int j=0;j<cnt;j++)
		stk1.pop();
	stk1.push(ans);
	stock1[i] = ans;
	}

stk2.push(-1); stk2.push(1); stock2[n] = 1;

for(int i=n-1;i>=1;i--)
	{
	lli ans = 1, idx = i+1, cnt = 0;
	while(arr[idx] <= arr[i] && idx <= n)
		{
		ans += stock2[idx];
		cnt++;
		idx += stock2[idx];
		}
	
	for(int j=0;j<cnt;j++)
		stk2.pop();
	stk2.push(ans);
	stock2[i] = ans;
	}



for(int i=1;i<=n;i++)
	vec.push_back(Node(arr[i], stock1[i]*stock2[i]));

sort(vec.begin(), vec.end(), comp);
	
for(int i=0;i<n;i++)
	cout<<vec[i].val<<":"<<vec[i].cnt<<" ** "; cout<<endl;

sum[1] = vec[0].cnt; arr[1] = vec[0].val; sum[0] = 0;
for(int i=1;i<n;i++)
	{
	arr[i+1] = vec[i].val;
	sum[i+1] += vec[i].cnt + sum[i];
	}

//for(int i=1;i<=n;i++)
	//cout<<"arr[i]: "<<arr[i]<<" cnt: "<<sum[i]<<endl;

arr[n+1] = INT_MAX;
char c,x1,x2; string str = "";
for(int i=0;i<m;i++)
	{
	cin>>c>>k>>x1;
	
	if(x1=='D') x2 = 'C';
	else x2 = 'D';
	
	lli temp;
	
	if(c=='=')
		{
		int l = lower_bound(arr+1, arr+n+1, k) - (arr+1);
		int r = upper_bound(arr+1, arr+n+1, k) - (arr+1);
		
		if(arr[l+1] != k) temp = 0;
		else if(r==n) temp = sum[n] - sum[l+1-1];
		else temp = sum[r+1-1] - sum[l+1-1];
		
		cout<<"i:"<<i+1<<" temp:"<<temp<<endl;
		if(temp&1) str += x1;
		else str += x2;
		}
	else if(c=='>')
		{
		int l = upper_bound(arr+1, arr+n+1, k) - (arr+1);
		
		if(l==n) temp = 0;
		else temp = sum[n] - sum[l+1-1];
		
		cout<<"i:"<<i+1<<" temp:"<<temp<<endl;
		if(temp&1) str += x1;
		else str += x2;
		}
	else // '<'
		{
		int l = lower_bound(arr+1, arr+n+1, k) - (arr+1);
		
		if(l==0) temp = 0;
		else temp = sum[l+1-1];
		
		cout<<"i:"<<i+1<<" temp:"<<temp<<<endl;
		if(temp&1) str += x1;
		else str += x2;
		}
	}
cout<<str<<endl;
return 0;
}
