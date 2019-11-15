#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int n;
void heapify(int*,int); void extractMin(int*); 
void buildHeap(int*); void heapSort(int*);

int main() {
	int arr[] = {110, 56, 34, 25, 1, 70, 3};
	n = (sizeof(arr))/(sizeof(int));

	cout<<"Input Array:\n";
	int limit = 1;
	for(int i=0;i<n;) {
		for(int j=0; j<limit && i<n ; j++, i++)
			cout<<arr[i]<<" ";
		limit *= 2; cout<<endl; }

	buildHeap(arr); // builds heap

	limit = 1; cout<<"\nAfter Build Heap:\n";
	for(int i=0;i<n;) {
		for(int j=0; j<limit && i<n ; j++, i++)
			cout<<arr[i]<<" ";
		limit *= 2; cout<<endl; }
	cout<<endl;

	cout<<"Min Element: "<<arr[0]<<endl<<endl; //prints minimum element 

	extractMin(arr); //extracts minimum elememt
	cout<<"After Extract Min:\n"; limit = 1;
	for(int i=0;i<n;) {
		for(int j=0; j<limit && i<n ; j++, i++)
			cout<<arr[i]<<" ";
		limit *= 2; cout<<endl; }
	cout<<endl;

	int size = n;
	heapSort(arr);
	
	cout<<"Heapsort: ";
	for(int i=0;i<size;i++) cout<<arr[i]<<" "; cout<<endl;
	return 0;
}

void extractMin(int *arr) {
	arr[0] = arr[n-1];
	n--;
	
	heapify(arr, 0);
	//buildHeap(arr); // it should be heapify(arr, 0)
}

void buildHeap(int *arr) {
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,i);
}

void heapify(int *arr, int idx) {
	int Min = idx, l = 2*idx+1, r = 2*idx+2;

	if(l < n && arr[l] < arr[Min])
		Min = l;
	if(r < n && arr[r] < arr[Min])
		Min = r;

	int temp = arr[idx];
	arr[idx] = arr[Min];
	arr[Min] = temp;

	if(Min != idx)
		heapify(arr, Min);
}

void heapSort(int *arr) {
	if(n <= 1) return;

	int temp = arr[n-1];
	arr[n-1] = arr[0];
	arr[0] = temp;
	n--;
	
	heapify(arr, 0);
	//buildHeap(arr);
	heapSort(arr);
}

