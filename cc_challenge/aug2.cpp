#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
string binary(lli); int cnt;
lli y[1048600],temp[1048600],idx[1048600],arr[100001],XOR[100001];
bool found[1048600];

int main()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n; lli ans = 0, x;
	for(int i=0;i<n;i++) cin>>arr[i];
	//cout<<binary(1000000)<<endl<<cnt<<endl; //2^20 == 1048576
	
	//memset(idx,-1,sizeof(idx));
	memset(y,0,sizeof(y));
	memset(temp,0,sizeof(temp));
	memset(found, false, sizeof(found));
	
	XOR[0] = arr[0];
	idx[arr[0]] = 0; found[arr[0]] = true;
	
	for(int i=1;i<n;i++)
		{
		XOR[i] = XOR[i-1]^arr[i];
		
		if(XOR[i]==0)
			{
			if(temp[0]==0)
				{
				ans += i;
				temp[0] = i; y[0] = 1; idx[0] = i;
				}
			else
				{
				temp[0] += y[0] + (y[0]+1)*(i-idx[0]-1);
				ans += temp[0];
				y[0]++; idx[0] = i;  
				}
			}
		else
			{
			if(found[XOR[i]]==false)
				{
				found[XOR[i]] = true;
				idx[XOR[i]] = i;
				}
			else
				{
				temp[XOR[i]] += y[XOR[i]] + (y[XOR[i]]+1)*(i-idx[XOR[i]]-1);
				ans += temp[XOR[i]];
				y[XOR[i]]++; idx[XOR[i]] = i;
				}
			}
		}
	//for(int i=0;i<n;i++) cout<<XOR[i]<<" "; cout<<endl;
	cout<<ans<<endl;
	}
return 0;
}

string binary(lli x)
{
string str = ""; cnt = 0;
while(x)
	{
	cnt++;
	str = to_string(x%2) + str;
	x = x>>1;
	}
/*for(lli i=0;i<(7-str.length());i++)
	cout<<" ";*/
return str;
}

/*    2^20 == 1048576
string str; cin>>str;
	bool ok = true;
	int len = str.length();
	
	for(int i=0;i<len;i++)
		{
		//cout<<"i:"<<i<<" str[i]:"<<str[i]<<endl;
		if(str[i]=='1')
			{
			ok = true;
			if(i != len-1)
				if(str[i+1]=='1') str[i+1] = '0';
				else str[i+1] = '1';
			}
		else
			ok = false;
		}
	
	if(ok) cout<<"WIN\n";
	else cout<<"LOSE\n";
*/
