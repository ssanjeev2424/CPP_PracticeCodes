#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
using namespace std;
void reduce(int); void binary();

int main()
{
int t;
cin>>t;
while(t--)
	{
	/*int n;
	cin>>n;*/
	binary();
	}
return 0;
}

void binary()
{
    int n,z;
    cin>>n>>z;
    int a[n],b[n],captured1s = 0,consecutive1s=0,flag=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1) captured1s+=1;
    }
    int no_of_1s = captured1s;
    for(int j=0;j<z;j++)
    {
        captured1s = no_of_1s;
        consecutive1s = 0;
       for(int i=0;i<n-1;i++)
       {
           if(captured1s==0) break;
           
           if(a[i]==1)
           {
              if(flag==1) consecutive1s++;
              captured1s--;
              continue;
           }
           else
           {
           	   flag=0;
               if(a[i+1]==0) continue;
               
               a[i] = 1; a[i+1] = 0;
               i++;
               captured1s--;
           }
       }
       if(consecutive1s==no_of_1s)
       		break;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void reduce(int n)
{
lli arr[n+1];
for(int i=1;i<=n;i++)
	arr[i] = i;

while(n!=1)
	{
	int i=1,j=n;
	while(i<j)
		{
		arr[i] = (arr[i]+arr[j]+arr[i]*arr[j])%MOD;
		i++; j--;
		}
	if(i==j)
		n = n/2 + 1;
	else
		n = n/2;
	}
cout<<arr[1]<<endl;
}
