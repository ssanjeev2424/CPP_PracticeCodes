#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int arr[1001][1001];

int main() {
	int n; cin>>n;
	int mid = n/2, x = 0;
	
	for(int i=0;i<mid;i++)
		for(int j=0;j<mid;j++) arr[i][j] = 4*(x++);
	
	for(int i=0;i<mid;i++)
		for(int j=mid;j<n;j++) arr[i][j] = arr[i][j-mid] + 1;
	
	for(int i=mid;i<n;i++)
		for(int j=0;j<mid;j++) arr[i][j] = arr[i-mid][j] + 2;
	
	for(int i=mid;i<n;i++)
		for(int j=mid;j<n;j++) arr[i][j] = arr[i-mid][j-mid] + 3;
		
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
