#include<bits/stdc++.h>
using namespace std;

int MaxSubArr(int*,int,int,int); int uglyNo(int);
void searchRotated(int*,int,int,int); void mergeMN(int*,int*,int,int);
int maxSumNoAdj(int*, int,int,int); void largestSubArr(int*,int);
void sumClosestToZero(int *,int); void smallestTwo(int*,int);
void unionIntersection(int*,int,int*,int); int maxDiff(int*,int);
int equilibrium(int*,int); void checkConsecu(int*,int);
void nextGreater(int*,int); int firstMissing(int*, int, int);
int countOcc(int*,int,int,int); int leftmostOcc(int*,int,int,int);
int rightmostOcc(int*,int,int,int);

map<int,int> nextG;

int main()
{

int arr[] = {-2,-3,4,-1,-2,1,5,-3};
int size = sizeof(arr)/sizeof(arr[0]);
cout<<"Max SubArray: "<<MaxSubArr(arr,0,size,0)<<endl;

int arr2[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
cout<<"Rotated Search: "; searchRotated(arr2, 0, 8, 1);

int arrM[] = {0,-1,2,-1,-1,99,-1}, arrN[] = {4,8,90,100};
mergeMN(arrM, arrN, 7, 4);
for(int i=0;i<7;i++)
	cout<<arrM[i]<<" ";
cout<<endl;

int adj[] = {15,5,20,100,10,5,6};
cout<<"MaxSumNoAdj: "<<maxSumNoAdj(adj,7,0,0)<<endl;

int sub[] = {-2,-3,4,-1,-2,1,5,-3,4};
largestSubArr(sub,sizeof(sub)/sizeof(sub[0]));

int zero[] = {-80,-10,1,60, 70, 85};
sumClosestToZero(zero, sizeof(zero)/sizeof(zero[0]));

int small[] = {12,25,8,55,10,33,17,11};
smallestTwo(small,sizeof(small)/sizeof(small[0]));

int ui1[] = {1,3,4,5,7}, ui2[] = {2,3,5,6};
unionIntersection(ui1,5,ui2,4);

int diffArr[] = {1, 2, 90, 10, 110};
int diffLen = sizeof(diffArr)/sizeof(diffArr[0]);
cout<<"Max diff: "<<maxDiff(diffArr,diffLen)<<endl;

int eq[] = {-7, 1, 5, 1, 2, 1, -4, 3, 0};
int eqLen = sizeof(eq)/sizeof(eq[0]);
cout<<"Equilibrium index: "<<equilibrium(eq,eqLen)<<endl;

int cons[] = {83, 78, 80, 81, 79, 82};
int consLen = sizeof(cons)/sizeof(cons[0]);
checkConsecu(cons, consLen);

int nextGr[] = {11, 13, 21, 3};
int nextGrLen = sizeof(nextGr)/sizeof(nextGr[0]);
nextGreater(nextGr, nextGrLen);

int miss[] = {0, 1, 2, 6, 9}; //0, 1, 2, 6, 9//4, 5, 10, 11//0, 1, 2, 3
int missLen = sizeof(miss)/sizeof(miss[0]);//0, 1, 2, 3, 4, 5, 6, 7, 10
cout<<"First missing number: "<<firstMissing(miss,0,missLen-1)<<endl;

int occ[]={1, 1, 2, 2, 2, 2, 3};   //{1, 1, 2, 2, 2, 2, 3}
int occLen = sizeof(occ)/sizeof(occ[0]); 
cout<<"No of Occ: "<<countOcc(occ,0,occLen-1,2)<<endl;

return 0;
}

int countOcc(int *arr, int l, int r, int val)
{
//Count number of occurrences in a sorted array in O(LogN)
int idx1 =  leftmostOcc(arr,l,r,val);
int idx2 = rightmostOcc(arr,l,r,val);

if(idx1 == idx2 && idx1 == -1) return 0;

return idx2-idx1+1;
}

int leftmostOcc(int *arr, int l, int r, int val)
{
if(l>r) return -1;

int mid = (l+r)/2;

if(arr[mid]<val)
	return leftmostOcc(arr,mid+1,r,val);

if(arr[mid]>val)
	return leftmostOcc(arr,l,mid-1,val);

if(arr[mid-1] != val)
	return mid;

return leftmostOcc(arr,l,mid-1,val);
}

int rightmostOcc(int *arr, int l, int r, int val)
{
if(l>r) return -1;

int mid = (l+r)/2;

if(arr[mid]<val)
	return rightmostOcc(arr,mid+1,r,val);

if(arr[mid]>val)
	return rightmostOcc(arr,l,mid-1,val);

if(arr[mid+1] != val)
	return mid;

return rightmostOcc(arr,mid+1,r,val);
}

int firstMissing(int *arr, int l, int r)
{
if(l>r) return (arr[r]+1);

int mid = (l+r)/2;

if(arr[mid]==mid)
	return firstMissing(arr,mid+1,r);

if(l==r && l==0) return 0;

if(l==r) return arr[l-1]+1;

return firstMissing(arr, l, mid-1);
}

void nextGreater(int *arr, int len)
{
if(len==0) return;

nextG[len-1] = -1;

for(int i=len-2;i>=0;i--)
	{
		if(arr[i]<arr[i+1])
			{
			nextG[i] = arr[i+1];
			continue;
			}
			
		int idx = i+1;
		while(idx<len)
			{
			if(nextG[idx]>arr[i])
				{
				nextG[i] = nextG[idx];
				break;
				}
			idx++;
			}
			
		if(idx==len) nextG[i] = -1;
	}
cout<<"\nElement		NEXTG"<<endl;
for(int i=0;i<len;i++)
	{
	cout<<"  "<<arr[i]<<"	-->	 "<<nextG[i]<<endl;
	}
cout<<endl;
}

void checkConsecu(int *arr,int len)
{
//https://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
if(len==0) { cout<<"Invalid"<<endl; return; }
if(len==1) { cout<<"YES"<<endl;     return; }

int min = arr[0], max = arr[0];

for(int i=1;i<len;i++)
	{
	if(arr[i]<min) min = arr[i];
	if(arr[i]>max) max = arr[i];
	}
//cout<<max<<" "<<min<<endl;
if(max-min+1 != len)
	{
	cout<<"Nope!!"<<endl;     
	return;
	}
else
	{
	int check[len];
	memset(check,0,sizeof(check));
	
	for(int i=0;i<len;i++)
		{
		int idx = arr[i] - min;
		if(check[idx] != 0)
			{ cout<<"Nope!!"<<endl; return;	}
		check[idx] = 1;
		}
	cout<<"YES"<<endl;
	}
}

int equilibrium(int *arr,int len)
{
if(len<=2) return -1;

stack<int> s;
int initialSum =0, secondSum=0;
for(int i=0;i<len-1;i++)
	{
	initialSum += arr[i];
	s.push(arr[i]);
	}

secondSum = arr[len-1];
int idx = len-2, flag=0;
while(!s.empty())
	{
	int temp = s.top();
	initialSum -= temp;
	if(initialSum == secondSum)
		{
		flag = 1;
		break;
		}
	
	idx--;
	s.pop();
	secondSum += temp;
	}
if(flag==1) return idx;
else return -1;
}

//Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted -->> make a new array, copy elements, sort it, then compare it's elements with the original one, from left as well as right. First unmatched value from both the sides would be the two indexes

int maxDiff(int *arr, int len)
{
//such that larger element appears after the smaller number
if(len<=1) return -1;

int max = arr[0], min = arr[0], diff = -1;

for(int i=1;i<len;i++)
	{
	if(arr[i]>max) max = arr[i];
	
	if(max != arr[0])
		if(diff < max-min) diff = max-min;
	
	if(min>arr[i]) min = arr[i];
	}
return diff;
}

void unionIntersection(int *arr1,int len1,int *arr2,int len2)
{
//Union and Intersection of two sorted arrays
//duplicates are not handled in this implementation, could use "map"
if(len1 == 0 && len2 == 0)
	{
	cout<<"Both are null"<<endl; return;
	}
int un[len1+len2]={0}, in[(len1>=len2)?len2:len1]={0};

int i1=0, i2=0, i3=0;

while(i1<len1 && i2<len2)
	{
	if(arr1[i1]==arr2[i2])
		{
		un[i3++] = arr1[i1];
		i1++; i2++; continue;
		}
	if(arr1[i1]<arr2[i2])
		un[i3++] = arr1[i1++];
	else
		un[i3++] = arr2[i2++];
	}
while(i1<len1)
	{
	if(arr1[i1] != un[i3-1])
		un[i3++] = arr1[i1++];
	}
while(i2<len2)
	{
	if(arr2[i2] != un[i3-1])
		un[i3++] = arr2[i2++];
	}
cout<<"Union: ";
for(int i=0;i<(len1+len2) && un[i]!=0;i++)
	cout<<un[i]<<" ";
cout<<endl;

i1=i2=i3=0;
int size = (len1>=len2)?len2:len1;

while(i1<len1 && i2<len2)
	{
	if(arr1[i1]==arr2[i2])
		{
		in[i3++] = arr1[i1];
		i1++; i2++; continue;
		}
	if(arr1[i1]<arr2[i2])
		i1++;
	else
		i2++;
	}
cout<<"Intersection: ";
for(int i=0;i<size && in[i]!=0;i++)
	cout<<in[i]<<" ";
cout<<endl;

}

void smallestTwo(int *arr, int len)
{
if(len<2)
	{
	cout<<"Invalid Input"<<endl; return;
	}
int min1,min2;

if(arr[0]>=arr[1])
	{
	min1=arr[1]; min2=arr[0];
	}
else
	{
	min1=arr[0]; min2=arr[1];
	}

for(int i=2;i<len;i++)
	{
	if(arr[i]<=min1)
		{
		min2 = min1; min1 = arr[i]; continue;
		}
	if(min1<arr[i] && min2>arr[i])
		{
		min2 = arr[i]; continue;
		}
	}
	
cout<<"Smallest:"<<min1<<" and 2nd smallest:"<<min2<<endl;
}

void sumClosestToZero(int *arr,int len)
{
//apply sorting first, if the array is not sorted. I am skipping that here
int l=0, r=len-1,min = INT_MAX,sum=0,minL,minR;

if(len <2)
	{
	cout<<"Invalid input"<<endl; return;
	}

while(l<r)
	{
	sum = arr[l] + arr[r];
	if(sum==0)
		{
		minL = l; minR = r; break;
		}
	if(abs(sum)<min)
		{ 
		min = abs(sum);
		minL = l; minR = r;
		}
	if(sum<0)
		l++;
	else
		r--;
	}
cout<<"Elements are: "<<arr[minL]<<" and "<<arr[minR]<<endl;
}

void largestSubArr(int *arr, int len)
{
int max_endHere = 0, max = 0;
for(int i=0;i<len;i++)
	{
	max_endHere+=arr[i];
	if(max_endHere<0)
		{
		max_endHere = 0; continue;
		}
	if(max_endHere > max)
		max = max_endHere;	
	}
cout<<"Max SubArray Sum: "<<max<<endl;
}

int maxSumNoAdj(int *arr, int len, int sum, int idx)
{
if(idx >= len) return sum;

int smallAns1=0, smallAns2=0;
smallAns1 = maxSumNoAdj(arr,len,sum+arr[idx],idx+2); //current chosen
smallAns2 = maxSumNoAdj(arr,len,sum,idx+1);      //current not chosen

return (smallAns1>=smallAns2)?smallAns1:smallAns2;
}

void mergeMN(int *arr1,int *arr2, int m, int n)
{
int end1 = m-1, temp = m-1;
while(temp>=0)  //putting -1s at the beginning
	{
	if(arr1[temp] != -1)
		{
		arr1[end1--] = arr1[temp];
		}
	temp--;
	}
int ptr1 = ++end1, ptr2 = 0, k = 0;

while(ptr1<m && ptr2<n)
	{
	if(arr1[ptr1] <= arr2[ptr2])
		arr1[k++] = arr1[ptr1++];
	else
		arr1[k++] = arr2[ptr2++];
	}
if(ptr1<m)
	{
	while(ptr1<m)
		arr1[k++] = arr1[ptr1++];
	}
else
	{
	while(ptr2<n)
		arr1[k++] = arr2[ptr2++];
	}
}

void searchRotated(int *arr, int l, int r, int val)
{
if(l>r)
	{
	cout<<"Key not Found!"<<endl; return;
	}
int mid = (l+r)/2;
if(arr[mid] == val) 
	{
	cout<<"Key:"<<val<<" found at index:"<<mid<<endl; return;
	}
if(val > arr[mid])
	{
	if(arr[r]>=arr[mid] && val<=arr[r])
		return searchRotated(arr,mid+1,r,val);
	if(arr[r]>=arr[mid] && val>arr[r])
		return searchRotated(arr,l,mid-1,val);
	if(arr[r]<arr[mid])
		return searchRotated(arr,mid+1,r,val);
	}
// val < arr[mid]
if(arr[l]<=arr[mid] && val>=arr[l])
		return searchRotated(arr,l,mid-1,val);
if(arr[l]<=arr[mid] && val<arr[l])
		return searchRotated(arr,mid+1,r,val);
return searchRotated(arr,l,mid-1,val);
}

int uglyNo(int n)
{
if(n==1) return 1;

int arr[n+1] = {0};
arr[1] = 1;
vector<int> vec;
vec.push_back(1);

return -1;
}

int MaxSubArr(int *arr, int sum, int size, int idx)
{
if(size==0 || idx == size)
	return sum;

return -1;
}

//map<int, int> m;
//m[2] = 3;  //shortcut
//cout<<m[2];  //see bitwise XOR
//XOR of all elements gives us odd occurring element. Please note that XOR of two elements is 0 if both elements are same and XOR of a number x with 0 is x.
