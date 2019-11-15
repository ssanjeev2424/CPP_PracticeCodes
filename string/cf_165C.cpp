#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

//https://codeforces.com/problemset/problem/165/C

int main() {
	lli k, ans = 0, lb = 0, start = -1, end, ub, len, temp = 0, j, span;
	cin>>k;
	string str; cin>>str; len = str.length();
	
	if(k == 0) {
		for(j=0; j<len; j++)
			if(str[j] == '0') break;
		
		if(j == len) {
			cout<<0<<endl;
			return 0;
		}
		
		start = j; lli i; //start = 1st 0
		
		for(i=j+1; i<len; i++) {
			if(str[i] == '1') {
				span = i - start;
				ans += (span*(span+1))/2;
				
				for(j = i+1; j<len; j++)
					if(str[j] == '0') break;
				
				start = j;
				i = j;
			}
		}
		//cout<<"start: "<<start<<" ans: "<<ans<<endl;
		if(start < len) {
			span = len - start;
			ans += (span*(span+1))/2;
		}
		
		cout<<ans<<endl;
		return 0;
	}
	
	// keeping 4 pointers
	//start = 1st 1 of current window, end = last 1 of current window
	//lb = leftmost 0 from start, without any 1 in-between
	//ub = rightmost 0 from end, without any 1 in-between
	//if there r no consecutive 0s before start, lb = start
	for(int i=0; i<len; i++) { 
		if(str[i] == '1') {
			if(temp == k - 1) {
				
				if(temp == 0 && start == -1) start = i;
				
				end = i;
				
				for(j = i+1; j<len; j++)
					if(str[j] == '1') break;
				
				ub = j - 1;
				ans += (start - lb + 1)*(ub - end + 1);
				
				for(j=start+1;j<len ; j++)
					if(str[j] == '1') break;
				
				lb = start + 1;
				start = j;
			}
			else {
				if(temp == 0) start = i;
				temp++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
