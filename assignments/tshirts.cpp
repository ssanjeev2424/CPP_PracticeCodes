#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,n2;
cin>>n;
while(n--)
{
	cin>>n2;
	int arr[10][100]={0},i=0,j;
	char temp;
	while(n2--)
	{
		do{
		j=0;
		scanf("%d%c",&arr[i][j++],&temp);
		}while(temp!='\n');
	i++;
	}
	cout<<" = "<<arr[0][1];
	for(int i=0;i<n2;i++)
	{
	j=0; cout<<" = ";
	while(arr[i][j]!=0)
	cout<<arr[i][j++]<<" * ";

	cout<<endl;
	}
}
return 0;
}
