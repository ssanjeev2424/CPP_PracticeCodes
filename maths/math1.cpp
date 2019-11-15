#include<bits/stdc++.h>
using namespace std;

long long int power(int,int); bool parity(unsigned int); bool power2(int);
void permuteBT(char *,int,int); void swap(char*,char*);
unsigned int revBits(unsigned int); bool luckyNo(int);
int multiplyRecursive(int,int);

int main()
{
cout<<"Power N: "<<power(2,12)<<endl;
cout<<"Parity: "<<(parity(15)?"Odd":"Even")<<endl;
cout<<"Power of 2:"<<(power2(1024)?"Yes":"No")<<endl;

char per[] = "ABC";
cout<<"Permutation with BT:"; permuteBT(per,0,strlen(per)-1); cout<<endl;

cout<<"Reverse Bits: "<<revBits(2147483648)<<endl;
cout<<"Lucky No: "<<(luckyNo(19)?"Yes":"No")<<endl;
cout<<"Multiply with Recursion: "<<multiplyRecursive(7,-15)<<endl;

return 0;
}

int multiplyRecursive(int a,int b)
{
if(b==0) return 0;

if(b>0) return a+multiplyRecursive(a,b-1);

return -multiplyRecursive(a,-b);
}

bool luckyNo(int num)    // https://www.geeksforgeeks.org/lucky-numbers/
{
static int counter = 2;

if(num % counter == 0) return false;

if(counter > num) return true;

int nextPos = num - num/counter;

counter++;
return luckyNo(nextPos);
}

unsigned int revBits(unsigned int num)
{
//cout<<sizeof(num)<<endl;  // it is 4 bytes, so we * by 8 to get bits
unsigned int noOfBits = sizeof(num)*8;
unsigned int reverse = 0,i,temp;

for(i=0;i<noOfBits;i++)
	{
	temp = (num & (1<<i)); //get the ith bit of num
	if(temp) 		//if it's 1
		{ 
		reverse |= (1 << ((noOfBits-1)-i));  //add it to rev, in a reverse order, [(NO_OF_BITS – 1) – i]th position 
		}
	}
//it's a 32 bits number, so reverse of 1 is 2147483648, and reverse of 2147483648 is 1

return reverse;
}

void permuteBT(char *arr,int idx,int end) //backtracking
{
if(idx == end) //only one character to arrange. So print it
	printf("%s ",arr);
else
	for(int i=idx;i<=end;i++)
		{
		swap(arr+idx,arr+i);
		permuteBT(arr,idx+1,end);
		swap(arr+idx,arr+i);
		}
}

void swap(char *x, char *y)
{
char t = *x;
*x = *y;
*y = t;
}

bool power2(int x)
{
//all power of two numbers have only one bit set.So count the no. of set bits and if you get 1 then number is a power of 2

// OR If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset. f a number n is a power of 2 then bitwise & of n and n-1 will be zero

return x && (!(x & (x-1))); //also the number itself shouldn't be 0

//A simple method for this is to simply take the log of the number on base 2 and if you get an integer then number is power of 2. return (ceil(log2(n)) == floor(log2(n))); 

//Another solution is to keep dividing the number by two, i.e, do n = n/2 iteratively. In any iteration, if n%2 becomes non-zero and n is not 1 then n is not a power of 2. If n becomes 1 then it is a power of 2.
}

bool parity(unsigned int n) // even no of 1s (in binary)-->> Even parity
{
bool parity = 0;
while(n != 0)
	{
	parity = !parity;
	n = n & (n-1);  // Unset rightmost set bit
	}
return parity;
}

long long int power(int x, int y) // negative powers not handled
{
if(y==0) return 1;

long long int smallAns = power(x,y/2);

if(y%2 == 0)
	return smallAns*smallAns;

return smallAns*smallAns*x;
}

//If difference between count of odd set bits (Bits set at odd positions) and even set bits is multiple of 3 then the actual number is a multiple of 3 -->> O(logN) soln

//We can multiply a number by 7 using bitwise operator. First left shift the number by 3 bits (you will get 8n) then subtract the original numberfrom the shifted number and return the difference (8n – n).

/*      Power set P(S) of a set S
Set  = [a,b,c]  , set_size = 3
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> Empty set
    001                    -> a
    010                    -> b
    011                    -> ab
    100                    -> c
    101                    -> ac
    110                    -> bc
    111                    -> abc 
    
    for(counter = 0; counter < pow_set_size; counter++) 
    { 
    for(j = 0; j < set_size; j++) 
    { 
        Check if jth bit in the counter is set 
            If set then print jth element from set 
        if(counter & (1 << j)) 
            cout << set[j]; 
    } 
*/

// https://www.geeksforgeeks.org/russian-peasant-multiply-two-numbers-using-bitwise-operators/

/* A number n is a power of 4 if following conditions are met.
a) There is only one bit set in the binary representation of n (or n is a power of 2)
b) The count of zero bits before the (only) set bit is even */


