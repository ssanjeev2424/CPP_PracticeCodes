#include<bits/stdc++.h>
using namespace std;
bool balanced(string, string);
int knapsack(int[],int[],int,int,int,int);
int rod(int[],int,int,int,int);

int main()
{
//string s = "abcd";
//cout<<s.substr(2) + "zz";
//cout<<s[2];
string str = "[2+{3+(4+3)+(9+1)}+0]";
int vajan[5] = {4,3,8,5,4};
int munaafa[5] = {10,20,5,10,20},len = 0; 

if(balanced(str,""))
	cout<<"Balanced."<<endl;
else
	cout<<"Unbalanced !!"<<endl;

len = sizeof(vajan)/sizeof(vajan[0]);
cout<<"Knapsack profit: "<<knapsack(vajan, munaafa,0, 10, len, 0)<<endl;

int prices[8] = {1,5,8,9,10,17,17,20};
len = sizeof(prices)/sizeof(prices[0]);
cout<<"Maxm obtainable value: "<<rod(prices,0,0,len,0)<<endl;

return 0;
}

//QUESTION 7
int rod(int prices[], int munaafa, int curr_len, int max_len, int index)
{
	if(curr_len == max_len) return munaafa;

	if(index == max_len) return -1;

	int smallAns1=0,smallAns2=0;

	smallAns1 = rod(prices,munaafa,curr_len,max_len,index+1);

	smallAns2 = rod(prices,munaafa+prices[index],curr_len+(index+1),max_len,index+1);

	return (smallAns1>=smallAns2)?smallAns1:smallAns2;
}


//QUESTION 6
int knapsack(int vajan[],int munaafa[],int chanda,int aukaat,int len,int index)
{
if(aukaat == 0 || index == len) return chanda;

int smallAns1=0,smallAns2=0;
smallAns1 = knapsack(vajan, munaafa, chanda, aukaat,len,index+1);

if(aukaat>=vajan[index])
smallAns2 = knapsack(vajan, munaafa, chanda+munaafa[index],aukaat-vajan[index],len,index+1);

return (smallAns1>=smallAns2)?smallAns1:smallAns2;
}


//QUESTION 3
bool balanced(string str, string paren){  //paren is used to store the parenthesis captured till now (traversing from left)

if(str.length()==0 && paren.length()==0) return true;

if(str.length()==0 && paren.length()!=0) return false;

if(str.front()=='[' || str.front()=='{' || str.front()=='(')
	{	
	paren.append(str.substr(0,1));
	return balanced(str.substr(1), paren);
	}
else if(str.front()==']' || str.front()=='}' || str.front()==')')
	{
	if(paren.length()==0) return false;
	
	if(str.front()==']') 
			{
		 	if(paren.back()=='[')
				{
				paren.erase(paren.length()-1,1);
				return balanced(str.substr(1),paren);
				} 
		 	return false;
			}
	if(str.front()=='}') 
			{
		 	if(paren.back()=='{')
				{
				paren.erase(paren.length()-1,1);
				return balanced(str.substr(1),paren);
				} 
		 	return false;
			}
	if(str.front()==')') 
			{
		 	if(paren.back()=='(')
				{
				paren.erase(paren.length()-1,1);
				return balanced(str.substr(1),paren);
				} 
		 	return false;
			}
	}
return balanced(str.substr(1),paren);
}


