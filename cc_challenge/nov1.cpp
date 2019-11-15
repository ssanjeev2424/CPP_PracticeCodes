#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 3000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

double NM[5001][5001], NK[5001], MK[5001], x, y, n, m, k;
vector<pair<double,double> > N(5001), M(5001), K(5001);
double dist(pair<double,double>,pair<double,double>); 

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		cin>>x>>y; cin>>n>>m>>k;
		for(int i=0; i<n; i++) cin>>N[i].first>>N[i].second;
		for(int i=0; i<m; i++) cin>>M[i].first>>M[i].second;
		for(int i=0; i<k; i++) cin>>K[i].first>>K[i].second;
		
		double temp;
		for(int i=0; i<n; i++) {
			temp = MX;
			for(int j=0; j<k; j++)
				temp = min(temp, dist(N[i], K[j]));
			NK[i] = temp;
		}
		for(int i=0; i<m; i++) {
			temp = MX;
			for(int j=0; j<k; j++)
				temp = min(temp, dist(M[i], K[j]));
			MK[i] = temp;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				NM[i][j] = dist(N[i], M[j]);
				
		temp = 3 * MX;
		pair<double, double> P = {x, y};
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				temp = min(temp, dist(P,N[i])+NM[i][j]+MK[j]);
				temp = min(temp, dist(P,M[j])+NM[i][j]+NK[i]);
			}
		cout<<fixed<<setprecision(10)<<temp<<endl;
	}
	return 0;
}

double dist(pair<double, double> X, pair<double, double> Y) {
	return sqrt(pow(X.first-Y.first, 2) + pow(X.second-Y.second, 2));
}

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int occ[65][130]; // [i, j] occurrences of i till index j, max is 62
int previ[130];     // index of previous occurrence of i
int seq[130];      // sequence
int temp[130];

int main() {
	fast;
	int t, x = 0, n; cin>>t;            seq[1] = 0;
	memset(previ, -1, sizeof(previ));  previ[0] = 1;
	memset(occ, 0, sizeof(occ));     occ[0][1] = 1;
	memset(temp, 0, sizeof(temp));   temp[0] = 1;
	
	for(int i=2; i<=128; i++) {
		if(temp[x] == 1) { 
			previ[x] = i - 1;
			seq[i] = x = 0;
			occ[x][i] = occ[x][i-1] + 1;
			temp[0]++;
		}
		else {
			seq[i] = i - 1 - previ[x];
			previ[x] = i - 1;        x = seq[i];
			occ[x][i] = occ[x][i-1] + 1;
			temp[x]++;
		}
		
		//cout<<"i: "<<i<<" seq[i]: "<<seq[i]<<" x: "<<x<<" prev[x]:"<<previ[x]<<" temp[x]: "<<temp[x]<<endl;
		for(int j=0; j<=65; j++) {
			if(j == x) continue;
			else occ[j][i] = occ[j][i-1];
		}
	}
	
	//for(int i=1; i<129; i++) cout<<seq[i]<<" "; cout<<endl;
	
	while(t--) {
		cin>>n; //cout<<"element: "<<seq[n]<<" occ: ";
		cout<<occ[seq[n]][n]<<endl;
	}
	return 0;
}


cin>>n; cnt = 0; 
		string str; int sum[10] = {0};
		for(int i=0; i<n; i++) {
			cin>>str; 
			
			for(int j=0; j<10; j++)
				if(str[j]=='1') sum[j]++;
		}
		
		for(int i=0; i<10; i++) if(sum[i]&1) cnt++;
		cout<<cnt<<endl;
*/
