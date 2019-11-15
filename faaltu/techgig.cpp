#include<bits/stdc++.h>
using namespace std; void game();
void mergeSort(int*,int,int); void merge(int *,int,int,int);
void roadies(); void test(); int maxSubsetSum(int*,int,int,int,string);

unordered_map<string,int> m[101];

int main()
{ 
    int n; cin>>n; 
	while(n--)
	{
	roadies();
	//test();
	}
    return 0; 
}

void roadies()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<maxSubsetSum(arr,0,n,0,"**********")<<endl;
}

int maxSubsetSum(int *arr,int idx,int len,int sum,string str)
{
if(idx>=len) return sum;

//if(m[idx].find(str) != m[idx].end()) return m[idx][str];

int num = arr[idx]; string temp = "**********";
while(num != 0)
	{
	int digit = num%10;
	if(temp[digit]=='*') temp[digit]=digit-'0';
	num = num/10;
	if(temp=="0123456789") break;
	}

bool conflict = false;
for(int i=0;i<10;i++)
	{
	if(str[i]!='*' && temp[i]!='*')
		{
		conflict = true;
		break;
		}
	}

if(conflict)
	return m[idx][str] = maxSubsetSum(arr,idx+1,len,sum,str);

string str2 = str;
for(int i=0;i<10;i++)
	{
	if(str2[i]=='*' && temp[i]!='*')
		str2[i] = temp[i];
	}

return /*m[idx][str] = */max(maxSubsetSum(arr,idx+1,len,sum,str),maxSubsetSum(arr,idx+1,len,sum+arr[idx],str2));
}

void test()
{
	m[0].insert({"*123**6789",100});
	m[0].insert({"*123**6**9",121});
	
	if(m[0].find("*123**6789") != m[0].end()) cout<<"found"<<endl;
	else cout<<"Not Found\n";
	/*set<pair<int, string> > s;
    s.insert({1,"*123**67**"}); s.insert({1,"*12345**89"});
    for(auto &it: s)
        cout<<it.first<<"-->>"<<it.second<<endl; */
        
    vector<pair<int, string> > v;
    v.push_back({1,"Sanju"});
    v.push_back({1,"Sanjeev"});
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<"->"<<v[i].second<<endl;
}

void game() 
{int n; cin>>n; int villains[n],players[n],flag=0; 
for(int i=0;i<n;i++) cin>>villains[i];
for(int i=0;i<n;i++) cin>>players[i];
mergeSort(villains,0,n-1);
mergeSort(players,0,n-1);

for(int i=0;i<n;i++) 
    {
    if(villains[i]>=players[i]) {flag=1; break;}
    }
if(flag==1) cout<<"LOSE"<<endl;
else cout<<"WIN"<<endl; 
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

