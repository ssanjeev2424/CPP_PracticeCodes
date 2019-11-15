#include <bits/stdc++.h>
using namespace std;
void bits(int);

int main() {
	for(int i=0;i<=100;i++)
	{
		cout<<"("<<i<<") ";
		bits(i); cout<<" XOR "; bits(0);
		cout<<" ("<<0<<") -->> "<<(i^0);
		cout<<" diff: "<<(i^0)-i<<endl;
	}
	return 0;
}

void bits(int num)
{
	string str = "";
	while(num!=0)
	{
		int temp = num%2;
		str = to_string(temp) + str;
		num = num/2;
	}
	cout<<str;
}
