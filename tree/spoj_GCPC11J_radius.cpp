#include <bits/stdc++.h>
using namespace std;

vector<int> node[100000];
bool visited[100000];
int diam, heightDP[100000];
int height(int); void diameter(int);

int main() {
	int t,n,a,b; cin>>t;
	while(t--) {
		diam = 0;  cin>>n;
		
		for(int i=0; i<n; i++) {
			node[i].clear();
			visited[i] = false;
			heightDP[i] = -1;
		}
		
		for(int i=1;i<n;i++) { //edges
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
		}	
		
		int h = height(0); //calculating height of all nodes (0 as root)
		
		for(int i=0; i<n; i++)
			visited[i] = false;
		
		diameter(0);
		cout<<(diam/2 + diam%2)<<endl; //radius = ceil(diam/2)
	}
	return 0;
}

void diameter(int curr) {
	visited[curr] = true;
	
	int max1 = 0, max2 = 0, temp;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		
		if(visited[child]) continue;
		
		temp = 1 + height(child);
		
		if(temp >= max1) {
			max2 = max1;
			max1 = temp;
		}
		else if(temp > max2)
			max2 = temp;
		
		diameter(child);
	}
	if(max1 + max2 > diam)
		diam = max1 + max2;
}

int height(int curr) {  //height of leaf = 0
	
	if(heightDP[curr] != -1) return heightDP[curr];
	
	visited[curr] =  true;
	int temp = 0;
	for(int i=0;i<node[curr].size();i++) {
		int child = node[curr][i];
		if(visited[child]) continue;
		temp = max(temp, 1 + height(child));
	}
	return heightDP[curr] = temp;
}
