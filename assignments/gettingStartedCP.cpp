#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void catsAndDogs(); void millionaire(); void matrix();
void doughnuts(); void tractor();

template <typename type>
struct mycomp2
	{
	bool operator()(const type &first, const type &second) const {
	return first.second <second.second;
	}
	};

int idx1[251001],idx2[251001], grp[100001];

int main()
{
int t; cin>>t;
while(t--)
	{
	tractor();
	}
return 0;
}

void tractor()
{
int n,h;   cin>>n>>h;
int arr[n][2], end = n-1;
for(int i=0;i<n;i++)
	{
	int x,y; cin>>x>>y;
	
	arr[i][0] = end - y;
	arr[i][1] = end - x;
	}
/*cout<<"GAPS:\n";
for(int i=0;i<n;i++)
	{
	for(int j=0;j<2;j++)
		cout<<arr[i][j]<<" ";
	cout<<endl;
	}
cout<<endl; */
lli cost = INT_MAX, temp;
int i = 0, j = h-1;
while(j<n)
	{
	temp = 0;
	for(int idx=0;idx<n;idx++)
		{
		if(arr[idx][0]>j || arr[idx][1]<i) temp += h;
		else if(arr[idx][0]<=i && j<=arr[idx][1]) continue;
		else if(arr[idx][0]>i && j<=arr[idx][1]) temp += arr[idx][0]-i;
		else if(arr[idx][0]<=i && j>arr[idx][1]) temp += j-arr[idx][1];
		else temp += (arr[idx][0]-i) + (j-arr[idx][1]);
		}
	//cout<<i<<" to "<<j<<": temp is: "<<temp<<endl;
	if(temp<cost) cost = temp;
	i++; j++;
	}
cout<<cost<<endl;
}

void doughnuts()
{
memset(grp,0,sizeof(grp));
int n,m, cuts=0, idx=1, k=0,m2; cin>>n>>m;
int arr[m];
for(int i=0;i<m;i++)
	{
	int temp;
	cin>>temp;
	grp[temp]++;
	}
m2=m;
while(idx<=100000 && m2>0)
	{
	while(grp[idx]!=0)
		{
		arr[k++]=idx;
		grp[idx]--;
		m2--;
		}
	idx++;
	}

int i=0, j=m-1;

while(i<j)
	{
	if(arr[i]==1)
		{
		j--; i++;
		}
	else
		{
		j--;
		arr[i]--;
		}
	cuts++;	
	}

cout<<cuts<<endl;
}

void matrix()
{
int n, steps=0; scanf("%d",&n);
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
		{
		int num; cin>>num;
		idx1[num]=i; idx2[num]=j;
		}
	}
for(int i=1;i<n*n;i++)
	{
	//cout<<i<<": ("<<idx1[i]<<","<<idx2[i]<<") and steps: ";
	steps += abs(idx1[i+1]-idx1[i]) + abs(idx2[i+1]-idx2[i]);
	//cout<<steps<<endl;
	}
cout<<steps<<endl;
}

void millionaire()
{
		int n;
		cin >> n;
		
		string corrAns, chefAns;
		cin >> corrAns >> chefAns;
		
		int w[n+1];
		for (int i = 0; i <= n; ++i)
			cin >> w[i];
		
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (corrAns[i] == chefAns[i])
				++cnt;
		
		if (cnt == n)
		cout << w[n] << endl;
		else
		{
			int ans = 0;
			for (int i = 0; i <= cnt; ++i)
				ans = max(ans, w[i]);
			cout << ans << endl;
		}
}

void catsAndDogs()
{
lli c,d,l;   cin>>c>>d>>l;

if(l%4 != 0) { cout<<"no"<<endl; return; }

lli maxOnBack = min(2*d,c);

lli minCatsOnGround = c - maxOnBack;

if(l >= (minCatsOnGround+d)*4 && l <= (d+c)*4) { cout<<"yes"<<endl; return; }

cout<<"no"<<endl;
}

/*
#include <bits/stdc++.h>
using namespace std;

void roadies(); void test();

int main()
{
    int t; cin>>t;
    while(t--)
    {
        //roadies();
        test();
    }
}

void roadies()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

}

void test()
{
    vector<pair<int, string> > v;
    v.push_back({1,"Sanju"});
    v.push_back({1,"Sanjeev"});
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<"->"<<v[i].second<<endl;

    set<pair<int, string> > s;
    s.insert({1,"12367"}); s.insert({1,"1234589"});
    for(auto &it: s)
        cout<<it.first<<"-->>"<<it.second<<endl;
}
*/
/*
Rannvijay explains the task to you - "There are N boxes placed in a horizontal line infront of you with each box having a positive integer written on it. You have to tell me the maximum sum which can be formed by choosing the subset of boxes. Simple. But it is Roadies, so it can't be that simple. You have to tell me the maximum sum but the subset of boxes should not have any digit in common. 


Constraints
1<= T <=5

1 <= N <= 100

1 <= array elements <= 10^5

INPUT: 
3
4
3 5 7 2
5
121 23 3 333 4
7
32 42 52 62 72 82 92

ANswers: 
17
458
92
Explanation

Test Case 1: {3, 5, 7, 2} = 17

Test Case 2: {121, 333, 4} = 458

Test Case 3: {92} = 92 */
