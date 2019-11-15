#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main()
{
int t; cin>>t;
while(t--)
	{
	int max = 0, flag = 0;
	map<string,int> m; string str, colors[6], zz;
	for(int i=0;i<6;i++)
		{
		cin>>str; colors[i] = str;
		if(m.count(str))
			{
			m[str]++;
			if(m[str] > max) { max = m[str]; zz = str; }
			}
		else
			m[str] = 1;
		}
		
	if(max < 3) cout<<"NO\n";
	else if(max > 4) cout<<"YES\n";
	else
		{
		for(int i=0;i<6;i+=2)
			{
			if(colors[i]==zz || colors[i+1]==zz) continue;
			else { flag = 1; break; }
			}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
		}
	}
return 0;
}
