#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void nuclear(); int buyingSweets(int,int); void jewels();
void maxWeightDiff(); void voters(); void salary(); 
void inc(int*,int,int,int); void countSubstr(); lli substr11(int);
void cupCakes();
void mergeSort(int*,int,int); void merge(int *,int,int,int);

int main()
{
int m,n,x;
cin>>m;
while(m--)
{
cupCakes();
}
return 0;
}

void cupCakes()
{
int n,diff=INT_MAX;
cin>>n;

for(int i=sqrt(n);i>0;i--)
	{
	if(n%i == 0)
		{
		int y = n/i;
		cout<<(y-i)<<endl; break;
		}
	}
}

void countSubstr()
{
int n;
cin>>n;
string str;
cin>>str;
int count =0;
for(int i=0;i<n;i++)
	if(str[i]=='1')
		count++;

cout<<substr11(count)<<endl;
}

long long int substr11(int count) //simply "n(n+1)/2"
{
if(count==0 || count==1)
	return count;

return count + substr11(count-1);
}

void salary()
{
int n, min=INT_MAX;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    if(arr[i]<min) min = arr[i];
	}

int count =0;
for(int i=0;i<n;i++)
    {
        if(arr[i]==min) continue;
        count = count + arr[i] - min;
    }
//above loop is equivalent to "Sum(arr)-n*min"
cout<<count<<endl;
}

void inc(int *arr,int len,int num,int idx) //increment all except [idx]
{
for(int i=0;i<len;i++)
	{
	if(i==idx) continue;
	arr[i]+=num;
	}
}

void voters()
{
int n1,n2,n3,temp;
cin>>n1>>n2>>n3;

map<int,int> m;
for(int i=0;i<(n1+n2+n3);i++)
	{
	cin>>temp;
	m[temp] = m[temp]+1;
	}
map<int,int>::iterator itr;
int arr[n1+n2+n3],count=0;

for(itr=m.begin();itr!=m.end();itr++)
	{
	if(itr->second >= 2)
		{
		arr[count++] = itr->first;
		}
	}
int ans[count];
for(int i=0;i<count;i++)
	ans[i] = arr[i];
mergeSort(ans,0,count-1);

cout<<count<<endl;
for(int i=0;i<count;i++)
	cout<<ans[i]<<endl;
}

void mergeSort(int *arr,int l,int r)  //QUESTION 2.a
{
if(l>=r) return;

int mid = (l+r)/2;
mergeSort(arr,l,mid);
mergeSort(arr,mid+1,r);
merge(arr,l,mid,r);
}

void merge(int *arr,int l,int m,int r)  //QUESTION 2.b
{
int L[m-l+1+1],R[r-m+1],i,j,k=0;
//L[m-l+1] = R[r-m] = INT_MAX;
for(i=0;i<=m-l;i++)
	L[i]=arr[l+i];
L[i] = INT_MAX;

for(j=0;j<r-m;j++)
	R[j] = arr[m+1+j];
R[j] = INT_MAX;

i=j=0;
while(k<r-l+1)
{
	if(L[i]<= R[j]) {arr[l + k] = L[i++]; k++;}
	else {arr[l + k] = R[j++]; k++;}
}
}


void maxWeightDiff()
{
int n,k;
cin>>n>>k;
int w[n]={0},smaller,sum1=0,sum2=0;

for(int i=0;i<n;i++)
	cin>>w[i];

if(k<=n/2) smaller = k;
else smaller = n-k;
int i=0;

while(i<smaller)
	{
	for(int j=n-1;j>i;j--)
		{
		int temp;
		if(w[j]<w[j-1]) { temp=w[j]; w[j]=w[j-1]; w[j-1]=temp;}
		}
	i++;
	}

for(int x=0;x<smaller;x++)
	sum1+=w[x];
for(int x=smaller;x<n;x++)
	sum2+=w[x];

cout<<sum2-sum1<<endl;
}


void jewels()
{
string j,s; //jewels and stones
int count=0,index;
cin>>j>>s;
vector <int> v(52,0);

for(int i=0;i<j.length();i++)
	{
	if(j[i]>='A' && j[i]<='Z') index = j[i]-'A'+26;
	else index = j[i]-'a';
	v[index]=1;
	}
for(int j=0;j<s.length();j++)
	{
	if(s[j]>='A' && s[j]<='Z') index = s[j]-'A'+26;
	else index = s[j]-'a';

	if(v[index]==1) count++;
	}
cout<<count<<endl;
}

int buyingSweets(int n, int x)
{
int notes[101]={0},temp,sum=0;

for(int i=0;i<n;i++)
	{
	cin>>temp; notes[temp]++; sum+=temp;
	}

if(sum%x==0) return sum/x;

for(int j=1;j<=(sum%x);j++)
	{
	if(notes[j] != 0) return -1;
	}
return sum/x;
}
	
void nuclear()
{
int part,limit,n;
cin>>part>>limit>>n;
int chambers[n]={0};  //initializing all the elements to 0

while(part>0)
	{
	for(int i=0;i<n;i++)
		{
		if(chambers[i]<limit) {chambers[i]++; break;}
		
		else {chambers[i]=0; if(i==n-1) break;}
		}
	part--;
	}
for(int k=0;k<n;k++)
cout<<chambers[k]<<" ";
}
