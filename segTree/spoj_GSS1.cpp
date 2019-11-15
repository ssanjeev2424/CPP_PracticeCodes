#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/GSS1/    ** GOOD ONE **
//http://ideone.com/Qq25J5#comments
//http://code.cloudkaksha.org/spoj/spoj-gss1-solution

typedef struct Node {
	int bestPrefixSum, bestSuffixSum, sum, bestSum;
	
	void Merge(Node &A, Node &B) {
		sum = A.sum + B.sum;  // sum of all elements
		bestPrefixSum = max(A.bestPrefixSum, A.sum + B.bestPrefixSum);
		bestSuffixSum = max(B.bestSuffixSum, A.bestSuffixSum + B.sum);
		bestSum = max(max(A.bestSum, B.bestSum), A.bestSuffixSum + B.bestPrefixSum);  // best contiguous sum
	}
	
	void CreateLeaf(int val) {
		sum = bestSum = bestPrefixSum = bestSuffixSum = val;
	}
} N;

int arr[50005]; N tree[4*50005];

void build(int l, int r, int idx) {
	
	if(l == r) {
		tree[idx].CreateLeaf(arr[l]);
		return;
	}
	
	int mid = (l + r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	
	tree[idx].Merge(tree[2*idx], tree[2*idx+1]);
}

void query(Node &result, int l, int r, int lb, int ub, int idx) {
	
	if(l == lb && r == ub) {
		result = tree[idx];
		return;
	}
	
	int mid = (l + r)/2;
	
	if(mid >= ub)
		query(result, l, mid, lb, ub, 2*idx);
	else if(mid < lb)
		query(result, mid+1, r, lb, ub, 2*idx+1);
	else {                 // [lb, ub] range overlaps the 2 segments
		Node left, right;
		query(left, l, mid, lb, mid, 2*idx);  // see all the arguments
		query(right, mid+1, r, mid+1, ub, 2*idx+1); // carefully
		result.Merge(left, right);
	}
}

int main() {
	fast;
	int n, q, l, r; cin>>n; 
	for(int i=1; i<=n; i++) cin>>arr[i];
	
	build(1, n, 1);
	
	cin>>q;
	Node ans;
	for(int i=0; i<q; i++) {
		cin>>l>>r;
		query(ans, 1, n, l, r, 1);   // "ans" passed as reference
		cout<<ans.bestSum<<endl;
	}
	return 0;
}
