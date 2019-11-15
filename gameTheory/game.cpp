#include <bits/stdc++.h>
using namespace std;

void chessBoardMain(); bool chessBoard(int,int);  void nim();
void stonesMain();     bool stones(int);          void tower();  
void misereNim();  

map<pair<int,int>,bool> dp_chess; map<int,bool> dp_stones;

int main()
{
misereNim();
return 0;
}

void misereNim()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n;
	int arr[n],temp;
	for(int i=0;i<n;i++)
		{
		cin>>temp;
		if(temp==1) arr[i] = 0;
		else arr[i] = temp-1;
		}
	
	int res = arr[0];
	for(int i=1;i<n;i++)
		res ^= arr[i];
	
	if(res==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	}
}


void nim()
{
int t,n; cin>>t;
while(t--)
	{
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int res = arr[0];
	for(int i=1;i<n;i++)
		res ^= arr[i];
	
	if(res==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	}
}

void tower()
{
int t,n,m; cin>>t;
while(t--)
{
cin>>n>>m;
if(m==1) cout<<2<<endl;
else
	{
	if(n & 1) cout<<1<<endl;
	else cout<<2<<endl;
	}
}

}

void stonesMain()
{
int t; cin>>t;
while(t--)
	{
	int x; cin>>x;
	cout<<(stones(x)?"First":"Second")<<endl;
	}
}

bool stones(int x)
{
if(dp_stones.count(x)) return dp_stones[x];

bool state = false;

if(x-2>=0 && !stones(x-2)) state = true;
//means if 2 elements can be picked nd "x-2" is a losing state for other
//person..
if(x-3>=0 && !stones(x-3)) state = true;

if(x-5>=0 && !stones(x-5)) state = true;

return dp_stones[x] = state;
}

void chessBoardMain()
{
int t; cin>>t;
while(t--)
	{
	int x,y; cin>>x>>y;
	cout<<(chessBoard(x-1,y-1)?"First":"Second")<<endl;
	}
}

bool chessBoard(int x, int y)
{
if(dp_chess.count({x,y}))
	return dp_chess[ {x,y} ];

bool state = false;

if(x-2>=0 && y+1<15 && !chessBoard(x-2,y+1)) state = true;

if(x-2>=0 && y-1>=0 && !chessBoard(x-2,y-1)) state = true;

if(x+1<15 && y-2>=0 && !chessBoard(x+1,y-2)) state = true;

if(x-1>=0 && y-2>=0 && !chessBoard(x-1,y-2)) state = true;

return dp_chess[ {x,y} ] = state;
}

/*



*/
