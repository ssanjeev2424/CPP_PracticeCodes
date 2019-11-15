#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define M 1000000007
#define Z 1000000000000000000
#define db double
void proxy(); void road(); lli power(lli); int gcd(int,int);
void road2(); void guddu(); ulli digitSum(ulli); void tasty();
vector<ulli> vec; int prime(lli); void gcdSum(int); lli modu(lli);
int gcdMax(int *,int, int, int, int, int); void path(int);
int gcdMaxi,found; 
map< pair<int,int>,int > m[11][100001];

map< pair<int,int>, unordered_set<int> > node[10];
map< pair<int,int>, vector<int> > raasta[10];
void pathGenerator(int,int,vector<int> (&child)[300001],int);
void pathFinder(int,int,int,unordered_set<int> s,vector<int> dp, vector<int> (&child)[300001],int);

lli gcdExtended(lli a, lli b, lli *x, lli *y) 
{  
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1;  
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
   
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

lli modInverse(lli b, lli m) 
{ 
    lli x, y;
    lli g = gcdExtended(b, m, &x, &y); 
  
    if (g != 1) 
        return -1; 

    return (x%m + m) % m; 
} 

lli modDivide(lli a, lli b, lli m) 
{ 
    a = a % m; 
    lli inv = modInverse(b, m); 
    
	return (inv * a) % m; 
} 

int main()
{
int t; cin>>t;
//cout<<((db)(3)/2.0)*5<<" "<<(db)(4)/2<<endl;
/*while(t)
	{
	gcdSum(t--);
	}*/
for(int i=0;i<t;i++)
	path(i);

return 0;
}

void path(int t)
{
int n,q,u,v; cin>>n>>q;
vector<int> child[300001];
for(int i=1;i<n;i++)
	{
	cin>>u>>v;
	child[u].push_back(v);
	child[v].push_back(u);
	}

for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
		{
		if(!raasta[t][{i,j}].empty()) continue;
		
		pathGenerator(i,j,child,t);
		
		if(raasta[t][{i,j}].size()>3)
			{
			int x = 1, y = raasta[t][{i,j}].size()-2;
			while(x<y)	
				{
				int l = raasta[t][{i,j}][x], r = raasta[t][{i,j}][y];
				if(raasta[t][{l,r}].empty())
					{
					unordered_set<int> ss;
					vector<int> vec;
					for(int p=x;p<=y;p++)
						{
						ss.insert(raasta[t][{i,j}][p]);
						vec.push_back(raasta[t][{i,j}][p]);
						}
					raasta[t][{l,r}] = vec;
					node[t][{l,r}] = ss;
					}
				x++; y--;
				}
			}
		}

/*for(int i=1;i<=n;i++)
	{
	for(int j=i;j<=n;j++)
		{
		cout<<"("<<i<<","<<j<<"):";
		unordered_set<int>::iterator it;
		for(it=node[t][{i,j}].begin();it!=node[t][{i,j}].end();it++)
			cout<<*it<<" ";
		cout<<" Vector:";
		for(int k=0;k<raasta[t][{i,j}].size();k++)
			cout<<raasta[t][{i,j}][k]<<" ";
		cout<<endl;
		}
	//cout<<endl;
	}*/
//map< pair<int,int>, unordered_set<int> > node[10];
//cout<<"heyyyyyyy"<<endl;
for(int i=0;i<q;i++)
	{
	cin>>u>>v;
	if(u>v)
		{
		int temp = u;
		u = v;
		v = temp; //u is always smaller(or equal)
		}
	
	int count = 0;
	unordered_set<int> baap = node[t][{u,v}];
	for(int i=1;i<=n;i++)
		{
		for(int j=i;j<=n;j++)
			{
			if(i==u && j==v) continue;
			
			unordered_set<int> beta = node[t][{i,j}];
			int betaCount = 0;
			unordered_set<int>::iterator itr;
			
			for(itr=beta.begin();itr!=beta.end();itr++)
				{
				int stop = *itr;
				if(baap.find(stop)!=baap.end())
					betaCount++;
				if(betaCount>=2)
					break;
				}
				
			if(betaCount==1) count++;
			}
		}
	cout<<count<<endl;
	}
}
//map< pair<int,int>, unordered_set<int> > node[10];
void pathGenerator(int a,int b,vector<int> (&child)[300001],int t)
{
if(a==b)
	{
	unordered_set<int> s;
	s.insert(a);
	vector<int> vec; vec.push_back(a);
	node[t][{a,a}] = s;
	raasta[t][{a,a}] = vec;
	return;
	}

found = 0;
unordered_set<int> ss; vector<int> vec;
pathFinder(a,a,b,ss,vec,child,t);
}

//map< pair<int,int>, unordered_set<int> > node[10];
void pathFinder(int curr,int a,int b,unordered_set<int> ss, vector<int> vec, vector<int> (&child)[300001],int t)
{
if(found==1) return;

if(curr==b)
	{
	ss.insert(b); vec.push_back(b);
	found=1;
	node[t][{a,b}] = ss; raasta[t][{a,b}] = vec;
	return;
	}

if(ss.find(curr)!=ss.end()) return;

ss.insert(curr); vec.push_back(curr);

for(int i=0;i<child[curr].size();i++)
	pathFinder(child[curr][i],a,b,ss,vec,child,t);
}
//**********************************************************
void tasty()
{
lli n,k,step,idx,ans; scanf("%lld %lld",&n,&k);

if(k==1) { cout<<0<<endl; return; }

step = n-1;

idx = (k-1)/step;

if(idx==0) { cout<<modu(k-1)<<endl; return; }

ans = modu(modu(idx+1)*modu(k-1));

lli a=modu(idx), b=modu(idx+1), temp;

temp = modu(modu(a*b)*modu(step));

lli inv = modu(power(M-2));
temp = modu(temp*inv);

ans = modu(ans - temp + M);
cout<<ans<<endl;
}
//********************************************************
lli modu(lli num)
{
if(num<M) return num;
if(num==M) return 0;

lli smallAns = modu(num>>1)%M;

if(num&1) return (smallAns+smallAns+1)%M;
return (smallAns+smallAns)%M;

}

void gcdSum(int t)
{
int n; cin>>n;
int arr[n];
for(int i=0;i<n;i++) scanf("%d",&arr[i]);
sort(arr, arr+n);

cout<<gcdMax(arr,0,n,0,0,t)<<endl;
}
//map< pair<int,int>,int > m[100001];

int gcdMax(int *arr,int idx, int len, int gcd1, int gcd2, int t)
{
if(idx==len-1)
	{
	if(gcd1==0) return arr[idx]+gcd2;
	if(gcd2==0) return gcd1+arr[idx];
	
	return max(gcd(gcd1,arr[idx])+gcd2, gcd1+gcd(gcd2,arr[idx]));
	}

if(m[t][idx].find(make_pair(gcd1,gcd2)) != m[t][idx].end())
	return m[t][idx][{gcd1,gcd2}];

int smallAns1 = gcdMax(arr,idx+1,len,gcd(gcd1,arr[idx]),gcd2,t);
int smallAns2 = gcdMax(arr,idx+1,len,gcd1,gcd(gcd2,arr[idx]),t);

int ans = max(smallAns1,smallAns2);

m[t][idx][{gcd1,gcd2}] = ans;
return ans;
}

int gcd(int a, int b)
{
if(b==0) return a;

return gcd(b, a%b);
}

int prime(lli n)
{
if(n <= 1) return 0;
if(n <= 3) return 1;

if(n%2==0 || n%3==0) return 0;

for(lli i=5; i*i<=n; i+=6)
	if(n%i==0 || n%(i+2)==0)
		return 0;
return 1;
}

void guddu()
{
ulli num; scanf("%llu",&num);

ulli dSum = digitSum(num);

int last;

if((last=dSum%10)==0)
	{ printf("%llu%d\n",num,last); return; }

printf("%llu%d\n",num,10-last);

}

ulli digitSum(ulli num)
{
ulli sum = 0;
while(num!=0)
	{
	sum += num%10;
	num /= 10;
	}
return sum;
}

void road2()
{
lli k, count=0, num=10, temp,temp2,digits; scanf("%lld",&k);

for(int i=1;i<k;i++)
	num *= 10;
num--;

int arr[10], flag; count++;
cout<<0<<":"<<count<<" ";
for(int i=1;i<num;i++)
	{
	temp = i; temp2 = num-i, digits=0, flag = 0;
	memset(arr,0,sizeof(arr));
	while(temp!=0)
		{
		int digit = temp%10;
		if(arr[digit]==0)
			{
			arr[digit]=1; digits++;
			if(digits==3) { flag = 1; break; }
			}
		temp = temp/10;
		}
		if(flag) continue;
	while(temp2!=0)
		{
		int digit = temp2%10;
		if(arr[digit]==0)
			{
			arr[digit]=1; digits++;
			if(digits==3) { flag = 1; break; }
			}
		temp2 = temp2/10;
		}
		
		if(flag==0) { count++; cout<<i<<":"<<count<<" ";}
	}
cout<<num<<endl<<count+1<<endl;
}

void road()
{
lli k,count=0; scanf("%lld",&k);
count = k;

if(k==1) { cout<<10<<endl; return; }

lli temp = power(k-1);

count = (count + (9*temp)%M)%M;

cout<<count<<endl;
}

lli power(lli p)
{
if(p==1) return 2;
if(p==0) return 1;

lli smallAns = power(p/2)%M;

if(p&1) return (smallAns*smallAns*2)%M;
return (smallAns*smallAns)%M;
}

void proxy()
{
int d,ps=0,count=0; cin>>d;
float percent;
string str; cin>>str;

for(int i=0;i<d;i++)
	if(str[i]=='P') ps++;

int needed = ceil((3.0/4.0)*d);
//cout<<"needed: "<<needed<<" #Ps: "<<ps<<endl;

if(ps>=needed) { cout<<count<<endl; return; }

if(d<=4) { cout<<-1<<endl; return; }

for(int i=2;i<d-2;i++)
	{
	if(str[i]=='P') continue;
	
	if( (str[i-1]=='P'||str[i-2]=='P')&&(str[i+1]=='P'||str[i+2]=='P'))
		{
		count++;
		if(ps+count==needed)
			{
			cout<<count<<endl;
			return;
			}
		}
	}
cout<<-1<<endl;
}
