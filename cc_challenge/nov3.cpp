#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<int> vec[100001]; int idx[100001];

int main() {
	fast;
	int t, n, m, x; cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=0; i<m; i++) { 
			vec[i].clear();
			idx[i] = 0;
		}
		for(int i=0; i<n; i++) {
			cin>>x;
			vec[i%m].push_back(x);
		}
		for(int i=0; i<m; i++) sort(vec[i].begin(), vec[i].end());
		
		int ans = M, Max, Min, temp;
		for(int i=0; i<vec[0].size(); i++) {
			temp = Max = Min = vec[0][i];
			
			for(int j=1; j<m; j++) {
				if(vec[j][idx[j]] >= Max || idx[j] == vec[j].size()-1) {
					if(vec[j][idx[j]] > Max) Max = vec[j][idx[j]];
					if(vec[j][idx[j]] < Min) Min = vec[j][idx[j]];
				}
				else {
					if(vec[j][idx[j]] >= Min)
						continue;
					
					while(idx[j] < vec[j].size() - 1) {
						if((vec[j][idx[j]] >= Min && vec[j][idx[j]] <= Max) || vec[j][idx[j]] > Max)
							break;
						
						if(vec[j][idx[j]+1] <= Max) {
							idx[j]++; continue;
						}
							
						if(abs(Min-vec[j][idx[j]]) < abs(Max-vec[j][idx[j]+1])) {
							Min = vec[j][idx[j]];
							break;
						}
						idx[j]++;
					}
					if(vec[j][idx[j]] > Max) Max = vec[j][idx[j]];
					if(vec[j][idx[j]] < Min) Min = vec[j][idx[j]];
				}
			}
			
			if(Max - Min < ans) ans = Max - Min;
		}
		cout<<ans<<endl;
	}
	return 0;
}
