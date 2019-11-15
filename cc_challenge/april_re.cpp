#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void palin(); bool palD(string); void subtree(); void dfs(int,int);

lli dpTree[100001],arrTree[100001],x; vector<int> child[100001];
bool pal[1001][1001];

int main() {
	// your code goes here
//int n;
//cin>>n;
//while(n--)
	//{
	memset(pal,false,sizeof(pal));
	palin();
	//}
return 0;
}

void subtree()
{
int n;
cin>>n>>x;

for(int i=1;i<=n;i++)
	{
	cin>>arrTree[i];
	child[i].clear();
	dpTree[i]=-1;
	}

int a,b;
for(int j=1;j<n;j++)
	{
	cin>>a>>b;
	child[a].push_back(b);
	child[b].push_back(a);
	}

dfs(1,-1);
cout<<((dpTree[1]>=-x)?dpTree[1]:-x)<<endl;
}

void dfs(int current, int parent)
{
lli ans = arrTree[current];

for(int i=0;i<child[current].size();i++)
	{
	if(child[current][i] != parent)
		{
		int childNode = child[current][i];
		dfs(childNode,current);
		ans += dpTree[childNode];
		}
	}
dpTree[current] = (ans>=-x)?ans:-x;
//cout<<"dp["<<current<<"]="<<dpTree[current]<<" and node value:"<<arrTree[current]<<endl;
}

void palin()
{
string str;
cin>>str;
int len = str.length();

for(int i=0;i<len;i++)
	pal[i][i] = true;

for(int i=0;i<len-1;i++)
	{
	if(str[i]==str[i+1]) pal[i][i+1] = true;
	}

for(int step=2;step<len;step++)
{
int l=0,r=step;
while(r<len)
	{
	if(str[l]==str[r] && pal[l+1][r-1])
		pal[l][r] = true;
	
	l++; r++;
	}
}

/*for(int i=0;i<len;i++)
	{
	for(int j=0;j<len;j++)
		cout<<"("<<i<<","<<j<<"):"<<pal[i][j]<<" ";
	cout<<endl;
	}*/

int startsAt[1001][1001], endsAt[1001][1001];
memset(startsAt,0,sizeof(startsAt));
memset(endsAt,0,sizeof(endsAt));

for(int i=0;i<len;i++)
	{
	startsAt[i][i] = 1;
	for(int j=i+1;j<len;j++)
		{
		if(pal[i][j])
			startsAt[i][j] = startsAt[i][j-1] + 1;
		else
			startsAt[i][j] = startsAt[i][j-1];
		}
	}
/*cout<<"**************************\n";
for(int i=0;i<len;i++)
	{
	for(int j=0;j<len;j++)
		cout<<"("<<i<<","<<j<<"):"<<startsAt[i][j]<<" ";
	cout<<endl;
	}*/

for(int i=len-1;i>=0;i--)
	{
	endsAt[i][i] = 1;
	for(int j=i-1;j>=0;j--)
		{
		if(pal[j][i])
			endsAt[j][i] = endsAt[j+1][i] + 1;
		else
			endsAt[j][i] = endsAt[j+1][i];
		}
	}
/*cout<<"**************************\n";
for(int i=0;i<len;i++)
	{
	for(int j=0;j<len;j++)
		cout<<"("<<i<<","<<j<<"):"<<endsAt[i][j]<<" ";
	cout<<endl;
	}
cout<<"**************************\n";*/
lli count = 0;
for(int i=0;i<len;i++)
	{
	for(int j=i+1;j<len;j++)
		{
		int l=i,r=j;
		while(str[l]==str[r] && l<r)
			{
			count += 1;
			if(l+1 != r)
				{
				count += startsAt[l+1][r-1] + endsAt[l+1][r-1];
				l++; r--;
				}
			else
				break;
			}
		}
	}

cout<<count;
}

bool palD(string str)
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


