#include<bits/stdc++.h>
using namespace std;
void sumDigits(int); void sum_first_last(int); void reverse(int);
int menu(int); int triangle(int,int,int);

int sum_tri[100][100];
int dp_tri[100][100];

int main()
{
int n,a,b;
cin>>n;
while(n--)
{
	cin>>a;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		{
		sum_tri[i][j] = 0; dp_tri[i][j] = -1;
		}

	for(int i=0;i<a;i++)
		for(int j=0;j<i+1;j++)
			cin>>sum_tri[i][j];

	cout<<triangle(a,0,0)<<endl; 
}

return 0;
}


int triangle(int n,int i,int j) //SUMTRIAN
{
	if(i==n) return 0;
	
	if(dp_tri[i][j] != -1) return dp_tri[i][j];

	int sum1 = sum_tri[i][j] + triangle(n,i+1,j);
	int sum2 = sum_tri[i][j] + triangle(n,i+1,j+1);

	if(sum1>=sum2) dp_tri[i][j] = sum1;
	else dp_tri[i][j] = sum2;

	return dp_tri[i][j];
}

int menu(int budget) //CIELRCPT
{
	int count = 0;
	double base=2,exp = 11,result=0;
	while(budget!=0&&exp!=-1)
	{
	result = pow(base,exp);
	//cout<<budget%(int)result<<" "<<int(result)<<endl;
	while(budget>=(int)result)
		{
		budget-=(int)result; count++;
		}
	exp--;
	}
return count;
}

void reverse(int num){
	int rev = 0;
	while(num/10 != 0){
	rev = rev*10 + num%10;
	num /= 10;
}
rev = rev*10 + num;
cout<<rev<<endl;
}

void sum_first_last(int num)
{
	int last=0;
	last = num%10;
	while(num/10 != 0) num/=10;
	cout<<last+num<<endl;	
}



void sumDigits(int a)
{
int sum = 0;
while(a/10 != 0)
{
sum += a%10;
a/=10;
}
sum += a;
cout<<sum<<endl;
}
