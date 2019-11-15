#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define MAXI 1000000000000001

lli dp[100001][2]; // idx, previous string reversed or not
lli cost[100001], n;
string str[100001];
lli solve(int,int);

int main() //CodeForces
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>cost[i];
	for(int i=0;i<n;i++) cin>>str[i];
	memset(dp,-1,sizeof(dp));
	
	lli ans = solve(0,0);
	
	if(ans == MAXI) ans = -1;
	cout<<ans<<endl;
	return 0;
}

lli solve(int idx, int rev) {
	if(idx == n) return 0;
	
	if(dp[idx][rev] != -1) return dp[idx][rev];
	
	string curr = str[idx], prev;
	int len1, len2 = curr.length();
	
	if(idx == 0) len1 = 0, prev = "";
	else len1 = str[idx-1].length(), prev = str[idx-1];
	
	if(rev) {
		int i1 = len1-1, i2 = 0; // i1 for prev, i2 for curr
		lli ans = MAXI;
		
		while(i1 >= 0 && i2 < len2) {  // reverse, normal --> (prev, curr)
			if(prev[i1] == curr[i2])
				i1--, i2++;
			else if(prev[i1] < curr[i2]) {
				ans = min(ans, solve(idx+1, 0));
				break;
			}
			else
				break;
		}
		if(len1 <= len2 && i2 == len1)
			ans = min(ans, solve(idx+1, 0));
		
		i1 = len1 - 1, i2 = len2 - 1;
		while(i1 >= 0 && i2 >= 0) { 		// reverse, reverse
			if(prev[i1] == curr[i2])
				i1--, i2--;
			else if(prev[i1] < curr[i2]) {
				lli ans2 = solve(idx+1, 1);
				ans = (ans2==MAXI) ? ans : min(ans,cost[idx]+ans2);
				break;
			}
			else
				break;
		}
		if(len1 <= len2 && i1 == -1) {
			lli ans2 = solve(idx+1, 1);
			ans = (ans2==MAXI) ? ans : min(ans,cost[idx]+ans2);
		}
		return dp[idx][rev] = ans;
	}
//***************************************************************	
	int i1 = 0, i2 = 0; // i1 for prev, i2 for curr
	lli ans = MAXI;
	
	while(i1 < len1 && i2 < len2) {  // normal, normal --> (prev, curr)
		if(prev[i1] == curr[i2])
			i1++, i2++;
		else if(prev[i1] < curr[i2]) {
			ans = min(ans, solve(idx+1, 0));
			break;
		}
		else
			break;
	}
	if(len1 <= len2 && i1 == len1)
		ans = min(ans, solve(idx+1, 0));
	
	i1 = 0, i2 = len2 - 1;
	while(i1 < len1 && i2 >= 0) { 		// normal, reverse
		if(prev[i1] == curr[i2])
			i1++, i2--;
		else if(prev[i1] < curr[i2]) {
			lli ans2 = solve(idx+1, 1);
			ans = (ans2==MAXI) ? ans : min(ans,cost[idx]+ans2);
			break;
		}
		else
			break;
	}
	if(len1 <= len2 && i1 == len1) {
		lli ans2 = solve(idx+1, 1);
		ans = (ans2==MAXI) ? ans : min(ans,cost[idx]+ans2);
	}
	return dp[idx][rev] = ans;
}

/*
cin>>a>>b>>n;
	
	if(n%3 == 0) cout<<a<<endl;
	else if(n%3 == 1) cout<<b<<endl;
	else cout<<(a^b)<<endl;
	*************************************************************
	int n; cin>>n; int arr[n+1];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	lli a,b;

struct Pair {
	int key;
	int cnt;
	
	Pair(int a, int b) {
	key = a;
	cnt = b;
	}
};

struct comp {
	bool operator()(const Pair &f, const Pair &s) const {
	return f.cnt < s.cnt;
	}
};

	
	int p = 0, q = n-1;
	unordered_map<int,int> m;
	
	while(p < q) { 
//https://codeforces.com/contest/1208/problem/B
// using binary search, trying out all ranges
// keeping unordered set of the elements outside the present window of (i,j), then using sliding window.. rest all should be unique		
		int mid = (p+q)/2;
		int i = 0, j = mid-1, extra = 0; m.clear();
		cout<<"START p:"<<p<<" q:"<<q<<" mid:"<<mid<<" extra:"<<extra<<endl;
		while(j < n) {
			//cout<<"Inside..";
			if(i != 0) {
				//cout<<"m[i-1]: "<<m[arr[i-1]]<<endl;
				if(m[arr[j]] == 2)
					extra--;
					
				if(m[arr[j]]==1) m.erase(arr[j]);
				else m[arr[j]]--;
				if(m.count(arr[i-1])) {
					if(m[arr[i-1]]==1) extra++; 
					m[arr[i-1]]++; 
				}
				else m[arr[i-1]] = 1;
			}
			else {
				for(int x=0;x<i;x++) {
					if(m.count(arr[x])) {
						if(m[arr[x]]==1) extra++;
						m[arr[x]]++;
					}
					else m[arr[x]] = 1;
				}
				
				for(int x=j+1;x<n;x++) {
					if(m.count(arr[x])) {
						if(m[arr[x]]==1) extra++;
						m[arr[x]]++;
					}
					else m[arr[x]] = 1;
				}
			}
			cout<<"("<<i<<","<<j<<")extra:"<<extra<<endl;
			for(auto k:m) cout<<"key:"<<k.first<<" -->> "<<k.second<<endl; cout<<"........\n";
				
			if(!extra) break;
			
			i++; j++;
		}
		
		if(extra) p = mid+1;
		else q = mid;
		cout<<"\nEND p:"<<p<<" q:"<<q<<" mid:"<<mid<<" extra:"<<extra;
		cout<<"\n********************************\n";
	}
	cout<<q<<endl;
	*************************************************************************
*/

