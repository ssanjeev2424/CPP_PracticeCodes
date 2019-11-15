#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int m, n, visited[21][21], idx1, idx2;
char arr[21][21]; int solve(int, int);

int main() { // NOT ACCEPTED, tricky case perpaps, got bored
	int t, entry, valid; cin>>t;
	while(t--) {
		cin>>m>>n; entry = 0, valid = 1;
		memset(visited, 0, sizeof(visited));
		 
		if(m == 1 || n == 1) {
			for(int i=0; i<m; i++)
				for(int j=0; j<n; j++) {
					cin>>arr[i][j];
					
					if(arr[i][j] == '.') {
						if((!i && !j)||(!i && j==n-1)||(i==m-1 && !j))
							valid = 0;
						else 
							entry++; 
					}
				}
			
			if(!valid || entry != 1) {
				cout<<"invalid\n";
				continue;
			}
			
			cout<<"valid\n";
			continue;
		}
		
		int corner = 0;
		
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				cin>>arr[i][j];
				
				if(arr[i][j] == '.') {
					if((!i && !j)||(!i && j==n-1)||(i==m-1 && !j)||(i==m-1 && j==n-1)) //corners
						entry += 2, corner++;
					else if(i==0 || i==m-1 || j==0 || j==n-1)
						entry++, idx1 = i, idx2 = j; 
				}
			}
		//cout<<"Entry: "<<entry<<endl;
		if(entry != 2) {
			cout<<"invalid\n";
			continue;
		}
		
		if(corner) {
			cout<<"valid\n";
			continue;
		}
		
		int found = solve(idx1, idx2);
		if(found) cout<<"valid\n";
		else cout<<"invalid\n";
	}
	return 0;
}

int solve(int i, int j) {
	if(!i || !j || i==m-1 || j==n-1)
		 if(!(i==idx1 && j==idx2)) return 1;
	 
	visited[i][j] = true;
	int ans1, ans2, ans3, ans4;
	
	ans1 = (j+1 < n && arr[i][j+1]=='.' && !visited[i][j+1]) ? solve(i, j+1) : 0; //right
	ans2 = (i+1 < m && arr[i+1][j]=='.' && !visited[i+1][j]) ? solve(i+1, j) : 0; //down
	ans3 = (j-1 >= 0 && arr[i][j-1]=='.' && !visited[i][j-1]) ? solve(i, j-1) : 0; //left
	ans4 = (i-1 >= 0 && arr[i-1][j]=='.' && !visited[i-1][j]) ? solve(i-1, j) : 0; //up
	
	return (ans1 || ans2 || ans3 || ans4);
}
