#include <bits/stdc++.h>
using namespace std;

vector<int> node[1000]; //for adjacency list (array of vectors)
bool visited[1000];    //to check whether a node is visited or not
void dft(int); void dfs(int); 
void bft(int); void bfs(int);

int main()
{
int n,e,a,b; cout<<"Enter no. of nodes: "; cin>>n;

cout<<"Enter no of edges: "; cin>>e;

cout<<"Enter edges:\n";
for(int i=0;i<e;i++) {
	cin>>a>>b;        //end points of edge are "a" and "b"
	node[a].push_back(b);
	node[b].push_back(a);
	}

memset(visited, false, sizeof(visited));
cout<<"\nDepth First Traversal => "; dfs(n); cout<<endl;

memset(visited, false, sizeof(visited));
cout<<"\nBreadth First Traversal => "; bfs(n); cout<<endl;
return 0;
}

void dft(int x) {  		//Depth first Traversal for a component
	visited[x] = true;

	cout<<x<<" ";
	
	for(int i=0;i<node[x].size();i++) {
		int child = node[x][i];
		
		if(!visited[child])
			dft(child);
		}	
	}

void dfs(int n) { 		//Depth first Traversal for the whole graph
	for(int i=1;i<=n;i++)
		if(!visited[i])
			dft(i);
	}

void bft(int x) { 		//Breadth first Traversal for a component
	queue<int> Q;
	Q.push(x); visited[x] = true; cout<<x<<" ";
	
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		
		for(int i=0;i<node[curr].size();i++) {
			int child = node[curr][i];
			
			if(!visited[child]) {
				visited[child] = true;
				cout<<child<<" ";
				Q.push(child);
				}
			}
		}
	}

void bfs(int n) {      //Breadth first Traversal for the whole graph
	for(int i=1;i<=n;i++)
		if(!visited[i])
			bft(i);
	}
