#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//lli power(lli);
int setBits(int); void binary(int);
map<int,int> m;
bool arr[131080];

int main()
{
int t; cin>>t;
while(t--)
	{
	int q,x,e=0,o=0,bits; cin>>q;
	memset(arr,false,sizeof(arr));
	m.clear();
	cin>>x;
	bits = setBits(x);
	arr[x] = true;
	if(bits&1) { o++; m[x] = 1; }
	else { e++; m[x] = 2; }
	
	cout<<e<<" "<<o<<endl;
	
	for(int i=1;i<q;i++)
		{
		cin>>x;
		if(!arr[x])
			{
			arr[x] = true;
			bits = setBits(x);
			if(bits&1) { o++; m[x] = 1; }
			else { e++; m[x] = 2; }
			//cout<<"Outside..";
			bits = m[x];
			
			for(auto y: m)
				{
				if(y.first==x) continue;
				
				int temp = (x^(y.first));
				if(!arr[temp])
					{
					arr[temp] = true;
					if((bits+y.second)&1) { o++; m[temp] = 1; }
					else { e++; m[temp] = 2; }
					//cout<<"Inside..("<<y.first<<") ";
					}
				
				}
			//cout<<endl;
			}
		/*cout<<"*********************"<<x<<"*******************\n";
		for(auto y: m)
			cout<<y.first<<"("<<y.second<<") "; cout<<endl;*/
		cout<<e<<" "<<o<<endl;
		}
	}
return 0;
}

int setBits(int x)
{
int count = 0;
while(x)
	{
	count++;
	x = (x&(x-1));
	}
return count;
}

void binary(int x)
{
string str = "";
int x2 = x;
while(x)
	{
	if(x%2==0) str = '0' + str;
	else str = '1' + str;
	x /= 2;
	}
cout<<"binary form of "<<x2<<" : "<<str<<endl;
}

/*
lli power(lli x)
{
if(x<18) return (lli)pow(10,x);

lli smallAns = power(x/2)%n;

if(x&1) return ( (smallAns*smallAns)%n * 10%n )%n;
return (smallAns*smallAns)%n;
}


cin>>n; double coins[n]; double temp,sum=0, mean; 
	for(int i=0;i<n;i++) { cin>>coins[i]; sum += coins[i]; }
	
	mean = sum/n;
	int idx = -1;
	for(int i=0;i<n;i++)
		if(coins[i]==mean)
			{ idx = i+1; break; }
	
	if(idx == -1)
		cout<<"Impossible\n";
	else
		cout<<idx<<endl;


cin>>n; lli sum, idx = 1;
	string str; cin>>str;
	
	lli len = str.length(), dgt;
	sum = (str[len-1]-'0')%n;
	
	for(lli i=len-2;i>=0;i--,idx++)
		{
		dgt = str[i]-'0';
		sum = (sum + ( power(idx)*dgt )%n )%n;
		}
		
	if(sum==0)
		{
		cout<<0<<endl;
		continue;
		}
		
	lli rem = n - sum;
	if(rem==sum)
		cout<<2*rem-1<<endl;
	else
		{
		if(rem > sum) rem = sum;
		cout<<2*rem<<endl;
		}
*/
