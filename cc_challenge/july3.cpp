#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
#define SIZE 1000000001

bool isPrime(lli); lli maxPrimeFactors(lli);

int main()
{
int t,i; cin>>t; lli arr[5] = {178,196,127,16139,31684}, ans1, ans2;
lli arr2[2] = {14, 31623};
while(t--)
	{
	cout<<1<<" "<<arr[0]<<endl; //178
	cout.flush();
	cin>>ans1;
	if(ans1==arr[4]) //31684
		{
		cout<<1<<" "<<arr2[1]<<endl; //31623
		cout.flush();
		cin>>ans2;
		lli guess = maxPrimeFactors(arr2[1]*arr2[1] - ans2);
		cout<<2<<" "<<guess<<endl;
		cout.flush();
		
		string str; cin>>str;
		if(str=="Yes") continue;
		else break;
		}
	else
		{
		cout<<1<<" "<<arr2[0]<<endl; //14
		cout.flush();
		cin>>ans2;
		
		if(ans1==0 && ans2==0) { cout<<2<<" "<<2<<endl; cout.flush(); }
		else if(ans1==1 && ans2==1) { cout<<2<<" "<<3<<endl; cout.flush(); }
		else if(ans1==4 && ans2==1) { cout<<2<<" "<<5<<endl; cout.flush(); }
		else if(ans1==2 && ans2==0) { cout<<2<<" "<<7<<endl; cout.flush(); }
		else if(ans1==4 && ans2==9) { cout<<2<<" "<<11<<endl; cout.flush(); }
		else if(ans1==3 && ans2==1) { cout<<2<<" "<<13<<endl; cout.flush(); }
		else
			{
			if(ans2==arr[1]) //196
				{
				lli guess = maxPrimeFactors(arr[0]*arr[0] - ans1);
				cout<<2<<" "<<guess<<endl;
				cout.flush();
				}
			else
				{
				lli guess = maxPrimeFactors(arr2[0]*arr2[0] - ans2);
				cout<<2<<" "<<guess<<endl;
				cout.flush();
				}
			}
		string str; cin>>str;
		if(str=="Yes") continue;
		else break;
		
		}
	}
return 0;
}

lli maxPrimeFactors(lli n) 
{ 
	lli maxPrime = -1; 
  
	while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1;
    } 
  
    for (lli i = 3; i <= sqrt(n); i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 
  
    if (n > 2) 
        maxPrime = n; 
  
	return maxPrime; 
} 


bool isPrime(lli n) 
{ 
    if (n <= 1) 
        return false; 
 
    for (lli i = 2; i <= sqrt(n); i++) { 
       if (n % i == 0) { 
            return false;
        } 
    } 
    return true; 
}  

