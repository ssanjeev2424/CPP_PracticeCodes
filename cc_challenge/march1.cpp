#include<bits/stdc++.h>
using namespace std;
void maxSum();

int main()
{
int n;
cin>>n;
while(n--)
{
maxSum();
}
return 0;
}

void maxSum()
{
int n;
cin>>n;
int score[n];
int sumP=0, sumN=0;	
for(int i=0;i<n;i++)
	{
	cin>>score[i];
	if(score[i]>0) sumP++;
	else sumN++;
	}

if(sumP>=sumN) cout<<sumP<<" ";
else cout<<sumN<<" ";

if(sumP==0) cout<<sumN;
else if(sumN==0) cout<<sumP;
else if(sumP>=sumN) cout<<sumN;
else cout<<sumP;

}
