#include<bits/stdc++.h>
using namespace std;

bool f(int x, int y)
{
return x > y;
}
template <typename type>
struct mycomp
	{
	bool operator()(const type &first, const type &second) const {
	return first<second;
	}
	};
template <typename type>
struct mycomp2
	{
	bool operator()(const type &first, const type &second) const {
	return first.second <second.second;
	}
	};

void vectorDemo()
{
vector<int> v = {11,2,3,14};
cout<<v[1]<<endl;
sort(v.begin(), v.end()); //sorting in ascending order 2,3,11,14   // takes NlogN time
bool present = binary_search(v.begin(), v.end(), 11);

v.push_back(100); //2,3,11,14,100
present = binary_search(v.begin(), v.end(), 100);
v.push_back(100); v.push_back(100); v.push_back(100); v.push_back(100); v.push_back(123);
// 2,3,11,14,100,100,100,100,100,123
cout<<"Vector: ";
for(int x: v)
	cout<<x<<" "<<++x<<" * "; //here "x++" won't change the vector contents
cout<<endl;

//lowerbound nd upperbound can be performed on sorted vectors only
vector<int>::iterator it = lower_bound(v.begin(), v.end(), 100); //gives the iterator to the first occ of number >= 100
auto it2 = upper_bound(v.begin(), v.end(), 100);// first occ of number > 100   //c++ automatically finds out the type of it2 //takes logN time
cout<<*it<<" "<<*it2<<endl;
cout<<it2 - it<<endl; //pointer arithmetic, also...this (it2-it) == count of 100

sort(v.begin(), v.end(), f); //to sort in decreasing order, f is a comparator function(it returns true or False)

vector<int>::iterator it3;
for(it3=v.begin();it3!=v.end();it3++) //printing vector elements
	cout<<*it3<<" ";
cout<<endl;

for(int &x: v) //iterate by reference
	x++; //here "x++" changes the vector contents

for(int x: v)
	cout<<x<<" "; //just printing
cout<<endl<<endl;

}

void setDemo()
{
//to perform the above operations on unsorted elements, we can use SETS
set<int> s;
s.insert(2); s.insert(1); s.insert(11); s.insert(-1);//each in logN time // set maintains the ascending order even while inserting unsorted data
for(int x: s)                                  // we don't need to sort the data again nd again (like in vectors)
	cout<<x<<" ";
cout<<endl; //-1 1 2 11

auto it = s.find(-1); //returns s.end() if -1 is absent, otherwise returns the iterator to -1
if(it != s.end())
	cout<<*it<<endl;

auto it2 = s.lower_bound(0); //gives iterator to first element >= 0
//if there is no lowerBound, it will return s.end()
//we can also erase an element from set in logN time using s.erase(1);

}

void mapDemo()
{
map<int,int> m;
m[1] = 100; m[20] = 200; m[11] = 232; //takes logN time each

map<char,int> count;
string s = "Sanjeev Sharma";
for(char x: s)
	count[x]++;
cout<<count['S']<<" "<<count['a']<<endl; //in logN time

map<char,int> p;
unordered_map<char,int> q;

for(char x: s) p[x]++; // NlogN (N is string's length)
for(char x: s) q[x]++; // time = N, unordered maps can get nd set the values of maps in O(1), whereas Map takes logN

}

void powerOfSTL()
{
set<pair<int,int> > s;
s.insert({2,3});
s.insert({401,450});
s.insert({30,400});
s.insert({10,20});

// the order would be 2,3   10,20     30,400    401,450
//let's say we want to find the interval containing 31, then we could get the upperBound of 31(if the second element of list is greater than 400, so we could use {31,INT_MAX)), it gives 401,500,  then we iterate on element to the left nd then we check whether it contains that term. BOOM!!
// first 1st field is compared, then the second one
// {10,12} < {10,20}   but {10,22} > {10,20}

int point = 32;
auto it = s.upper_bound({point,INT_MAX});
if(it==s.begin())
	{
	cout<<"Is absent\n";
	return;
	}
it--;
pair<int,int> current = *it;
if(current.first <= point && point <= current.second)
	cout<<"It lies in the interval: ["<<current.first<<","<<current.second<<"]\n";
else
	cout<<"Is absent\n";




//set contains elements in ascending order. pair {a,b} is smaller than {c,d} iff (a<c) or (a==c && b<d)
}

