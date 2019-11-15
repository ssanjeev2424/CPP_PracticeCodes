#include<bits/stdc++.h>
using namespace std;
void till_42(); void aMinusB(); int horses(); int johny(); int carSpeed();

int main()
{
int n;
cin>>n;
while(n--)
{
cout<<carSpeed()<<endl;
}	
return 0;
}

int carSpeed()
{
int n;
cin>>n;
int arr[n],count=1;
for(int i=0;i<n;i++)
	cin>>arr[i];

for(int i=1;i<n;i++)
{
if(arr[i-1]>=arr[i]) count++;
else arr[i]=arr[i-1];
}

return count;
}

int johny()
{
int n;
cin>>n;
int arr[n],k,item,flag;

for(int i=0;i<n;i++)
	cin>>arr[i];

cin>>k;
item = arr[k-1];

for(int i =0;i<n-1;i++)
{	flag = 0;
	for(int j=0;j<(n-i-1);j++)
	{
	if(arr[j]>arr[j+1]) { flag=1; int temp=arr[j]; arr[j]=arr[j+1];
				arr[j+1]=temp;}
	}
	if(flag==0) break;	
}

for(int i=0;i<n;i++)
{
if(arr[i]==item){ k=i+1; break;}
}

return k;
}


int horses()
{
int n;
cin>>n;
int arr[n],size=n,diff=INT_MAX;
while(n--)
	cin>>arr[n];

for(int i=0;i<size-1;i++)
	for(int j=i+1;j<size;j++)
	{
	if(abs(arr[i]-arr[j])<diff) diff=abs(arr[i]-arr[j]);
	}
return diff;
}

void aMinusB()
{
int a,b;
cin>>a>>b;
int result = abs(a-b),flag=0;

if(result%10 !=9) cout<<++result;
else cout<<--result;
}

void till_42()
{
int x;
cin>>x;
while(x!=42)
{
	cout<<x<<endl;
	cin>>x;
}
}
