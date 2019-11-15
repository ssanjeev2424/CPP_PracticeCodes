#include <bits/stdc++.h>
using namespace std;

vector<int> node[10001]; void diameter(int,int); bool visited2[10001];
int height(int,int); int diam, heightDP[10001]; bool visited[10001];

// radius of tree = ceil(diameter/2)  .. confirm it

int main() { 
	int n,a,b,x; cin>>n;
	for(int i=1;i<n;i++) { //edges
		cin>>a>>b; //parent, child
		node[a].push_back(b);
		node[b].push_back(a);
	}
	memset(heightDP, -1, sizeof(heightDP));
	memset(visited, false, sizeof(visited));
//	cout<<"Height of: "; cin>>x;
	//cout<<height(x)<<endl; 
	int h = height(1,-1); memset(visited2,false,sizeof(visited2));
	diam = 0;
	diameter(1,-1); cout<<diam<<endl;
	//cout<<heightDP[1]<<" "<<heightDP[2]<<" "<<heightDP[3]<<endl;
	//for(int i=1;i<=n;i++) cout<<i<<": "<<heightDP[i]<<endl;
	return 0;
}

void diameter(int curr, int par) {
	visited2[curr] = true;
	
	int max1 = 0, max2 = 0, temp;
	
	for(int i=0; i<node[curr].size(); i++) {
		int child = node[curr][i];
		if(visited2[child]) continue;
		temp = 1 + height(child, curr);
		
		if(temp >= max1) {
			max2 = max1;
			max1 = temp;
		}
		else if(temp > max2)
			max2 = temp;
		
		diameter(child, curr);
	}
	
	if(max1 + max2 > diam)
		diam = max1 + max2;
}

int height(int curr, int par) {   //height of leaf = 0
	if(heightDP[curr] != -1) return heightDP[curr];
	
	visited[curr] =  true;
	int temp = 0;
	for(int i=0;i<node[curr].size();i++) {
		int child = node[curr][i];
		if(visited[child]) continue;
		temp = max(temp, 1 + height(child, curr));
	}
	return heightDP[curr] = temp;
}
