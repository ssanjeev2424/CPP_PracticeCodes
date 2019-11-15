#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

bool isPalin(string str)
{
int i=0,j=str.length()-1;

while(i<j)
	{
	if(str[i]!=str[j]) return false;
	i++; j--;
	}
return true;
}

void solve(string str)
{
int x = 0, i = 0, j = str.length()-1;

while(i<j)
	{
	if(str[i]==str[j]) { i++; j--; }
	else
		{
		 if(isPalin(str.substr(i,j-i)) || isPalin(str.substr(i+1,j-i)))
		 	{ cout<<"YES\n"; return; }
		 else
		 	{ cout<<"NO\n"; return; }
		}
	}
cout<<"YES\n";
}


int main()
{
int t; cin>>t;
while(t--)
	{
	string str; cin>>str;
	solve(str);
	}
return 0;
}
