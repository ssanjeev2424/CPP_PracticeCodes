#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int main() { //https://codeforces.com/contest/465/problem/C
	int n, p, flag = 0, idx; cin>>n>>p;
	string str; cin>>str; char prev1, prev2, curr, start;
	
	
	char ch[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
					'n','o','p','q','r','s','t','u','v','w','x','y','z'};

	for(int i=str.length()-1; i>=0; i--) {
		if(flag) break;
		if(i > 1) {
			
			idx = (str[i]-'a')+1; 
			//cout<<"i: "<<i<<" idx: "<<idx<<endl;
			prev1 = str[i-1];
			prev2 = str[i-2]; int x;
			for(x=idx; x<p; x++) {
				curr = ch[x];
				if(curr != prev1 && curr != prev2) {
					flag = 1;
					idx = i; break;
					//cout<<"break..i: "<<i<<" idx: "<<x<<endl;
				}
			}
			//if(!flag) cout<<"No break..i: "<<i<<" idx: "<<x<<endl;
		}
		else if(i==1) {
			idx = (str[i]-'a')+1;
			//cout<<"i: "<<i<<" idx: "<<idx<<endl;
			prev1 = str[i-1]; int x;
			for(x=idx; x<p; x++) {
				curr = ch[x];
				if(curr != prev1) {
					flag = 1;
					idx = i; break;
					//cout<<"break..i: "<<i<<" idx: "<<x<<endl;
				}
			}
			//if(!flag) cout<<"No break..i: "<<i<<" idx: "<<x<<endl;
		}
		else {
			idx = (str[i]-'a')+1;
			//cout<<"i: "<<i<<" idx: "<<idx<<endl; 
			int x;
			for(x=idx; x<p; x++) {
				curr = ch[x];
				flag = 1;
				idx = i; break;
				//cout<<"break..i: "<<i<<" idx: "<<x<<endl;
			}
			//if(!flag) cout<<"No break..i: "<<i<<" idx: "<<x<<endl;
		}
	}
	//cout<<"...flag: "<<flag<<" idx: "<<idx<<" curr: "<<curr<<endl;
	if(!flag) cout<<"NO"<<endl;
	else {
		for(int i = idx; i<str.length(); i++) {
			str[i] = curr;
			if(i==str.length()-1) break;
			
			int index = 0;
			while(true) {
				if(i>0) {
					prev1 = curr;
					prev2 = str[i-1];
					char s = ch[index];
					//cout<<"********* "<<prev2<<" "<<prev1<<" "<<s<<endl;
					if(s != prev1 && s != prev2) {
						curr = s; //cout<<"inside************* "<<prev2<<" "<<prev1<<" "<<s<<endl;
						break;
					}
					index = (index+1)%p;
					//cout<<"str: "<<str<<" curr: "<<curr<<" index: "<<index<<endl;
				}
				else {
					prev1 = curr;
					char s = ch[index];
					//cout<<"..............."<<endl;
					if(s != prev1) {
						curr = s; //cout<<"inside..............."<<endl;
						break;
					}
					index = (index+1)%p;
					//cout<<"str: "<<str<<" curr: "<<curr<<" index: "<<index<<endl;
				}	
			}
		}
		
		cout<<str<<endl;
	}
	
	return 0;
}


