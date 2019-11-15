#include<bits/stdc++.h>
using namespace std;

int main()
{
cout<<"Executed Successfully"<<endl;
//vectors are like arrays but their size can change
vector <int> numsV(10);
int lottery[5] = {3,56,7,8,98};
numsV.insert(numsV.begin(),lottery,lottery+3);
//adding first 3 elements of array to Vector

cout<<numsV.at(2)<<endl; //3rd element, i.e index starts with 0  
numsV.push_back(65); //adds at the end

cout<<numsV.front()<<" * "<<numsV.size()<<" * "<<numsV.at(5)<<endl;

return 0;
}
