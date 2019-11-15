#include <bits/stdc++.h>
using namespace std;

//https://cp-algorithms.com/data_structures/disjoint_set_union.html

vector<int> parent(100001); //size is 100001
vector<int> size(100001);

void make_set(int u) { //makes a new set consisting only one element
	parent[u] = u;
	size[u] = 1;  // size is used in Union by Rank, it's rank (max depth)
}

int find_set(int u) {
	if(u == parent[u]) //representative itself
		return u;
	
	return parent[u] = find_set(parent[u]); //path compression
}

void union_by_rank(int a, int b) {
	a = find_set(a);
	b = find_set(b); //getting their representatives
	
	if(a != b) {
		if(size[a] < size[b])
			swap(a, b); //we want a to be the bigger one
		
		parent[b] = a; // union by rank, b is smaller, so joined to a
		
		if(size[a] == size[b])
			size[a]++;
	}
	
	// if a==b, they r in the same set, no need for union
}

int main() {
	make_set(1); make_set(2); make_set(3); make_set(4);
	make_set(5); make_set(6); make_set(12); make_set(7);
	make_set(8); make_set(9); make_set(10); make_set(11);
	
	cout<<find_set(8)<<endl;
	
	union_by_rank(1, 2); union_by_rank(3, 4); union_by_rank(11, 12);
	union_by_rank(2, 3); union_by_rank(7, 8); union_by_rank(9, 10);
	
	cout<<find_set(4)<<" "<<find_set(2)<<endl;
	
	union_by_rank(7, 4);
	
	cout<<find_set(8)<<" "<<find_set(12)<<endl;
	
	return 0;
}




