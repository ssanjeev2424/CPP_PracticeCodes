#include<bits/stdc++.h>
using namespace std;
void codes(string,string);

string s("abcdefghijklmnopqrstuvwxyz");

int main()
{
//string ss = "123";
//string ss2 = ss.substr(0,1);
//int i = stoi(ss2);
codes("1123","");
//string ss = s.substr(0,1) + "anju";
//cout<<s[25];
return 0;
}

void codes(string num, string final) //1123
{
if(num.length() == 0 && final.length() ==0) return;
if(num.length() == 0 && final.length() != 0) {cout<<final<<endl; return;}

if(num.length() == 1){
	cout<<final + s.substr(stoi(num)-1,1)<<endl; return; }

if(num.front()=='1'){
	codes(num.substr(1),final+s.substr(0,1));
	int index = stoi(num.substr(0,2))-1;
	codes(num.substr(2), final + s.substr(index,1)); return;}

if(num.front()=='2' && stoi(num.substr(1,1))<7){
	codes(num.substr(1),final+s.substr(1,1));
	int index = stoi(num.substr(0,2))-1;
	codes(num.substr(2), final + s.substr(index,1)); return;}

codes(num.substr(1), final + s.substr(stoi(num.substr(0,1))-1,1));

}
