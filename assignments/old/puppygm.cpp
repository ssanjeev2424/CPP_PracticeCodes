#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
int t,a,b; bool flag; cin>>t;
while(t--)
	{
	flag=true; // true means Tuzik wins
	cin>>a>>b;
	while(true)
		{
		if(a==2 || b==2) break;
		if((a==1 && b==1)||(a==1 && b==3)||(a==3 && b==1))
			{ flag = !flag; break; }
		
		
		//yet to be coded
		}
	
	if(flag) cout<<"Tuzik"<<endl;
	else cout<<"Vanka\n";
	}
return 0;
}
