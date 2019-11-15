#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/PALIN/
//http://solutions4spoj.blogspot.com/2015/10/palin-next-palindrome.html

int main() {
	fast;
	int t, n, i, j, l, r; cin>>t; string str, str2;
	while(t--) {
		cin>>str; str2 = "";
		for(j=0; ; j++) 
			if(str[j] != '0') break;
		for(; j<str.length(); j++)
			str2 += str[j];
		str = str2;
		
		n = str.length(); bool flag = false;
		
		for(i=0; i<n; i++)
			if(str[i] != '9') {
				flag = true; break;
			}
		
		if(!flag) {                            // if all 9s
			cout<<1; for(i=1; i<n; i++) cout<<0; cout<<1<<endl;
			continue;
		}
		
		l = r = n/2;
		if(n%2 == 0) l--;
		
		while(l >= 0 && str[l] == str[r]) l--, r++;
		
		if(l < 0 || str[l] < str[r]) {
			l = r = n/2;
			if(n%2 == 0) l--;
			
			int carry = 1, num;
			while(l >= 0) {
				num = (str[l]-'0') + carry;
				carry = num/10;
				
				str[r] = str[l] = num%10 + '0';
				l--; r++;
			}
		}
		else {
			while(l >= 0) str[r++] = str[l--];
		}
		
		cout<<str<<endl;
	}
	return 0;
}

/*
The input number is palindrome and has all 9s. For example “9 9 9″. Output should be “1 0 0 1″. for this we will just output the string of length 1 greater tthan the previous with 1 at ends and 0 in middle.
Other cases. say 2133
Split it into the left half and right half ("21", "33");
Compare the last digit in the left half and the first digit in the right half.
a. If the right is greater than the left, increment the left and stop. ("22")
b. If the right is less than the left, stop.
c. If the right is equal to the left, repeat step 3 with the second-last digit in the left and the second digit in the right (and so on).
Take the left half and append the left half reversed. That's your next largest palindrome. ("2222")

*/
