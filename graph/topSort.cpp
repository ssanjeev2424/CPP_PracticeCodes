#include <bits/stdc++.h>
using namespace std;

vector<int> node[1000]; //for adjacency list (array of vectors)
bool visited[1000];    //to check whether a node is visited or not
void topSort(int);
stack<int> stk;

int main() {
int n,e,a,b; cout<<"Enter no. of nodes: "; cin>>n;
cout<<"Enter no of edges: "; cin>>e;
cout<<"Enter edges:\n";
for(int i=0;i<e;i++) {
	cin>>a>>b;        //end points of edge are "a" and "b"
	node[a].push_back(b);
}

for(int i=1; i<=n; i++) visited[i] = false;
for(int i=1; i<=n; i++)
	if(!visited[i])
		topSort(i);

cout<<"Topological Sort: ";
while(!stk.empty()) {
	cout<<stk.top()<<" ";
	stk.pop();
} 
cout<<endl;
return 0;
}

void topSort(int u) {
	visited[u] = true;
	
	for(int i=0; i<node[u].size(); i++) {
		int child = node[u][i];
		
		if(!visited[child]) topSort(child);
	}
	stk.push(u);
}
