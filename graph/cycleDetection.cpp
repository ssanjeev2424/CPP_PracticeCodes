#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> node[1001]; //for adjacency list (array of vectors)
int color[1001];    //to check whether a node unvisited, discovered or 
bool cycle;                                               // explored

bool checkCycle(int);

int main() {
	int n,e,a,b; cout<<"Enter no. of nodes: "; cin>>n;

	cout<<"Enter no of edges: "; cin>>e;

	cout<<"Enter edges:\n";
	for(int i=0;i<e;i++) {
		cin>>a>>b;        //edge from "a" to "b"
		node[a].push_back(b);
		}
	
	cycle = false;
	memset(color, WHITE, sizeof(color));
	
	for(int i=1; i<=n; i++) {
		if(cycle) break;
		
		if(color[i] == WHITE)
			cycle = cycle || checkCycle(i);
	}
	
	if(cycle) cout<<"Cycle Found"<<endl;
	else cout<<"Graph is acyclic"<<endl;

	return 0;
}

bool checkCycle(int curr) {
	color[curr] = GREY;
	bool ans = false;
	
	for(int i=0; i<node[curr].size(); i++) {
		
		int child = node[curr][i];
		if(color[child] == GREY) {
			return true;
		}
		else if(color[child] != BLACK)
			ans = ans || checkCycle(child);
	}
	
	color[curr] = BLACK;
	return ans;
}
