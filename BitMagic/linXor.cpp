#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

string binary(lli);
int cnt;

lli decimal(string str)
{
int i=0; lli res = 0;
for(int idx=str.length()-1;idx>=0;idx--,i++)
	{
	if(str[idx]=='1') res += (lli)pow(2,i);
	}
return res;
}

int main()
{
int t, flag, flag2; cin>>t;
while(t--)
	{
	lli a,b;
	cin>>a>>b;
	
	if(a==b) { cout<<0<<endl; continue; }
	
	if(a>b)
	{
	    lli tempo = a;
	    a = b;
	    b = tempo;
	}
	
	lli ans = 0, x, ones; string str = "";
	/*for(lli i=0;i<=100;i++)
		{
		cout<<" Binary: "; binary(i); cout<<s<<" "<<i<<endl;
		ans ^= i;
		}*/
	
	//string str1 = binary(a);
	string str2 = binary(b);
	//cout<<"cnt: "<<cnt<<endl;
	if(a&1)
		{
		x = a;
		ones = (1 + (b-x)/2);
		}
	else
		{
		x = a + 1;
		ones = (1 + (b-x)/2);
		}
		
	if(ones&1) str = "1"; //for LSB
	else str = "0";
	//cout<<"0th: "<<ones<<endl;
	
	for(lli i=1;i<cnt;i++)
		{
		lli temp = (lli)pow(2,i);
		ones = 0;
		if( (a/temp)&1 ) // 1 in a
			{
			ones = temp - a%temp;
			x = a + ones - 1;
			
			if(x > b)
				{
				ones = b - a + 1;
				}
			else
				{
				if( ((b-x)/temp)%2==0 ) ones += ((b-x)/(temp*2))*temp;
				else
					{
					if( (b-x)%temp != 0 )
						{
						ones += ((b-x)/(temp*2))*temp;
						ones += b%temp + 1;
						}
					else
						ones += ((b-x)/(temp*2))*temp;
					}
				}
			}
		else
			{
			x = a - a%temp - 1;
			if( ((b-x)/temp)%2==0 ) ones += ((b-x)/(temp*2))*temp;
				else
					{
					if( (b-x)%temp != 0 )
						{
						ones += ((b-x)/(temp*2))*temp;
						ones += b%temp + 1;
						}
					else
						ones += ((b-x)/(temp*2))*temp;
					}
			}
		//cout<<i<<"th: "<<ones;
		//if(ones&1) ans |= (lli)(1<<i);
		if(ones&1) str = "1" + str;
		else str = "0" + str;
		//cout<<" ans: "<<str<<endl;
		}
	//string f = "";//binary(ans);
	lli res = decimal(str);
	cout<<"string: "<<str<<" Ans1: ";
	cout<<res<<endl;
	
	ans = 0;
	for(lli i=a;i<=b;i++)
		ans ^= i;
	string f = binary(ans);
	cout<<"string: "<<f<<" Ans2: "<<ans<<endl;
	}
	//cout<<(lli)pow(2,49)<<endl<<(lli)pow(2,48)<<endl;
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
