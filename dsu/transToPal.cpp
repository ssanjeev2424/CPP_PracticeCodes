#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

// https://www.hackerrank.com/contests/w33/challenges/transform-to-palindrome/problem 

vector<int> parent, size;
int dp[1001][1001], arr[1001];
int solve(int,int);

void make_set(int u) {
	parent[u] = u;
	size[u] = 1;
}

int find_set(int u) {
	if(u == parent[u]) 
		return u;
	
	return parent[u] = find_set(parent[u]);
}

void union_by_rank(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	
	if(a != b) {
		if(size[a] < size[b])
			swap(a, b);
		
		parent[b] = a;
		
		if(size[a] == size[b])
			size[a]++;
	}
}

int main() {

	int n, k, m, a, b; cin>>n>>k>>m;
	parent = size = vector<int>(n+1, 0);
	memset(dp, -1, sizeof(dp));
	
	//iota(parent.begin(), parent.end(), 0);
	//cout<<parent[4]<<" "<<size[4]<<endl;
	
	for(int i=0; i<k; i++) {
		cin>>a>>b;
		
		if(!parent[a] && !parent[b]) { //both new
			make_set(a); make_set(b);
			union_by_rank(a, b);
		}
		else if(parent[a] && parent[b]) { //both present
			if(find_set(a) != find_set(b))
				union_by_rank(a, b);
		}
		else if(parent[a] && !parent[b]) { //b new
			make_set(b);
			union_by_rank(a, b);
		}
		else {                     // a new
			make_set(a);
			union_by_rank(a, b);
		}
	}
	
	for(int i=1; i<=n; i++)
		if(!parent[i]) make_set(i);
		
	for(int i=0; i<m; i++) cin>>arr[i];
	
	int ans = solve(0, m-1);
	cout<<ans<<endl;
	return 0;
}

int solve(int l, int r) {
	if(l >= r) return (l == r) ? 1: 0;
	
	if(dp[l][r] != -1) return dp[l][r];
	
	if(find_set(arr[l]) == find_set(arr[r]))
		return dp[l][r] = 2 + solve(l+1, r-1);
	
	return dp[l][r] = max(solve(l+1,r), solve(l, r-1));
}

/*
The Orion alphabet system consists of  letters, denoted by the integers from  to . The  Orion letter is denoted by the integer .

Some Orion letters can be transformed to other Orion letters. A transformation is denoted by a pair of two Orion letters, . Using this transformation, you can replace letter  with letter .

1 to n letters, tranformation x-->y, associative and transitive

Transformations also have additional properties:

If letter  can be transformed to letter  using a transformation, then letter  can be transformed to letter  as well.
If letter  can be transformed to letter  and letter  can be transformed to letter , then letter  can be transformed to letter  as well.
You are given a sequence  comprising of  Orion letters. You are given  transformations that can be applied to . You may apply transformations to zero or more letters in the sequence. When a transformation is applied to a letter, the other letters of the string remain unaffected. You can also apply a single transformation multiple times on the same sequence.

Print the length of the longest possible palindromic subsequence after applying zero or more transformations on the letters of the given sequence.

For example, in the sequence below, transformation  is first applied to the sequence  to obtain . The longest palindrome subsequence is then obtained from the resulting transformed sequence by removing letter .

Input Format

The first line contains three space separated integers ,  and . The following  lines each contain two space separated integers  and , denoting a transformation from letter  to letter . The last line contains  positive integers (elements of the string).

Constraints

Output Format

Print a single line containing an integer denoting the length of the longest possible palindromic subsequence which can be obtained after applying transformations on the given string.

Sample Input 0

10 7 6
1 3
5 7
3 5
2 6
2 4
8 4
10 9
1 9 2 3 10 3
Sample Output 0

5
Explanation 0

The given string is . After transforming the last letter from  to , string becomes . After transforming  to , string becomes . One of the longest palindromic subsequence is formed as follows .

*/





















