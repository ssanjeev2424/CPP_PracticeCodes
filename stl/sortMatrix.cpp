#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
//https://practice.geeksforgeeks.org/problems/sorted-matrix/0
struct Matrix{
  int val;
  int i;
  int j;
  
  Matrix(int v, int x, int y) {
      val = v;
      i = x; j = y;
  }
};

struct comp {
  bool operator()(const Matrix &x, const Matrix &y) const {
      return x.val > y.val;
  }  
};

//during pQ initialization, default is max-heap, less comp creates max-heap
//and greater creates min-heap

//whereas in normal comp in pair,vector...it's reverse

int main()
{
int t,n,temp; cin>>t;
while(t--)
	{
	   cin>>n;
	   bool used[n+1][n+1]; memset(used,false,sizeof(used));
	   int arr[n+1][n+1];
	   priority_queue<Matrix, vector<Matrix>, comp> pq;
	   for(int x=1;x<=n;x++)
	    for(int y=1;y<=n;y++)
	            cin>>arr[x][y];
	   
	   pq.push(Matrix(arr[1][1],1,1)); 
	   
	   while(!pq.empty())
	   {
	       Matrix m = pq.top();
	       cout<<m.val<<" ";
	       used[m.i][m.j] = true;
	       
	       if(m.i < n && !used[m.i+1][m.j])
	        {
	            pq.push(Matrix(arr[m.i+1][m.j],m.i+1,m.j));
                used[m.i+1][m.j] = true;
	        }
	        if(m.j < n && !used[m.i][m.j+1])
	        {
	            pq.push(Matrix(arr[m.i][m.j+1],m.i,m.j+1));
                used[m.i][m.j+1] = true;
	        }
		pq.pop();
	   }
	   cout<<endl;
	}
return 0;
}
