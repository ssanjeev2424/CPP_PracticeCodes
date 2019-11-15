#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007

int solution(vector<int> &A, int K, int L)
{
int len = (int)(A.size());
if(K+L > len)
	return -1;

int ans = 0, temp1=0, temp2=0 ,i=0, j=K-1;
for(int x=0;x<K;x++)
	temp1 += A[x];

while(j<len)
	{
	if(i>=L)
		{
		temp2 = 0;
		int idx=0,end=L-1;
		
		for(int x=0;x<L;x++)
			temp2 += A[x];
		if(temp1+temp2 > ans) ans = temp1+temp2;
		
		idx++; end++;
		while(end<i)
			{
			temp2 += A[end];
			temp2 -= A[idx-1];
			
			if(temp1+temp2 > ans) ans = temp1+temp2;
			
			idx++; end++;
			}
		}
		
	if(len-j-1 >= L)
		{
		temp2=0;
		int idx=j+1, end = j+L;
		for(int x=idx;x<=end;x++) temp2 += A[x];
		
		if(temp1+temp2 > ans) ans = temp1+temp2;
		idx++; end++;
		
		while(end<len)
			{
			temp2 += A[end];
			temp2 -= A[idx-1];
			
			if(temp1+temp2 > ans) ans = temp1+temp2;
			
			idx++; end++;
			}
		}
	i++; j++;
	if(j<len)
		{
		temp1 += A[j];
		temp1 -= A[i-1];
		}
	}
//cout<<"dsfdsfdfd";
return ans;
}

int main()
{
vector<int> v;
v.push_back(6);
v.push_back(1);
v.push_back(4);
v.push_back(6);
v.push_back(3);
v.push_back(2);
v.push_back(7);
v.push_back(4);
/*cout<<"fsdfsdf";
v.push_back(10);
v.push_back(19);
v.push_back(15);*/
cout<<solution(v,3,2)<<endl;
return 0;
}
