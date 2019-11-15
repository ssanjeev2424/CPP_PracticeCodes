#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define M 1000000007
#define SIZE 1000000001

int gcd(int,int); void gcdSum(int); void divisors(int,int,int);
int gcdMax;
unordered_set<int> fact[10][100001];


int main()
{ int t; cin>>t; for(int i=0;i<t;i++) gcdSum(i); return 0; }

void gcdSum(int t)
{
int n; cin>>n;
int arr[n];
for(int i=0;i<n;i++) scanf("%d",&arr[i]);

for(int i=0;i<n;i++)
	divisors(arr[i],i+1,t);

gcdMax = 0;
cout<<"*********************************\n";

}

void divisors(int num, int idx, int t)
{
	for(int i=1;i<=sqrt(num);i++)
	{
		if(num%i == 0)
		{
		int temp = num/i;
		fact[t][idx].insert(i);
		
		if(fact[t][idx].find(temp)==fact[t][idx].end())
			fact[t][idx].insert(temp);
		}
	}
	for(auto it = fact[t][idx].begin();it!=fact[t][idx].end();it++)
		cout<<*it<<" ";
	cout<<endl;
}

int gcd(int a, int b)
{
if(b==0) return a;

return gcd(b, a%b);
}
