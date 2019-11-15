#include<bits/stdc++.h>
using namespace std;

char maxOcc(string); void remDup(string); void remFromFirst(string,string);
string reverseRec(string); void printPermutations(string,int,int,string);
void firstNonRep(string); bool balParen(string); void revWords(string);
void runLenEncoding(string); void LSWR(string);
string window(string,string); bool anagram(string,string);
void interleavings(string,string,int,int,int,int,string);
bool checkInterL(string,string,string,int,int,int,int,int);

int main()
{
string s = "testeett";
cout<<"Max Occ char: "<<maxOcc(s)<<endl;
remDup("sanjeev sharma");
remFromFirst("geeksforgeeks","mask");
cout<<"Reverse of a string: "<<reverseRec("KakaroTT..!!")<<endl;
cout<<"Permutations: "; printPermutations("abc", 3, 0, ""); cout<<endl;
firstNonRep("GeeksforGeeks");
if(balParen("{()}[]{{}()}")) cout<<"Balanced Parenthesis"<<endl;
else cout<<"Unbalanced Parenthesis"<<endl;
revWords("geeks quiz practice code");
runLenEncoding("wwwwaaadexxxbxxxq");
LSWR("ABDEFGABEF"); LSWR("BBBB"); LSWR("GEEKSFORGEEKS"); LSWR("ABCDEFGHI");
cout<<"Smallest window: "<<window("this is a test string","tist")<<endl;
cout<<"Interleavings: "; interleavings("AB","XY",2,2,0,0,""); cout<<endl;
//cout<<"** "<<s.substr(1,0);
if(checkInterL("AB","XY","AXBY",2,2,0,0,0)) cout<<"Yes, correct string\n";
else cout<<"Nope, not an interleaved string\n";
if(anagram("SILENT","LISTEN")) cout<<"Anagrams.."<<endl;
else cout<<"Not Anagrams..\n";
return 0;
}

bool anagram(string str1, string str2)
{
if(str1.length() != str2.length()) return false;

int chars[256]={0};

for(int i=0;i<str1.length();i++)
	chars[str1[i]]++;
for(int i=0;i<str1.length();i++)
	{
	if(chars[str2[i]]==0) return false;
	chars[str2[i]]--;
	}
return true;
}

bool checkInterL(string str1, string str2, string str3, int len1, int len2, int idx1, int idx2, int idx3)
{
//check whether (len1+len2)==str3.length() or not.(before calling this fn)
if(idx3==str3.length())
	{
	if(idx1==len1 && idx2==len2) return true;
	return false;
	}

if(idx1!=len1 && str3[idx3]==str1[idx1] && idx2!=len2 && str3[idx3]==str2[idx2])
 return checkInterL(str1,str2,str3,len1,len2,idx1+1,idx2,idx3+1) || checkInterL(str1,str2,str3,len1,len2,idx1,idx2+1,idx3+1);

if(idx1!=len1 && str3[idx3]==str1[idx1])
	return checkInterL(str1,str2,str3,len1,len2,idx1+1,idx2,idx3+1);
if(idx2!=len2 && str3[idx3]==str2[idx2])
	return checkInterL(str1,str2,str3,len1,len2,idx1,idx2+1,idx3+1);

return false;
}

void interleavings(string str1,string str2,int len1, int len2, int idx1, int idx2, string runnAns)
{
if(idx1==len1)
	{
	if(idx2==len2)
		{
		cout<<runnAns<<" "; return;
		}
	cout<<runnAns+str2.substr(idx2,len2-idx2)<<" ";
	return;
	}

if(idx2==len2)
	{
	cout<<runnAns+str1.substr(idx1,len1-idx1)<<" ";
	return;
	}

for(int i=0;i<=(len2-idx2);i++)
	{
	string temp = runnAns + str2.substr(idx2,i) + str1[idx1];
	interleavings(str1,str2,len1,len2,idx1+1,idx2+i,temp);
	}
}

string window(string str,string pat)
{
//Find the smallest window in a string containing all characters of another string(pat)
//https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
int len1 = str.length(), len2 = pat.length();
if(len1<len2)
	{
	cout<<"No such Window";
	return "";
	}

int chars_str[256] = {0}, chars_pat[256] = {0};

for(int i=0;i<len2;i++) //occurrence of chars in pat
	chars_pat[pat[i]]++;

int start = 0, startIndex = -1, minLen = INT_MAX, count = 0;//countOfChars

for(int i=0;i<len1;i++)
	{
	chars_str[str[i]]++;
	
	if(chars_pat[str[i]]!=0 && chars_str[str[i]]<=chars_pat[str[i]])
		count++;
	
	if(count == len2)
		{
		while(chars_str[str[start]]>chars_pat[str[start]] ||            chars_pat[str[start]]==0)
			{
			if(chars_str[str[start]]>chars_pat[str[start]])
				chars_str[str[start]]--;
			start++;
			}
		
		int winLen = i-start+1;
		if(minLen>winLen)
			{
			minLen = winLen;
			startIndex = start;
			}
		}
	}
if(startIndex==-1)
	{
	cout<<"No such Window";
	return "";
	}
return str.substr(startIndex, minLen);
}

