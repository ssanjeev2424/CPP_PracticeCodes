#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	vector<node *> child;
	   };

void maxRem(int);
void mergeSort(int*,int,int); void merge(int *,int,int,int);
int mod(int,int);
void maxRem2(int); void strCH(); void fencing(); void fencing2();
void subRem(); void levelOrder(node *); 
//long subtreeSum(node *);
void palin(); bool pal(string); vector<string> substr(string,int,int);


int main()
{
int n=1;
//cin>>n;
//cout<<INT_MAX;
while(n--)
{
vector<string> s = substr("abcde",0,4);
for(int i=0;i<s.size();i++)
	cout<<s[i]<<" ";
cout<<"\n****************************\n";
palin();
}
return 0;
}

void palin()
{
//string s = "san",s2="jeev";
//cout<<s+s2;
string str;
cin>>str;
long count=0;

int end = str.length()-1;

for(int step=1;step<=end+1;step++)
	{
	int first=0,last=first+step;
	while(last<=end+1)
		{
		//cout<<str.substr(first,last-first)<<" ";
		string s = str.substr(first,last-first);
		vector<string> subs = substr(str,last,end);
		for(int i=0;i<subs.size();i++)
			{
			if(pal(s+subs[i])) count++;
			}
		first++; last++;
		}
	}
cout<<count;
}

vector<string> substr(string str, int l,int r)
{
vector<string> subs;

for(int step=1;step<=(r-l+1);step++)
	{
	int beg=l,end=l+step;
	while(end<=r+1)
		{
		subs.push_back(str.substr(beg, end-beg));
		beg++; end++;
		}
	}
return subs;
}

bool pal(string str)
{
int i=0,j=str.length()-1;

while(i<j)
	{
	if(str[i] != str[j])
		return false;
	i++; j--;
	}
return true;
}

void subRem()
{
int n,x;
cin>>n>>x;

struct node* ptr[n+1]={NULL};
//int arr[n+1]={-1};

for(int i=1;i<=n;i++)
	{
	ptr[i]=(struct node*)malloc(sizeof(struct node));
	cin>>ptr[i]->data;
	}
int a,b;

for(int i=1;i<=n-1;i++)
	{
	cin>>a>>b;
	(ptr[a]->child).push_back(ptr[b]);
	}

levelOrder(ptr[1]);
}

long substreeSum(node *root)
{
return 0;
}

void levelOrder(node *root)
{
if(root==NULL) return;

queue<node *> q;
q.push(root);

while(!q.empty())
	{
	int n = q.size();
	while(n>0)
		{
		node *p = q.front();
		q.pop();
		cout<<p->data<<" ";

		for(int i=0;i<(p->child).size();i++)
			q.push(p->child[i]);

		n--;
		}
	cout<<endl;
	}
}

void fencing2()
{
string s = to_string(42);
cout<<s;
}

void fencing()
{
int n,m,k,x,y;
long cost=0;
cin>>n>>m>>k;
int grid[n+2][m+2]={};

for(int i=0;i<k;i++)
	{
	cin>>x>>y;
	grid[x][y]=1;
	}

//for(int i=0;i<n+2;i++){
	//for(int j=0;j<m+2;j++){
		//cout<<grid[i][j]<<" * ";} cout<<endl;}
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
	if(grid[i][j]==0) continue;

	if(grid[i][j-1]==0) cost+=1;
	if(grid[i-1][j]==0) cost+=1;
	if(grid[i][j+1]==0) cost+=1;
	if(grid[i+1][j]==0) cost+=1;
	}
}
cout<<cost<<endl;	
}

void strCH()
{
int n,count=0,prev=-1;
cin>>n;
string str;
char x;
cin>>str>>x;

//cout<<str<<" ** "<<x<<" "<<str.size()<<endl;
//if(str[2]==x) cout<<"YES";

for(int i=0;i<n;i++)
{
	if(str[i]==x)
	{
	int a = i-(prev+1)+1;
	int b = (n-1)-i+1;
	count = count + (a*b);
	prev = i;
	}
}
cout<<"The count is: "<<count<<endl;
}

void maxRem2(int size)
{
int arr[size];

for(int i=0;i<size;i++)
	cin>>arr[i];

mergeSort(arr,0,size-1);
int max=0;
for(int j=size-2;j>=0;j--)
	{
	if(arr[size-1]==arr[j]) continue;
	max=arr[j];
	break;
	}
cout<<max<<endl;
}


void maxRem(int size)
{
int arr[size];

for(int i=0;i<size;i++)
	cin>>arr[i];

mergeSort(arr,0,size-1);

int max = INT_MIN,temp;

for(int j=size-1;j>=0;j--)
	{
	cout<<"Max is: "<<max<<" and iteration: "<<j+1<<endl;
	
	if(max >= arr[j]-1) break;

	for(int k=size-1;k>=0;k--)
		{
		if(k==j) continue;
		
		if((temp=mod(arr[k],arr[j])) == arr[k])
		    {
		        if(temp>max)
		        {
		            max=temp;
		        }
		        break;
		    }
		    
		 if(temp>max) max=temp;
		}
	}
cout<<max<<endl;
}

int mod(int a, int m)
{
if(a<m) return a;
if(a==m) return 0;

int half = a/2;
int smallAns = mod(half,m)%m;

if(a%2==0) return (smallAns+smallAns)%m;
return (smallAns+smallAns+1%m)%m;
}

void mergeSort(int *arr,int l,int r)
{
if(l>=r) return;

int mid = (l+r)/2;
mergeSort(arr,l,mid);
mergeSort(arr,mid+1,r);
merge(arr,l,mid,r);
}

void merge(int *arr,int l,int m,int r)
{
int L[m-l+1+1],R[r-m+1],i,j,k=0;
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
