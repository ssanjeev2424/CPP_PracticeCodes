#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// ************************* Double Binary search *********************** 

ll k, block;
int ok(ll); int findDigit(ll);

int main() {
	//fast;
	int t; cin>>t;
	while(t--) {
		cin>>k;
		
		ll l = 1, r = 1e9, temp;      // l = min possible value of block number, r = maximum value of block number.
		ll mid = (l + r)/2;          // https://codeforces.com/blog/entry/69954, maximum block value could be 10^9, read this tutorial
		temp = ok(mid); 
		
		while(temp != 0) {
			if(temp == 1)
				l = mid + 1;
			else
				r = mid - 1;
		
			mid = (l + r)/2;
			
			temp = ok(mid);
		}
		//cout<<"Binary search 1 complete..\n";
		if(!k) {                                   //means kth digit is the last digit of block (block-1)..
			if(block%10 == 0) cout<<9<<endl;
			else cout<<block%10 - 1<<endl;
			
			continue;
		}
		
		// now we need to find the kth digit in the range [1...block]     ,   1 <= k <= (#digits in this block)
		
		l = 1, r = block;   // min and max value of digit number in this block
		mid = (l + r)/2;
		
		while((temp=findDigit(mid)) != 0) {
			if(temp == 1)
				l = mid + 1;
			else
				r = mid - 1;
			
			mid = (l + r)/2;
		}
		
		//cout<<"Binary search 2 complete..\n";
	}
	return 0;
}

int findDigit(ll x) {                  // find the kth digit in the block, here x represents the number in range [1...block]
	ll sum = 0, sum2, ten = 1, n;     // we need to find the kth digit, eg 11th digit in 1234567891011 is 0..
	
	while(ten < x) {
		sum += x - ten;
		ten *= 10;
	}
	
	if(sum > k) return -1;       // need to go down
	
	sum2 = 0, ten = 1;
	while(ten < (x+1)) {
		sum2 += (x+1) - ten;   // checked for number (x+1)
		ten *= 10;
	}
	
	if(sum2 < k) return 1;    // even (x+1)th is lesser, so go up
	
	k -= sum;
	
	if(!k) {                   // k == 0, so it's the last digit of (x-1)
		if(x%10 == 0) cout<<9<<endl;
		else cout<<x%10 - 1<<endl;
		return 0;
	}
	
	// find kth digit(from left) of x,  kth digit falls inside the number x
	
	string str = "";
	while(x) {
		int dgt = x%10;
		str = to_string(dgt) + str;
		x /= 10; 
	}  
	
	cout<<str[k-1]<<endl;  // kth digit
	return 0;
}
                  
int ok(ll x) {                       // returns the block number of kth digit, block number starts from 1
	ll sum = 0, sum2, ten = 1, n;  // returns 0 if this is the correct block, -1 if we need to go down, 1 if we need to go up
	                              // here x represent the block number, each block contains number from [1...blockNumber]
	while(ten < x) {            // for k = 5, block number will be 3, ..... [1] [1,2] [1,2,3]....digit is 2
		n = x - ten;
		sum += (n*(n+1))/(ll)2;     // sum contains the sum of #digits contained in block number 1 to (x-1) (inclusive)
		ten *= 10;
	}
	
	if(sum > k) return -1; //need to go down, as #digits in block 1 to (x-1) is larger than k(asked digit number)
	
	sum2 = 0, ten = 1;
	while(ten < (x+1)) {
		n = (x+1) - ten;
		sum2 += (n*(n+1))/(ll)2;  // sum2 contains the #digits contained in block number 1 to x (inclusive)
		ten *= 10;
	}
	
	if(sum2 < k) return 1;       // if k is still greater, means we need to go to some upper(higher) block
	
	k -= sum;       // means kth digit falls in block x
	block = x;
	
	return 0; 
}
