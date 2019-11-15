#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

map<int,int> slicks; int n, m, arr[251][251];
bool visited[251][251];
int solve(int, int);

int main() {
	cin>>n>>m;
	while(n && m) {
		
		int cnt = 0, size;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) cin>>arr[i][j];
		memset(visited, false, sizeof(visited));
		slicks.clear();
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(!visited[i][j] && arr[i][j] == 1) {
					cnt++;
					size = solve(i, j);
					//cout<<"("<<i<<","<<j<<"): "<<size<<endl;
					if(slicks.count(size)) slicks[size]++;
					else slicks[size] = 1;
				}
		
		cout<<cnt<<endl;
		for(auto x: slicks)
			cout<<x.first<<" "<<x.second<<endl;
		
		cin>>n>>m;
	}
	return 0;
}

int solve(int i, int j) {
	int ans1, ans2, ans3, ans4;
	
	visited[i][j] = true;
	
	ans1 = (i+1 < n && arr[i+1][j] && !visited[i+1][j])?solve(i+1, j):0; // down
	ans2 = (j+1 < m && arr[i][j+1] && !visited[i][j+1])?solve(i, j+1):0; // right
	ans3 = (i-1 >= 0 && arr[i-1][j] && !visited[i-1][j])?solve(i-1, j):0; // up
	ans4 = (j-1 >= 0 && arr[i][j-1] && !visited[i][j-1])?solve(i, j-1):0; // left
	
	return 1 + ans1 + ans2 + ans3 + ans4;
}