void LSWR(string str)       //Length of the longest substring without
{                           // repeating chars....O(n) soln
int len = str.length(), idx=0;
int chars[256] = {0}, indexes[len]; memset(indexes,-1,sizeof(indexes));

for(int i=0;i<len;i++)
	{
	if(chars[str[i]]==0)
		{
		chars[str[i]]=1; continue;
		}
	indexes[idx++] = i-1;  //it stores the indexes at which the final non
	memset(chars,0,sizeof(chars)); // rep char is obseerved, when we 
	chars[str[i]]=1;              // traverse from left to rigth
	}                //if duplicate is observed, we start again from there
	
int maxLen,start,end,temp,i;

if(indexes[0]==-1)  //no duplicates found
	{
	cout<<"The whole string doesn't contain any duplicates, so the longest substring without any rep chars: "<<str<<endl; 
	return;
	}
else
	{
	maxLen = indexes[0]-0+1;  //len of first non rep substr from left
	start = 0;  end = indexes[0];
	}

for(i=1;indexes[i]!=-1;i++)
	{
	if((temp=indexes[i]-indexes[i-1]) > maxLen) //we keep on comparing
		{                              //if larger one found, we update it 
		maxLen = temp;
		start = indexes[i-1]+1;  end = indexes[i];
		}
	}
if((temp=(len-1)-indexes[i-1]) > maxLen)//covering the final non rep substr
	{
	maxLen = temp;
	start = indexes[i-1]+1;  end = len-1;
	}
cout<<"The longest nonRepSubstr is of length "<<maxLen<<" and substr is "<<str.substr(start,maxLen)<<endl;
}

void runLenEncoding(string str)
{
if(str.length()==0) { cout<<"Empty string"<<endl; return; }
if(str.length()==1) { cout<<"RunLength Encoding: "<<str<<1<<endl; return; }

int count = 1;
cout<<"RunLength Encoding: ";
for(int i=1;i<str.length();i++)
	{
	if(str[i-1]==str[i]) { count++; continue; }
	
	cout<<str[i-1]<<count;
	count = 1;
	}
	cout<<str[str.length()-1]<<count<<endl;
}

void revWords(string str)
{
if(str.length()<=2) { cout<<"Reversed words: "<<str<<endl; return; }

string ans = "",temp = "";
char space = ' ';

for(int i=0;i<str.length();i++)
{
	if(str[i]==space) { 
			ans = temp + " " + ans; temp = ""; 
			continue; 
			}
	if(i==str.length()-1) { temp+=str[i]; ans=temp+" "+ans; continue;}
	
	temp+=str[i];
}
cout<<"Reversed words:"<<ans<<endl;
}

bool balParen(string str)
{
stack<char> s;
char x;

for(int i=0;i<str.length();i++)
	{
	if(str[i]=='{' || str[i]=='[' || str[i]=='(')
		{ s.push(str[i]); continue; }
		
	if(s.empty()) return false;
	
	switch(str[i])
		{
		case ')':
			x = s.top();
			s.pop();
			if(x != '(') return false;
			break;
		case '}':
			x = s.top();
			s.pop();
			if(x != '{') return false;
			break;
		case ']':
			x = s.top();
			s.pop();
			if(x != '[') return false;
			break;
		default:
			cout<<"Invalid input."<<endl;
			return false;
			break;
		}
	}
	return s.empty();
}

void firstNonRep(string str)
{
if(str.length()<=1) { cout<<"First Non Rep Char: "<<str<<endl; return; }

int arr[256]={0};
for(int i=0;i<str.length();i++)
	arr[str[i]]++;

for(int i=0;i<str.length();i++)
	{
	if(arr[str[i]]==1)
		{
		cout<<"First Non Rep Char: "<<str[i]<<endl;
		break;
		}
	}
}

void printPermutations(string str,int len, int mask, string runnAns)
{
if(mask==(1<<len)-1) {cout<<runnAns<<" "; return; }

	for(int j=0;j<len;j++)
	{
	if((mask & (1<<j)) == 0)
		{
		printPermutations(str,len,mask|(1<<j),runnAns+str[j]);
		}
	}
}

string reverseRec(string str)
{
if(str.length()<=1) return str;

return reverseRec(str.substr(1)) + str[0];
}

void remFromFirst(string str, string mask)
{
//removes the characters from first string which are present in second string
int c[256]={0};

cout<<"First string after masking:";
for(int i=0;i<mask.length();i++)
	c[mask[i]]=1;
for(int i=0;i<str.length();i++)
	{
	if(c[str[i]]!=1) cout<<str[i];
	}
cout<<endl;
}

void remDup(string str)
{
int len;
if((len=str.length())<=1) { cout<<"After Dup removal:"<<str<<endl; return; }

int arr[256]={0};
cout<<"After Dup removal:";
for(int i=0;i<len;i++)
	{
	if(arr[str[i]]==0)
		{
		arr[str[i]]=1;
		cout<<str[i];
		}
	}
cout<<endl;
}

char maxOcc(string str)
{
int max = -1, arr[256]={0},temp;
char ch;

for(int i=0;i<str.length();i++)
	{
	arr[str.at(i)]++;

	if((temp=arr[str.at(i)]) > max)
		{
		max = temp; ch = str.at(i);
		}
	}
return ch;
}
