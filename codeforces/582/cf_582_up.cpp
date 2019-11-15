#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() {
	int n; string s, t;
	cin>>n>>s>>t;
	
	string abc = "abc";
	vector<string> perm;
	do {
		string str;
		for(int i=0;i<n;i++) str += abc;
		perm.push_back(str);
		perm.push_back(string(n,abc[0])+string(n,abc[1])+string(n,abc[2]));
		
	} while(next_permutation(abc.begin(), abc.end()));
	
	for(auto str: perm) {
		if(str.find(s) == string::npos && str.find(t) == string::npos) {
			cout<<"YES"<<endl<<str<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int n; string s, t, str; void solve(int);
set<int> invalid[3];

int main() {
	cin>>n; str = "abc";
	cin>>s>>t;
	
	invalid[s[0]-'a'].insert(s[1]-'a');
	invalid[t[0]-'a'].insert(t[1]-'a');
	
	if(s[0] == t[0] && s[1] != t[1])
		solve(s[0] - 'a');
	else
		solve(-1);
	
	return 0;
}

void solve(int s1) { //s == single char allowed for a particular char
	string ans = "";
	if(s1 != -1) { //***********************************************
		int x = (s1+1)%3 , y = (s1+2)%3;
		
		for(int i=0;i<n;i++) {
			ans.push_back(str[x]);
			ans.push_back(str[y]);
		}
		for(int i=0;i<n;i++)
			ans += str[s1];
		
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	} // **********************************************************
	else { 
		if(s[1]==t[1] && s[0]!=s[1] && s[0]!=t[0]) {
		
			for(int i=0;i<n;i++)
				ans += s[1];
			for(int i=0;i<n;i++) {
				ans.push_back(s[0]);
				ans.push_back(t[0]);
			}
		}
		else { // -----------------------------------------
			int x, y, last;
			for(int i=0;i<3;i++) {
				if(invalid[i].find(i)==invalid[i].end()) {
					last = i;
					break;
				}
			}
			
			for(int i=0;i<3;i++) {
				if(i==last) continue;
				
				if(invalid[i].find(last)==invalid[i].end()) {
					y = i;
					break;
				}
			}
			
			x = 3 - y - last;
			cout<<x<<" "<<y<<" "<<last<<" ans: "<<ans<<endl;
			for(int i=0;i<n;i++) {
				ans.push_back(str[x]);
				ans.push_back(str[y]);
			}
			for(int i=0;i<n;i++)
				ans += str[last];	
		}
		
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	} //*******************************************
}


#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<vector<int> > vals(200010);
vector<int> arr(200001);

int main() {
	fast; //used multiset earlier
	int n, k, x, ans = 1e9, cnt; cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0; i<n; i++) {
		x = arr[i];
		cnt = 0;
		
		while(x) {
			vals[x].push_back(cnt);
			x = x>>1;
			cnt++;
		}
		vals[0].push_back(cnt);
	}
	
	for(int i=0; i<=200000; i++) {
		if(vals[i].size() < k) continue;
		
		sort(vals[i].begin(), vals[i].end());
		ans = min(ans, accumulate(vals[i].begin(), vals[i].begin()+k, 0));
	}
	cout<<ans<<endl;
	return 0;
}
*/
