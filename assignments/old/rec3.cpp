#include <bits/stdc++.h>
using namespace std;
#define lli long long int

struct tree
	{
	int val;
	struct tree *l,*r;
	};

void build(struct tree*,int,int); void preorder(struct tree*);
void maxXor(struct tree*,int,int,int*);
void printDecreasingOrder(struct tree*, int, int);
void search(struct tree*, int , int);

//https://docs.google.com/document/d/1FsSqoN77qnctuVJCNvcpI98X2dHzLe0K3dJZwN1J_eE/edit  -->> Q.9 (Good one)

int main()
{

int a,b,c,x; cin>>a>>b>>c;
struct tree *root = (struct tree*)malloc(sizeof(struct tree));
root->val = 9;
build(root,a,7);
build(root,b,7);
build(root,c,7); preorder(root); cout<<endl;
int ans = 0; cout<<"Enter x:"; cin>>x;
maxXor(root,x,7,&ans);
cout<<"Item from the tree: "<<ans<<" max XOR: "<<(ans^x)<<endl;
cout<<"Decreasing order: ";
printDecreasingOrder(root->r,7,0); printDecreasingOrder(root->l,7,0);
cout<<endl;
search(root,15,7); search(root,150,7); search(root,229,7);
search(root,250,7); search(root,77,7);
return 0;
}

void search(struct tree *root, int num, int t)
{
if(t==-1)
	{
	cout<<"Number "<<num<<" Found!!"<<endl;
	return;
	}

int bit;
if(num & (1<<t)) bit = 1; 
else bit = 0;

if(bit && root->r)
	{
	search(root->r,num,t-1);
	return;
	}
if(bit==0 && root->l)
	{
	search(root->l,num,t-1);
	return;
	}
cout<<"Number "<<num<<" NOT Found!!"<<endl;
}

void printDecreasingOrder(struct tree *root, int t, int ans)
{
if(t==0)
	{
	if(root->val) ans |= (1<<t);
	cout<<ans<<" ";
	return;
	}
if(root->val) ans |= (1<<t);

if(root->r)
	printDecreasingOrder(root->r,t-1,ans);
if(root->l)
	printDecreasingOrder(root->l,t-1,ans);
}

void maxXor(struct tree *root, int num, int t, int *ans)
{
if(t==-1) return;

int bit; // of num, and we want to go to the other bit to maximize the ans
if(num & (1<<t)) bit = 1;
else bit = 0;

if(bit) // is 1, nd we want to go to 0
	{
	if(root->l) // to 0
		maxXor(root->l, num, t-1, ans);
	else // no 0, so gotta go to 1
		{
		*ans |= (1<<t);
		maxXor(root->r, num, t-1, ans);
		}
	return;
	}

// bits is 0, we wanna go to 1

if(root->r) // to 1
	{
	*ans |= (1<<t);
	maxXor(root->r, num, t-1, ans);
	}
else // no 1, so gotta go to 0
	maxXor(root->l, num, t-1, ans);

}

void build(struct tree *root, int num, int t)
{
if(t==-1) return;

if(num & (1<<t)) //means (t+1)th bit from left is 1, should go right
	{
	if(root->r)
		build(root->r,num,t-1);
	else
		{
		root->r = (struct tree*)malloc(sizeof(struct tree));
		root->r->val = 1;
		build(root->r,num,t-1);
		}
	return;
	}

//means (t+1)th bit from left is 0, should go left

if(root->l)
	build(root->l,num,t-1);
else
	{
	root->l = (struct tree*)malloc(sizeof(struct tree));
	root->l->val = 0;
	build(root->l,num,t-1);
	} 	
}

void preorder(struct tree *root)
{
if(root)
	{
		cout<<root->val<<" ";
		preorder(root->l);
		preorder(root->r);
	}
}
