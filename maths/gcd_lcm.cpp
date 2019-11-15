#include<bits/stdc++.h>
using namespace std;

class gcd_lcm
{
public:
	int gcd(int a, int b)
	{
	if(a==0 || b==0) return 0;
	
	if(a==b) return a;

	if(a>b) return gcd(a-b,b);

	return gcd(a,b-a);
	}

	int lcm(int a, int b)
	{
	return (a*b)/gcd(a,b);
	}
};

int main()
{
gcd_lcm obj;
cout<<obj.gcd(15,20)<<"<--GCD **(15,20)** LCM-->"<<obj.lcm(15,20)<<endl;
return 0;
}
