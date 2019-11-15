#include<bits/stdc++.h>
using namespace std;

int numberOfSetBits(int);

int main()
{	
for(int i=0;i<16;i++)
 cout<<i<<" : "<<numberOfSetBits(i)<<endl;
return 0;
}

int numberOfSetBits(int x)
{
int count = 0;

while(x != 0)
	{
	count++;
	x = x & (x-1);			
	}
return count;
}
