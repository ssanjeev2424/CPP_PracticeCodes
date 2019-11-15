#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast; lli ans = 0, dgts, temp, step, prev,terms;
	int q,n; cin>>q;
	while(q--) {
		cin>>n; dgts = 0; temp = 0, step = 1, terms = 9;
		
		while(dgts < n) {
			if(dgts+terms*step < n) {
				dgts += terms*step;
				terms *= 10; step++;
			}
			else {
				//cout<<"..inside.."<<terms<<endl;
				int rem = n - dgts;
				
				int rem2 = rem%step;
				temp = pow(10,step-1)-1;
				temp += rem/step;
				
				//cout<<temp<<endl;
				if(rem%step) {
					int i = rem%step;
					string s = to_string(temp+1);
					temp = s[i-1] - '0';
				}
				else
					temp = temp%10;
				
				break;
			}
		}
		ans += temp;
	}
	cout<<ans<<endl;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	fast;
	int t,n; cin>>t;
	while(t--) {
		string a, b, ans = "", ans2 = ""; char carry;
		cin>>a>>b;
		
		int i = 0, j = a.length()-1, d;
		while(i < j) {
			char ch = a[i];
			a[i] = a[j];
			a[j] = ch;
			i++; j--;
		}
		i = 0, j = b.length()-1;
		while(i < j) {
			char ch = b[i];
			b[i] = b[j];
			b[j] = ch;
			i++; j--;
		}
		//cout<<a<<" "<<b<<endl;
		carry = '0';
		if(a.length() > b.length()) {
			i = a.length()-1, j = b.length()-1;
			
			carry = '0';
			//cout<<ans<<endl;
			for(;j>=0;i--,j--) {
				d = (a[i] - '0') + (b[j] - '0') + (carry - '0');
				if(d < 10) {
					carry = '0';
					ans = (char)(d + '0') + ans;
				}
				else {
					carry = '1';
					d = d%10;
					ans = (char)(d + '0') + ans;
				}
			}
			for(;i>=0;i--) {
				d = (a[i] - '0') + (carry - '0');
				if(d < 10) {
					carry = '0';
					ans = (char)(d + '0') + ans;
				}
				else {
					carry = '1';
					d = d%10;
					ans = (char)(d + '0') + ans;
				}
			}
			 //cout<<ans<<endl;
		}
		else if(b.length() > a.length()) {
			i = b.length()-1, j = a.length()-1;
			
			carry = '0';
			//cout<<ans<<endl;
			for(;j>=0;i--,j--) {
				d = (a[j] - '0') + (b[i] - '0') + (carry - '0');
				if(d < 10) {
					carry = '0';
					ans = (char)(d + '0') + ans;
				}
				else {
					carry = '1';
					d = d%10;
					ans = (char)(d + '0') + ans;
				}
			}
			for(;i>=0;i--) {
				d = (b[i] - '0') + (carry - '0');
				if(d < 10) {
					carry = '0';
					ans = (char)(d + '0') + ans;
				}
				else {
					carry = '1';
					d = d%10;
					ans = (char)(d + '0') + ans;
				}
			}
		}
		
		else {
			carry = '0';
			
			for(i=a.length()-1;i>=0;i--) {
				d = (a[i] - '0') + (b[i] - '0') + (carry - '0');
				if(d < 10) {
					carry = '0';
					ans = (char)(d + '0') + ans;
				}
				else {
					carry = '1';
					d = d%10;
					ans = (char)(d + '0') + ans;
				}
			} //cout<<ans<<endl;
		}
		//cout<<ans<<endl;
		if(carry == '1')
			ans = carry + ans;
		i = 0, j = ans.length()-1;
		while(i<j){
		    char ch = ans[i];
			ans[i] = ans[j];
			ans[j] = ch;
			i++; j--;
		}
		
		i = 0;
		while(ans[i]=='0') i++;
		ans2 = ans.substr(i,ans.length()-i);
		cout<<ans2<<endl;
	}
		
	return 0;
}
*/
