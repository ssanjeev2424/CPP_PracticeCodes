#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
// https://codeforces.com/contest/1203/problem/D2
string s, t; int len1, len2, endsAt[200001], startsFrom[200001], ans;

void binSearch(int l, int r) {
	if(l > r || (!l && !r)) return;
	
	int mid = (l+r)/2, i, j, sum;
	if(!mid) {
		binSearch(1,1);
		return;
	}
	
	i = 0, j = mid - 1;
	while(j < len1) {
		sum = 0;
		
		if(i) sum += endsAt[i-1];
		if(j != len1-1) sum += startsFrom[j+1];
		
		if(sum >= len2) {
			if(mid > ans) ans = mid; //satisfied for "mid" length
			binSearch(mid + 1, r); // so check the greater one
			return;
		}
		
		i++; j++;
	}
	
	binSearch(l, mid - 1); //check for lesser value
}

int main() {
	cin>>s>>t; ans = 0;
	len1 = s.length(), len2 = t.length();
	//cout<<"len1: "<<len1<<" len2: "<<len2<<endl;
	memset(endsAt, 0, sizeof(endsAt)); //traversing t left to right
	memset(startsFrom, 0, sizeof(startsFrom)); //traversing t right to left
	
	int idx = 0, i;
	
	for(i=0; i<len1; i++) {
		if(s[i] == t[idx]) {
			if(!idx) endsAt[i] = 1;
			else endsAt[i] = endsAt[i-1] + 1;
			idx++;
			if(idx == len2)
				for(i=i+1; i<len1; i++) endsAt[i] = len2;
		}
		else
			if(i) endsAt[i] = endsAt[i-1];
	}
	
	idx = len2 - 1;
	for(i=len1-1; i>=0; i--) {
		if(s[i] == t[idx]) {
			if(idx == len2 - 1) startsFrom[i] = 1;
			else startsFrom[i] = startsFrom[i+1] + 1;
			idx--;
			if(idx < 0)
				for(i=i-1; i>=0; i--) startsFrom[i] = len2;
		}
		else
			if(i != len1 - 1) startsFrom[i] = startsFrom[i+1];
	}
	
	//for(int i=0; i<len1; i++) cout<<endsAt[i]<<" "; cout<<endl;
	//for(int i=0; i<len1; i++) cout<<startsFrom[i]<<" "; cout<<endl;
	
	binSearch(0, len1 - len2); //min and max value of ans, will check its
	cout<<ans<<endl; // validity on this range using binary search
	return 0;
}
