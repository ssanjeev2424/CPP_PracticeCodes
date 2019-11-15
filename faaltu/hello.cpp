#include<iostream>
#include<vector>
#include<string>


using namespace std;
typedef int feet; //means "feet" is another name of "int"

int main()
{
feet x = 5,number;
cout<<"Hello**** World"<<endl;  //we would have to use "std::cout" without the
//std::cout<<"Hello ji";			// namespace

const double PI = 3.14156;
char myGrade = 'S';
bool isHappy = true;
cout<<"Favourite: "<<x<<endl;
cout<<"Size of int: "<<sizeof(x)<<endl;
cout<<"5 % 2 = "<<5%2<<" and 4/5="<<4/5<<endl;
cout<<"but with casting: 4/5 = "<<(float)4/5<<endl;
int randNum = (rand()%100) + 1;
while(randNum != 100)
{
cout<<randNum<<", ";
randNum = (rand()%100) + 1;
}
cout<<endl<<"Enter a number: ";
//cin>>number;
//cout<<"Entered no is: "<<number<<endl;
char happy[6] = { 'H','a','p','p','y','\0'}; 
string birthday = " Birthday";
cout<<endl<<happy + birthday<<endl;
string name = "Sanjeev SHarma";
string name2 = name.assign(name); //read about string methods
string name3 = name.assign(name,0,5); //also changes "name"
cout<<name<<" * "<<name2<<" * "<<name3<<endl;
return 0;
} 