void codeForce1()
{
int n; cin>>n;
vector<int> v(n+2,0);  long long S = 0, sDash = 0;
for(int i=0;i<n;i++) cin>>v[i], S+=v[i];
if(S & 1)
	{
	cout<<"NO\n"; return;
	}

unordered_map<long long,int> first,second;

first[v[0]] = 1;

for(int i=1;i<n;i++) second[v[i]]++;

for(int i=0;i<n;i++)
	{
	sDash += v[i]; //first i numbers
	if(sDash==S/2)
		{
		cout<<"YES"<<endl; return;
		}
	
	if(sDash < S/2)
		{
		long long x = S/2 - sDash;
		//delete from second half nd insert in first half
		if(second[x] > 0)
			{
			cout<<"YES"<<endl; return;
			}
		}
	else
		{
		long long y = sDash - S/2;
		//first to second half
		if(first[y] > 0)
			{
			cout<<"YES"<<endl; return;
			}
		}
	
	first[v[i+1]]++;
	second[v[i+1]]--;
	}

cout<<"NO\n";
}

void codesBay()
{
//data Store==Containers     and    data manipulation==algorithms,   but they don't communicate directly to each other
// they communicate via Iterators, data stored in containers are accessed by iterators, algo works on iterators
// container types: Sequence and Associative
//sequence == stores elements in a sequence(vector,list),  associative == stores elements as a key value pair(map,set)
//vector--contiguous memory allocation,    list--doubly link lists
//sort fn can't sort lists, it can sort vectors

//Associative containers
pair<int,int> p = make_pair(10,20);
cout<<p.first<<"-"<<p.second<<endl<<endl;

map<int,int> m;
m[22]=3; m[5]=34; m[34]=45; m[56]=66; m.insert({33,44}); m.insert(make_pair(99,54));

for(auto it=m.begin();it!=m.end();it++) //map iterators returns a pair, so we use pair methods (first nd second)
	cout<<it->first<<"--"<<it->second<<endl; //we automatically got the output in sorted order
cout<<endl<<"Multimap:\n";
//maps maintains the data in sorted order acc to the key, it uses Red Black Tree
//in case of duplicate keys,  insert() fn doesn't update it,  whereas m[key]=value method updates the key with new updated value

//multimap doesn't support the subscript operator m[]=3
multimap<int,int> mm;
mm.insert({10,700});            //multimap also maintains the sorted order of key, multiple values can be mapped to a key
mm.insert({2,20});            //
mm.insert({10,100});
mm.insert({10,200});
mm.insert({12,9});

for(auto it=mm.begin();it!=mm.end();it++) 
	cout<<it->first<<"--"<<it->second<<endl;
cout<<endl;
//unordered map -- elements are not stored in a sorted order, stored as h hash structure, faster than normal map
//unordered multimap also use hash implementation, no sorted order

//*******************Erase Remove Idiom******************
vector<int> v;
v.push_back(10); v.push_back(20); v.push_back(40); v.push_back(30); v.push_back(60); v.push_back(50);
for(int &x: v) cout<<x<<" ";
cout<<endl;

v.erase(v.begin()+1,v.begin()+2); //erase(i,j) deletes i to (j-1) elements,  so it deletes 1st element (starting from 0th)
for(int &x: v) cout<<x<<" ";
cout<<endl;

//remove()--just shifts the desired element to the end(vector size remains the same), then we delete them by erase() ( now size decreses)

//************************Associate Containers***********************
//***********************Comparing elements********************

set<int> myset;  // less<int> comparator is passed by default
myset.insert(40); myset.insert(30); myset.insert(20);
for(auto &x:myset) cout<<x<<" ";  //prints in ascending order
cout<<endl;

set<int,greater<int> > myset2; //greater<int> is a inbuilt comparator
myset2.insert(40); myset2.insert(30); myset2.insert(20);
for(auto &x:myset2) cout<<x<<" ";  //prints in descending order
cout<<endl;

//comparators can also be used inside the maps

set<pair<int,int>, mycomp2<pair<int,int> > > set1;
set1.insert({40,10}); set1.insert({30,250}); set1.insert({20,200}); 
for(auto &i:set1)
	cout<<i.first<<"->"<<i.second<<endl;
cout<<endl;

//*******************Container Adapters******************* stack queue and priority queues
//******************Map, filter nd reduce equivalent*************************


}

template <typename T>
T square(T x)
{
return x*x;
}

template <typename T>
class BoVector {
	T arr[100];
	int size;
	
	public:
		BoVector():size(0){}
		void push(T x) { arr[size]=x; size++; }
		void print() const {for(int i=0;i<size;i++) { cout<<arr[i]<<" "; } cout<<endl;}
};

void BoQian()
{
cout<<square<int>(5)<<" "<<square<double>(5.5)<<endl;

BoVector<int> bv;
bv.push(3); bv.push(13); bv.push(23); bv.push(30); bv.push(11);
bv.print();
}

int main()
{
codesBay();
return 0;
}
