#include<bits/stdc++.h>
using namespace std;
int maxSubArray(int*,int,int);
int max(int,int,int); int midIncluded(int *,int,int,int);
void mergeSort(int*,int,int); void merge(int *,int,int,int);

int main()
{
int arr[] = {-3,4,-2,1,2,-4,14,0};
int len = (sizeof(arr)/sizeof(arr[0]));
cout<<"Max SubArray Sum: "<<maxSubArray(arr,0,len-1)<<endl;  //time=n.logn, took the help of internet
mergeSort(arr,0,len-1);

for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}

void mergeSort(int *arr,int l,int r)  //QUESTION 2.a
{
if(l>=r) return;

int mid = (l+r)/2;
mergeSort(arr,l,mid);
mergeSort(arr,mid+1,r);
merge(arr,l,mid,r);
}

void merge(int *arr,int l,int m,int r)  //QUESTION 2.b
{
int L[m-l+1+1],R[r-m+1],i,j,k=0;
//L[m-l+1] = R[r-m] = INT_MAX;
for(i=0;i<=m-l;i++)
	L[i]=arr[l+i];
L[i] = INT_MAX;

for(j=0;j<r-m;j++)
	R[j] = arr[m+1+j];
R[j] = INT_MAX;

i=j=0;
while(k<r-l+1)
{
	if(L[i]<= R[j]) {arr[l + k] = L[i++]; k++;}
	else {arr[l + k] = R[j++]; k++;}
}
}


int maxSubArray(int *arr,int l,int r)  //QUESTION 1.a
{
if(l==r) return arr[l];

int mid = (l+r)/2;
return max(maxSubArray(arr,l,mid), maxSubArray(arr,mid+1,r),midIncluded(arr,l,mid,r));
}


int max(int a,int b,int c)  //QUESTION 1.b
{
if(a>=b && a>=c) return a;
return (b>=c)?b:c;
}


int midIncluded(int *arr,int l,int m,int r)   //QUESTION 1.c
{
int sum=0,leftSum = INT_MIN,rightSum = INT_MIN;;

for(int i=m;i>=l;i--)
{
	sum+=arr[i];
	if(sum>leftSum) leftSum=sum;
}
sum=0;
for(int i=m+1;i<=r;i++)
{
	sum+=arr[i];
	if(sum>rightSum) rightSum = sum;
}

return leftSum+rightSum;
}
