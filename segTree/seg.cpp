#include <bits/stdc++.h>
using namespace std;

/*  **********SEGMENT TREES***********              29/05/2019

Lazy propagation -->>  https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/     ... it's an optimization to make range updates faster

*/
void buildTree(int*,int,int,int); int sumInRange(int,int,int,int,int);
void update(int,int,int,int,int); void buildRangeMin(int*,int,int,int);
void lazyBuild(int*,int,int,int); 
int rangeSumLazy(int,int,int,int,int);
void updateRange(int,int,int,int,int,int);

int segTree[32], treeMin[32], lazy[32], lazyTree[32];

int main()
{
//memset(segTree,-1,sizeof(segTree));
int arr[] = {1,3,5,7,9,11};
int len = sizeof(arr)/sizeof(arr[0]);

int height = (int)(ceil(log2(len))); //max height of segTree
int maxSize = 2*(int)pow(2,height) - 1; //if n leaves, there are 2n-1 nodes
buildTree(arr,0,len-1,0);              // in total

int temp=1;
for(int i=0;i<maxSize;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<segTree[i]<<" ";
	temp *= 2; cout<<endl;
	}
cout<<"Range Sum: "<<sumInRange(2,4,0,len-1,0)<<endl;
update(0,len-1,0,1,2);

temp=1;
for(int i=0;i<maxSize;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<segTree[i]<<" ";
	temp *= 2; cout<<endl;
	}

buildRangeMin(arr,0,len-1,0);
temp=1;
for(int i=0;i<maxSize;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<treeMin[i]<<" ";
	temp *= 2; cout<<endl;
	}

int lzArr[] = {1,2,3,4,5,6,7};
int lzLen = sizeof(lzArr)/sizeof(int);

lazyBuild(lzArr,0,lzLen-1,0);

int height2 = (int)(ceil(log2(lzLen))); //max height of segTree
int maxSize2 = 2*(int)pow(2,height2) - 1;
temp=1; cout<<"\nLazyTree:\n";
for(int i=0;i<maxSize2;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<lazyTree[i]<<" ";
	temp *= 2; cout<<endl;
	}
updateRange(0,lzLen-1,0,3,0,10);
cout<<"\nLazyTree after update in range:\n";
temp=1;
for(int i=0;i<maxSize2;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<lazyTree[i]<<" ";
	temp *= 2; cout<<endl;
	}
	
updateRange(0,lzLen-1,0,1,0,5);
cout<<"\nLazyTree after 2nd update in range:\n";
temp=1;
for(int i=0;i<maxSize2;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<lazyTree[i]<<" ";
	temp *= 2; cout<<endl;
	}

cout<<"Lazy Sum in range: "<<rangeSumLazy(4,6,0,lzLen-1,0)<<endl;
cout<<"Lazy Sum in range: "<<rangeSumLazy(1,2,0,lzLen-1,0)<<endl;

temp=1;
for(int i=0;i<maxSize2;)
	{
	for(int j=1;j<=temp;j++,i++)
		cout<<lazyTree[i]<<" ";
	temp *= 2; cout<<endl;
	}
return 0;
}

//min element of a RANGE
void buildRangeMin(int *arr,int l,int r,int idx)
{
if(l==r)
	{
	treeMin[idx] = arr[l];
	return;
	}
int mid = (l+r)/2;
buildRangeMin(arr, l    , mid, 2*idx+1);
buildRangeMin(arr, mid+1, r,   2*idx+2);

treeMin[idx]=(treeMin[2*idx+1] < treeMin[2*idx+2])?treeMin[2*idx+1]:treeMin[2*idx+2];
}

//updates the value at index "pos" of original array to 'val", also updates the segment tree
void update(int l, int r, int idx, int pos, int val)
{
if(pos<l || pos>r) return;

if(l==r && l==pos)
	{
	segTree[idx] = val;
	return;
	}

int mid = (l+r)/2;
update(l,     mid, 2*idx+1, pos, val);
update(mid+1, r  , 2*idx+2, pos, val);

segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
}

//updates range startR to endR by +val, i.e each node by "+val", using lazy
void updateRange(int l, int r, int startR, int endR, int idx, int val)
{
if(lazy[idx] != 0)
	{
	lazyTree[idx] += (r-l+1)*lazy[idx];
	if(l != r)
		{
		lazy[2*idx + 1] += lazy[idx];
		lazy[2*idx + 2] += lazy[idx];
		}
	lazy[idx] = 0;
	}
if(r<startR || l>endR) return;

if(l==0 && r==1) cout<<"outside "<<lazyTree[idx]<<endl;
if(startR<=l && r<=endR)
	{
	if(l != r)
	{
		lazy[2*idx + 1] += val;
		lazy[2*idx + 2] += val;
	}
	lazyTree[idx] += (r-l+1)*val;
	if(l==0 && r==1) cout<<"inside "<<lazyTree[idx]<<endl;
	return;
	}

int mid = (l+r)/2;
updateRange(l,     mid, startR, endR, 2*idx+1, val);
updateRange(mid+1, r,   startR, endR, 2*idx+2, val);
lazyTree[idx] = lazyTree[2*idx + 1] + lazyTree[2*idx + 2];
}

//finds the sum between index lb to ub (both inclusive)....l and r are the 
// current state of recursion. i.e current position in segment tree
int sumInRange(int lb, int ub, int l, int r, int idx)
{
if(r<lb || l>ub) return 0;  //out of range

if(lb<=l && r<=ub) return segTree[idx];  //completely inside the range

//partially inside..
int mid = (l+r)/2;
return sumInRange(lb,ub,l,mid,2*idx+1) + sumInRange(lb,ub,mid+1,r,2*idx+2);
}

int rangeSumLazy(int lb, int ub, int l, int r, int idx)
{
if(lazy[idx] != 0)
	{
	lazyTree[idx] += (r-l+1)*lazy[idx];
	if(l != r)
		{
		lazy[2*idx + 1] += lazy[idx];
		lazy[2*idx + 2] += lazy[idx];
		}
	lazy[idx] = 0;
	}
if(l>ub || r<lb) return 0;

if(lb<=l && r<=ub) return lazyTree[idx];

int mid = (l+r)/2;
return rangeSumLazy(lb,ub,l,mid,2*idx+1) + rangeSumLazy(lb,ub,mid+1,r,2*idx+2); 
}

void buildTree(int *arr, int l, int r, int idx)
{
if(l==r)
	{
	segTree[idx] = arr[l];
	return;
	}

int mid = (l+r)/2;
buildTree(arr, l, mid, 2*idx+1);
buildTree(arr, mid+1, r, 2*idx+2);
segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
}

void lazyBuild(int *arr, int l, int r, int idx)
{
if(l==r)
	{
	lazyTree[idx] = arr[l];
	lazy[idx]     = 0;
	return;
	}
int mid = (l+r)/2;
lazyBuild(arr, l,     mid, 2*idx+1);
lazyBuild(arr, mid+1, r,   2*idx+2);

lazy[idx] = 0;
lazyTree[idx] = lazyTree[2*idx + 1] + lazyTree[2*idx + 2];
}
