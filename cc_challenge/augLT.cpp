#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	//fast;
	int t,n,k; cin>>t;
	while(t--) {
		cin>>n>>k; int arr[n], prev = 0, flag = 0;
		for(int i=0;i<n;i++) { cin>>arr[i]; }
		
		for(int i=0;i<n;i++) {
			if(arr[i] != -1) {
				prev = arr[i];
			}
			else {
				if(i==n-1) {
					arr[i] = prev==k ? 1 : prev+1;
				}
				else {
					//cout<<"\n*********prev:"<<prev<<" k:"<<k<<" *******\n";
					int next,secNext;
					if(prev==k) next = 1;
					else next = prev+1;
					if(next==k) secNext = 1;
					else secNext = next+1;

					//cout<<"idx: "<<i<<" prev: "<<prev<<" next: "<<next<<" secN: "<<secNext<<endl;
					if(arr[i+1] != next) {
						arr[i] = next;
						prev = next;
					}
					else if((arr[i+1] != secNext) && (arr[i-1]!=secNext && i!=0)) {
						arr[i] = secNext;
						prev = secNext;
					}
					else if(arr[i+1] != secNext && i==0) {
						arr[i] = secNext;
						prev = secNext;
					}
					else {
						flag = 1;
						break;
					}
				}
			}
		}
		if(flag) cout<<"NO\n";
		else {
			cout<<"YES\n";
			for(int i=0;i<n;i++) cout<<arr[i]<<" ";
			cout<<endl;
		}
		
	}
	return 0;
}

/*
int a1,a2,a3,c1,c2,c3;
		cin>>a1>>a2>>a3>>c1>>c2>>c3;
		
		if(a1 > a2 && c1 <= c2) cout<<"NOT FAIR\n";
		else if(a1 == a2 && c1 != c2) cout<<"NOT FAIR\n";
		else if(a1 < a2 && c1 >= c2) cout<<"NOT FAIR\n";
		else if(a1 > a3 && c1 <= c3) cout<<"NOT FAIR\n";
		else if(a1 == a3 && c1 != c3) cout<<"NOT FAIR\n";
		else if(a1 < a3 && c1 >= c3) cout<<"NOT FAIR\n";
		else if(a3 > a2 && c3 <= c2) cout<<"NOT FAIR\n";
		else if(a3 == a2 && c3 != c2) cout<<"NOT FAIR\n";
		else if(a3 < a2 && c3 >= c2) cout<<"NOT FAIR\n";
		else cout<<"FAIR\n";
*/
