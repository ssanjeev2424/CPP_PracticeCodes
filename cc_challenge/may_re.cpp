#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
void reduceTo1();

int main()
{
reduceTo1();
return 0;
}

//practice game theory questions. then solve "https://www.codechef.com/MAY19B/problems/MATCHS"

void reduceTo1()
{
//as the answer set is same, so solve it once, nd later use that for all the test cases. no need for separate computation for every test case
int t,n;
cin>>t;
lli arr[1000001];
arr[0]=1;
for(int i=1;i<1000001;i++)
	arr[i] = (arr[i-1]*i)%MOD;

while(t--)
	{
	cin>>n;
	cout<<(arr[n+1]-1)<<endl;
	}
}
