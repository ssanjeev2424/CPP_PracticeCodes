#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Application of MERGE SORT
//https://www.spoj.com/problems/INVCNT/
//when we merge the two arrays, both are already sorted, so counting inversions becomes easy

int n; int arr[200001], L[200001], R[200001];
ll cnt;
void mergeSort(int,int); void merge(int,int,int);

int main() {
	fast;
	int t; cin>>t;
	while(t--) {
		cin>>n; cnt = 0;
		for(int i=0; i<n; i++) cin>>arr[i];
		
		mergeSort(0, n-1);
		cout<<cnt<<endl;
	}
	return 0;
}

void mergeSort(int l, int r) {
	if(l >= r) return;
	
	int mid = (l + r)/2;
	mergeSort(l    , mid);
	mergeSort(mid+1, r);
	merge(l, mid, r);
}

void merge(int l, int mid, int r) {
	//int L[mid-l+1], R[r-(mid+1)+1];
	
	for(int i=0; i<=mid-l; i++)
		L[i] = arr[l + i];
	
	for(int i=0; i<r-mid; i++)
		R[i] = arr[mid + 1 + i];
		
	//cout<<"l: "<<l<<" mid: "<<mid<<" r: "<<r<<" cnt: "<<cnt<<endl;	
	
	int i = mid - l, j = 0, k; ll temp = 0;
	while(j < r - mid) {              // Inversion calculation
		
		while(R[j] > L[i] && i<mid-l) {
			i++; temp--;
		}
		cnt += temp;
		
		while(R[j] < L[i] && i>=0) {
			i--;
			temp++; cnt++;
		}
		j++;
	}
	
	i = j = k = 0;                      // merge Sort
	while(i <= mid-l && j < r-mid) {
		if(L[i] >= R[j]) arr[l + k++] = R[j++];
		else arr[l + k++] = L[i++];
	}
	while(i <= mid - l) arr[l + k++] = L[i++];
	while(j < r-mid) arr[l + k++] = R[j++];
}
