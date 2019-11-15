#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define M 1000000007
string solution(string &s);
int main()
{
string str, ans=""; cin>>str;
//cout<<c-'a';
int prev = -1;
char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
for(lli i=0;i<str.length();i++)
	{
	if(str[i] != '?')
		{
		ans += str[i];
		prev = str[i]-'a';
		}
	else
		{
		if(i != str.length()-1)
			{
			if(str[i+1] != arr[(prev+1)%26])
				{
				ans += arr[(prev+1)%26];
				prev = (prev+1)%26;
				}
			else
				{
				ans += arr[(prev+2)%26];
				prev = (prev+2)%26;
				}
			}
		else
			ans += arr[(prev+1)%26];
		}
	}
string z = "a??c?c???";
cout<<solution(z)<<endl;
return 0;
}

string solution(string &riddle)
{
string ans="";
int prev = -1;
char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
for(int i=0;i<riddle.length();i++)
	{
	if(riddle[i] != '?')
		{
		ans += riddle[i];
		prev = riddle[i]-'a';
		}
	else
		{
		if(i != riddle.length()-1)
			{
			if(riddle[i+1] != arr[(prev+1)%26])
				{
				ans += arr[(prev+1)%26];
				prev = (prev+1)%26;
				}
			else
				{
				ans += arr[(prev+2)%26];
				prev = (prev+2)%26;
				}
			}
		else
			ans += arr[(prev+1)%26];
		}
	}
return ans;
}
