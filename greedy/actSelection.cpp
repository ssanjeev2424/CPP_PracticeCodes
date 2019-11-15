#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<int,int> &f, pair<int,int> &s) {
	if(f.second == s.second) return f.first >= s.first;	
	return f.second < s.second;
}
 
int main() {
	int t, n, a, b, maxA, maxB; 
	cout<<"Enter #Test Cases: "; cin>>t;
	while(t--) {
		vector< pair<int,int> > inter;
		cout<<"Enter #Activities: "; cin>>n; maxA = maxB = -1;
		cout<<"Enter starting and ending times of activities..\n";
		for(int i=0; i<n; i++) {
			cin>>a>>b;
			inter.push_back({a, b});
			
			if(a > maxA) maxA = a; if(b > maxB) maxB = b;
		}
		
		sort(inter.begin(), inter.end(), comp);
		
		int ans = 0, end = -1;
		for(int i=0; i<n; i++) {
			if(end > maxA) break;
			
			if(inter[i].first < end) continue;
			
			ans++; end = inter[i].second;
		}
		
		cout<<"Maximum of "<<ans<<" activities can be finished."<<endl;
	}
	return 0;
} 

