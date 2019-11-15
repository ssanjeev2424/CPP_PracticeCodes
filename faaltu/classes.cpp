#include<bits/stdc++.h>
using namespace std;

class Animal{
	private:
	int height,weight;
	string name;
	static int numOfAnimals;

	public:
	int getH(){ return this->height; }

	string getName() { return this->name; }
	
	void setH(int h) { this->height = h; }

	void setN(string name) { this->name = name; }

	Animal(int, int, string); //constructor

	~Animal(); //destructor

	Animal(){ numOfAnimals++; }

	static int getNoOfAnimals() { return numOfAnimals; }
};

int Animal::numOfAnimals = 0;

Animal::Animal(int h, int w, string name)
{
		Animal::numOfAnimals++; this->height = h; this->weight = w;
		this->name = name; }

Animal::~Animal(){
cout<<"Animal "<<this->name<<" destroyed"<<endl; }



int main()
{

Animal fred;
fred.setH(33); fred.setN("FreD"); 
Animal john(22, 44, "john");
cout<<fred.getH()<<" "<<john.getH()<<endl;
return 0;
}


