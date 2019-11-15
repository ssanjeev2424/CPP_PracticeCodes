#include <bits/stdc++.h>
using namespace std;
#define lli long long int

unordered_map<string, string> chain;
set<string> curr;
set<string> used;
vector<string> tail;

int main() {
	int idx = 0, q; string a,b;
	cin>>q;
	
	for(int i=0; i<q; i++) {
		cin>>a>>b;
		
		if(used.count(b) || used.count(a) || curr.count(b)) continue;
		
		if(curr.count(a)) { // 'a' on head
			curr.erase(a);
			
			used.insert(a);
			curr.insert(b);
			
			chain[a] = b;
		}
		else {
			tail.push_back(a); //new user
			
			used.insert(a);
			curr.insert(b);
			
			chain[a] = b;
		}
	}
	
	cout<<tail.size()<<endl;
	for(int i=0; i<tail.size(); i++) {
		string str = tail[i];
		
		while(chain.count(str)==1)
			str = chain[str];
		
		cout<<tail[i]<<" "<<str<<endl;
	}
	return 0;
}




