#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// https://www.spoj.com/problems/BITMAP/ -- >> multi source bfs or modified Dijkstra ,GOOD ONE !!
//https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

typedef struct Node {
	int x, y;
	int d;
	
	Node(int a, int b, int c) {
		x = a; y = b;
		d = c;
	}
} N;

struct comp {
	bool operator()(const Node &x, const Node &y) {
		return x.d > y.d;
	}
};

bool used[185][185]; // node already used in dijkstra
int dist[185][185]; // min distance found at that time

int main() {
	fast;
	int t, n, m, gap; cin>>t;
	while(t--) {
		cin>>n>>m; string s[n];
		memset(used, false, sizeof(used));
		for(int i=0; i<n; i++) cin>>s[i];
		
		priority_queue<Node, vector<Node>, comp> pq;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(s[i][j] == '1') pq.push(Node(i, j, 0)), dist[i][j] = 0;
				else pq.push(Node(i, j, 500)), dist[i][j] = 500;
			}
		}
		
		int cnt = 0;
		
		while(true) {
		
			int i, j, w;
			while(true) {
				Node temp = pq.top();
				pq.pop();
				if(!used[temp.x][temp.y]) {
					i = temp.x, j = temp.y, w = temp.d;
					break;
				}
			}
			
			cnt++;
			dist[i][j] = w;  used[i][j] = true;
			
			if(cnt == m*n) break;
			
			if(i && dist[i-1][j] > w + 1 && !used[i-1][j]) {  //up
					pq.push(Node(i-1, j, w+1));
					dist[i-1][j] = w + 1;
			}
			if(j && dist[i][j-1] > w + 1 && !used[i][j-1]) { //left
				pq.push(Node(i, j-1, w+1));
				dist[i][j-1] = w + 1;
			} 
			if(i < n-1 && dist[i+1][j] > w + 1 && !used[i+1][j]) { //down
				pq.push(Node(i+1, j, w+1));
				dist[i+1][j] = w + 1;
			} 
			if(j < m-1 && dist[i][j+1] > w + 1 && !used[i][j+1]) { //right
				pq.push(Node(i, j+1, w+1));
				dist[i][j+1] = w + 1;
			} 
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) cout<<dist[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

/* using BFS on every node.. TLE

typedef struct Dist {
	int x;
	int y;
	int d;
	
	Dist(int a, int b, int c) {
		x = a; y = b;
		d = c;
	}
} D;


cin>>n>>m;
		string bits[n];
		bool visited[n][m];
		for(int i=0; i<n; i++) cin>>bits[i];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
			
				if(bits[i][j] == '1') {
					cout<<0<<" ";
					continue;
				}
				
				memset(visited, false, sizeof(visited));
				visited[i][j] = true;
				
				queue<Dist> Q;
				bool f = false;
				
				if(i) { //up
					if(bits[i-1][j] == '1') f = true;
					Q.push(Dist(i-1, j, 1));
					visited[i-1][j] = true;
				}
				if(j) { //left
					if(bits[i][j-1] == '1') f = true;
					Q.push(Dist(i, j-1, 1));
					visited[i][j-1] = true;
				} 
				if(i < n - 1) { //down
					if(bits[i+1][j] == '1') f = true;
					Q.push(Dist(i+1, j, 1));
					visited[i+1][j] = true;
				} 
				if(j < m - 1) { //right
					if(bits[i][j+1] == '1') f = true;
					Q.push(Dist(i, j+1, 1));
					visited[i][j+1] = true;
				} 
				
				if(f) {
					cout<<1<<" ";
					continue;
				}
				
				while(true) {
					Dist temp = Q.front();
					Q.pop();
					
					bool f = false;
				
					if(temp.x && !visited[temp.x-1][temp.y]) { //up
						if(bits[temp.x-1][temp.y] == '1') f = true;
						Q.push(Dist(temp.x-1, temp.y, temp.d+1));
						visited[temp.x-1][temp.y] = true;
					}
					if(temp.y && !visited[temp.x][temp.y-1]) { //left
						if(bits[temp.x][temp.y-1] == '1') f = true;
						Q.push(Dist(temp.x, temp.y-1, temp.d+1));
						visited[temp.x][temp.y-1] = true;
					} 
					if(temp.x < n - 1 && !visited[temp.x+1][temp.y]) { //d
						if(bits[temp.x+1][temp.y] == '1') f = true;
						Q.push(Dist(temp.x+1, temp.y, temp.d+1));
						visited[temp.x+1][temp.y] = true;
					} 
					if(temp.y < m - 1 && !visited[temp.x][temp.y+1]) { //r
						if(bits[temp.x][temp.y+1] == '1') f = true;
						Q.push(Dist(temp.x, temp.y+1, temp.d+1));
						visited[temp.x][temp.y+1] = true;
					}
					
					if(f) {
						cout<<temp.d + 1<<" ";
						break;
					} 
				}
			}
			cout<<endl;
		}
*/
