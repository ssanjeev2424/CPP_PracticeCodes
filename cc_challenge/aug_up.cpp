#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

vector<int> nums; int len;
lli nl, nr; string l, r, str;
lli pow10(int); void process();

lli dp[100002][2][11]; //idx, f, prev
lli tenP[100005], numAhead[100005];

lli call(int idx, int f, int prev) {
	if(idx == len) return 0;
	
	if(dp[idx][f][prev] != -1) return dp[idx][f][prev];
	
	int LMT;
	if(f) LMT = 9;
	else LMT = nums[idx];
	
	lli ans = 0;
	
	for(int i=0; i<=LMT; i++) {
		int newF = f, dgt = i;
		if(!f && dgt < nums[idx]) newF = 1;
			
		if(prev != dgt) {
			if(newF) {
				if(idx != len-1)
					ans = (ans + (((dgt*tenP[len-1-idx])%M)*tenP[len-1-idx])%M) % M;
				else
					ans = (ans + ((dgt*tenP[len-1-idx])%M)) % M;
			}
			else
				ans = (ans + (((dgt*tenP[len-1-idx])%M)*(numAhead[idx+1]+1))%M) % M;
		}
		
		ans = (ans + call(idx+1, newF, dgt)) % M;
		//cout<<"dgt: "<<dgt<<" ans: "<<ans<<endl;
	}
	//cout<<"idx: "<<idx<<" f: "<<f<<" prev: "<<prev<<" ans: "<<ans<<endl;
	return dp[idx][f][prev] = ans;
}

lli solve(string x) {
	nums.clear(); len = x.length();
	
	memset(dp, -1, sizeof(dp));
	memset(numAhead, 0, sizeof(numAhead));
	for(int i=0; i<len; i++)
		nums.push_back(x[i] - '0');
	
	process();
	
	lli res = call(0, 0, 10) % M;
	//cout<<"For "<<x<<" ************* ans: "<<res<<endl<<endl;
	return res;
}

int main() {
	int t,n; cin>>t;
	//char c = '2'; cout<<c-'0'<<endl;
	
	tenP[0] = 1;
	for(int i=1; i<100002; i++)
		tenP[i] = (tenP[i-1] * 10) % M;
	
	while(t--) {
		cin>>nl>>l>>nr>>r;
		
		lli res = (solve(r) - solve(l) + M)%M;
		//cout<<"res: "<<res<<endl;
		lli ans = 0; char prev = 'z';
		for(int i=0; i<nl; i++) { //for 'l' only
			if(prev != l[i]) {
				ans = (ans + ((l[i]-'0')*tenP[nl-1-i]) % M) % M;
				prev = l[i];
			}
		}
		//cout<<ans<<endl;
		cout<< (res + ans)%M <<endl;
	}
	return 0;
}

void process() {
	for(int i=len-1; i>=0; i--)
		numAhead[i] = (nums[i]*tenP[len-1-i] + numAhead[i+1]) % M;
}

lli pow10(int n) {
	if(n == 0) return 1;
	
	lli ans = pow10(n/2)%M;
	
	if(n&1)
		return (10*((ans*ans)%M))%M;
	return (ans*ans)%M;
}
