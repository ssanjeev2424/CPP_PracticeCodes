#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

void largerThanK(vector<char> &vec, char ch)
{
/*auto it = upper_bound(vec.begin(), vec.end(), ch);
if(it==vec.end()) cout<<vec[0]<<endl;
else cout<<*it<<endl; */ //using upper_bound

int l=0, r=vec.size()-1, ans=0;

while(vec[r]>ch && l<r)
	{
	int mid = (l+r)/2;
	
	if(vec[mid]<=ch)
		l = mid+1, ans=mid+1;
	else
		r = mid, ans=mid;
	}
cout<<vec[ans]<<endl;
}

//https://www.geeksforgeeks.org/smallest-alphabet-greater-than-a-given-character/
int main()
{
int n; cin>>n; char x,k; vector<char> vec;
while(n--)
	{
	cin>>x;
	int asc = x;
	if(asc>90) vec.push_back(asc-32);
	else vec.push_back(asc);
	}	
cout<<"Enter K: "; cin>>k;
if(k>90) k -= 32;
largerThanK(vec, k);
return 0;
}
