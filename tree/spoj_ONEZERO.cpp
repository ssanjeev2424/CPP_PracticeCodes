#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/ONEZERO/
//https://www.geeksforgeeks.org/find-the-smallest-binary-digit-multiple-of-given-number/
// NICE PROBLEM ON BFS

int mod(string s, int n) {
	int r = 0;
	for(int i=0; i<s.length(); i++)
		r = (r*10 + (s[i]-'0'))%n;
	
	return r;
}

int main() {
	fast;
	int t, n, r; cin>>t;
	while(t--) {
		queue<string> Q; Q.push("1");
		unordered_set<int> rem;
		cin>>n;
		
		while(true) {
			string temp = Q.front();
			Q.pop();
			
			r = mod(temp, n);
			if(!r) {
				cout<<temp<<endl;
				break;
			}
			
			if(!rem.count(r)) {
				Q.push(temp + "0");
				Q.push(temp + "1");
				rem.insert(r);
			}
		}
	}
	return 0;
}
