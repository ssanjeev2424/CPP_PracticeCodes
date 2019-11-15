#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

bool isPalin(int num)
{
int rev = 0, x = num;
while(num)
	{
	rev = rev*10 + num%10;
	num /= 10;
	}
return (rev == x);
}

bool prime(int num)
{
for(int i=2;i<=sqrt(num);i++)
	if(num%i==0) return false;
return true;
}

int main()
{
int n; cin>>n;
if(n%2==0) n++;

while(true)
	{
	if(prime(n))
		{
		if(isPalin(n))
			{
			cout<<n<<endl;
			break;
			}
		}
	n += 2;
	}
	
return 0;
}

