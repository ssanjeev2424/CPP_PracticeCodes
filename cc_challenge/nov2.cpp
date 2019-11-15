#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

string str[100001]; int l; void solve();
int vow[100001], con[100001];

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		cin>>l;
		for(int i=0; i<l; i++) cin>>str[i];
		solve();
	}
	return 0;
}

void solve() {
	D xA[26] = {0}, xB[26] = {0}; // #recipes containing a particular char
	D occA[26] = {0}, occB[26] = {0}; // total #occurrences
	int alice = 0;
	
	for(int i=0; i<l; i++) {
		int ok = 1; // if it belongs to Alice
		int len = str[i].length(), vowels = 0, conso = 0;
		D occ[26] = {0}, found[26] = {0};
		
		//for(int j=0; j<len; j++) vow[j] = con[j] = 0;
		vow[0] = con[0] = 0;
		
		if(str[i][0]=='a' || str[i][0]=='e' || str[i][0]=='i' || str[i][0]=='o' || str[i][0]=='u') vow[0]++;
		else con[0]++;
		
		occ[str[i][0]-'a']++; found[str[i][0]-'a'] = 1;
		
		for(int j=1; j<len; j++) {
			if(str[i][j]=='a' || str[i][j]=='e' || str[i][j]=='i' || str[i][j]=='o' || str[i][j]=='u') {
				vow[j] = 1 + vow[j-1];
				con[j] = con[j-1];
			}
			else {
				vow[j] = vow[j-1];
				con[j] = 1 + con[j-1];
			}
		
			occ[str[i][j]-'a']++; found[str[i][j]-'a'] = 1; 
		}
		//for(int j=0; j<len; j++) cout<<"i: "<<j<<" vow:"<<vow[j]<<" con:"<<con[j]<<endl;
		for(int step=1; step<min(len, 3); step++) {
			int p = 0, q = step;
			if(con[q] > vow[q]) ok = 0;
			if(!ok) break;
			p++; q++;
			
			while(q < len) {
				if(!ok) break;
				
				if(con[q]-con[p-1] > vow[q]-vow[p-1]) ok = 0;
				p++; q++;
			} 
		}
		
		if(ok) {
			alice++;
			for(int j=0; j<26; j++) {
				occA[j] += occ[j]; xA[j] += found[j];
			}
		}
		else {
			for(int j=0; j<26; j++) {
				occB[j] += occ[j]; xB[j] += found[j];
			}
		}
	}
	
	//cout<<"Alice: "<<alice<<endl;
	D score = 1, scoreA, scoreB;
	for(int i=0; i<26; i++) {
		if(xA[i]) {
			scoreA = (xA[i]/((D)pow(occA[i], alice)));
			score *= scoreA;
		}
	}
	for(int i=0; i<26; i++) {
		if(xB[i]) {
			scoreB = (xB[i]/((D)pow(occB[i], l - alice)));
			score /= scoreB;
		}
		
		if(score > 10000000) break;
	}

	if(score > 10000000) cout<<"Infinity\n";
	else cout<<fixed<<setprecision(7)<<score<<endl;
}
