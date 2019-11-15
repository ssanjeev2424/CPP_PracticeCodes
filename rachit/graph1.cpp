#include<bits/stdc++.h>
using namespace std;

int main()
{
/*
6 5
1 2
2 3
3 1
2 6
4 5

1---2---6     4---5                 (6 nodes, 5 edges)
 \  /
   3
 

2 forests: f1: <1,2,3,6>  and f2: <4,5>

f1 has a cycle & not a tree
f2 is a tree.

Every tree is a graph, but every graph need not be a tree;
trees do not have cycles and there's only 1 forest in a tree, n-1 edges

** Can we reach to 4 from 1? -- CONNECTIVITY PROBLEM
	ANS: NO !!

** DFS(x)--traverses all the nodes which we can reach from node x

*/

return 0;
}
