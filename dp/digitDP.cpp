#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<int> num;
int a,b,d,k;
int dp[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int count, int f) //count-->>of digit d
{   //starting from MS.Digit, ending at the LS.Digit

if(count > k) return 0;

if(pos == num.size()) return (count == k);

if(dp[pos][count][f] != -1) return dp[pos][count][f];

int res = 0;

int digitsAllowed; //till what number

if(f == 0)
	{
	/// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        digitsAllowed = num[pos];
	}
else
	{
	        /// The number has already become smaller than b. We can place any digit now.
	digitsAllowed = 9;
	}

for(int dgt=0; dgt<=digitsAllowed; dgt++)
	{
	int nf = f, nCount = count;
	if(f==0 && dgt<digitsAllowed)//The number is getting smaller at this position
		nf = 1; //so in further recursive calls from this, any digit can be chosen
	
	if(dgt == d) nCount++;
	
	if(nCount <= k) res += call(pos+1,nCount,nf);
	}

return dp[pos][count][f] = res;
}

int solve(int b)
{
num.clear();
while(b>0)
	{
	num.push_back(b%10);
	b /= 10;
	}
reverse(num.begin(), num.end()); //digits of b,  num[0]==MS.Digit

memset(dp,-1,sizeof(dp));
int res = call(0,0,0);
return res;
}

int main()
{
// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?
cin >> a >> b >> d >> k;
int res = solve(b) - solve(a-1);
cout << res << endl;	
return 0;
}
