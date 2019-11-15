#include<bits/stdc++.h>
using namespace std;

struct node {
			int data;
			struct node *l,*r;
			};
struct node* newNode(int); void inorder(struct node*);
bool isCousin(struct node*,struct node*,struct node*);
int level(struct node*,struct node*,int); int height(struct node*);
bool isSibling(struct node*,struct node*,struct node*);
int rightLeavesSum(struct node *); int leavesSum(struct node*);
struct node* buildTree(int*,int*,int,int); int index(int*,int,int,int);
void postOrder(struct node*); 
struct node* inSucc(struct node*,struct node*,struct node*);
struct node* leftmost(struct node*);
int kthAnces(struct node*,struct node*,struct node*,int);
void parent(struct node*); int kthAnces2(struct node*,int);
void verticalWidth(struct node*,int); void longestLeafPath(struct node*);

map<struct node*,struct node*> par; int leftWidth=0, rightWidth=0;
map<struct node*,int> pathLen; int longestPath=0;

int main()
{
struct node *root = NULL;
root = newNode(6); root->l = newNode(3); root->r = newNode(5);
root->l->l = newNode(7); root->l->r = newNode(8);
root->r->l = newNode(1); root->r->r = newNode(3);
cout<<"Inorder: "; inorder(root); cout<<endl;
/*	     6                                                  7
	   /   \       <<--Tree1                              /   \
	  3     5                                           11     32
	 / \   / \                   Tree2-->>             /  \   /  \
	7   8 1   3                                       2   66 10  20
                                                     /           /    */
struct node *ptr1, *ptr2;                //         5           50
ptr1 = root->l->r;  ptr2 = root->r->l;  // 8 and 1
if(isCousin(root,ptr1,ptr2))
	cout<<"Yes, they are cousins.."<<endl;
else
	cout<<"Not cousins.."<<endl;

int pre[] = {7,11,2,5,66,32,10,20,50}, in[] = {5,2,11,66,7,10,32,50,20};
int len = sizeof(pre)/sizeof(pre[0]);
struct node *root2 = buildTree(in,pre,0,len-1);
cout<<"PostOrder of built tree: "; postOrder(root2); cout<<endl;

cout<<"Sum of right leaves: "<<rightLeavesSum(root2)<<endl;
cout<<"Sum of leaves: "<<leavesSum(root2)<<endl;
cout<<"Height: "<<height(root2)<<endl;
cout<<"Inorder Succ: "<<inSucc(root2,root2,NULL)->data<<endl;       //of 7
cout<<"Inorder Succ: "<<inSucc(root2,root2->l->r,NULL)->data<<endl;//of 66
(inSucc(root2,root2->r->r,NULL)==NULL)?cout<<"Rightmost node or node not found"<<endl:cout<<"Found"<<endl;                                 //of 20
cout<<"Kth ancestor: "<<kthAnces(root2,root2,root2->r->r->l,1)<<endl;
cout<<"Kth ancestor: "<<kthAnces(root2,root2,root2->r->r->l,2)<<endl;//50's
cout<<"Kth ancestor: "<<kthAnces(root2,root2,root2->r->r->l,3)<<endl;
cout<<"Kth ancestor: "<<kthAnces(root2,root2,root2->r->r->l,4)<<endl;

par[root2] = NULL; parent(root2); cout<<endl;
cout<<"Kth ancestor: "<<kthAnces2(root2->r->r->l,1)<<endl; //of 50's 
cout<<"Kth ancestor: "<<kthAnces2(root2->r->r->l,2)<<endl; // in Tree2
cout<<"Kth ancestor: "<<kthAnces2(root2->r->r->l,3)<<endl;
cout<<"Kth ancestor: "<<kthAnces2(root2->r->r->l,4)<<endl; cout<<endl;

verticalWidth(root2,0);
cout<<"Vertical width: "<<abs(leftWidth)+1+rightWidth<<endl; //1 is root 
leftWidth = rightWidth = 0;                                 // itself

cout<<"Longest L2L path: ";longestLeafPath(root2);cout<<longestPath<<endl;
longestPath=0;
return 0;
}

void longestLeafPath(struct node *root) //don't call this for root==NULL
{
int left=0,right=0,temp=1; //1 for the root itself
if(root->l)
	{
	left = height(root->l);
	longestLeafPath(root->l);
	}
if(root->r)
	{
	right = height(root->r);
	longestLeafPath(root->r);
	}
if((temp+=left+right)>longestPath)
	longestPath = temp;

pathLen[root] = temp;  //couldn't use it
}

void verticalWidth(struct node *root,int width)
{
if(abs(leftWidth) < abs(width))
	leftWidth = width;     //stores left of root
if(rightWidth < width)
	rightWidth = width;    //stores rigth of root

if(root->l)
	verticalWidth(root->l, width-1);
if(root->r)
	verticalWidth(root->r, width+1);
}

int kthAnces2(struct node* ptr, int k)  //method 2 for kth Ancestor
{
if(k==0 || par[ptr]==NULL) return -1;

if(k==1) return par[ptr]->data;

return kthAnces2(par[ptr],k-1);
}

void parent(struct node* root)  //stores the parent of each node
{
if(root==NULL) return;

if(root->l)
	{
	par[root->l] = root;
	parent(root->l);
	}
if(root->r)
	{
	par[root->r] = root;
	parent(root->r);
	}
}

int kthAnces(struct node* root,struct node* curr,struct node* ptr,int k)
{
if(k==0 && ptr!=NULL) return ptr->data;

if(curr==NULL) return -1;

if(curr->l==ptr || curr->r==ptr)
	return kthAnces(root,root,curr,k-1);

int temp;
return (kthAnces(root,curr->l,ptr,k)!=-1)?kthAnces(root,curr->l,ptr,k):kthAnces(root,curr->r,ptr,k);
}

struct node* inSucc(struct node* root,struct node* ptr,struct node* parent)
{
if(root==NULL) return NULL;

if(root==ptr)
	{
	if(ptr->r != NULL)
		return leftmost(ptr->r);
	return parent;
	}
struct node* left = inSucc(root->l,ptr,root);
struct node* right = inSucc(root->r,ptr,parent);

return (left!=NULL)?left:right;
}

struct node* leftmost(struct node* root)
{
struct node* temp = root;
while(temp->l !=NULL)
	temp = temp->l;

return temp;
}

struct node *buildTree(int *in, int *pre, int inStart, int inEnd)
{                               //using PreOrder nd InOrder
static int preIndex = 0;

if(inStart>inEnd) return NULL;

struct node *temp = newNode(pre[preIndex++]);

int inIndex = index(in,inStart,inEnd,temp->data);

if(inIndex == -1) {cout<<"Invalid i/p\n"; return NULL; }

temp->l = buildTree(in,pre,inStart,inIndex-1);
temp->r = buildTree(in,pre,inIndex+1,inEnd);

return temp;
}

int index(int *in, int l, int r, int data) //could use hashing in place
{										  //of this function	
for(int i=l;i<=r;i++)
	if(in[i]==data) return i;

return -1;
}

int height(struct node *root)    //heigth of root = 1
{
if(root==NULL) return 0;

if(!root->l && !root->r) return 1;

return 1 + max(height(root->l), height(root->r));
}

int leavesSum(struct node *root)
{
if(root==NULL) return 0;

if(!root->l && !root->r) return root->data;

return leavesSum(root->l) + leavesSum(root->r);
}

int rightLeavesSum(struct node *root)
{
if(root==NULL) return 0;

if(root->r && !root->r->l && !root->r->r)
	return root->r->data + rightLeavesSum(root->l);

return rightLeavesSum(root->l) + rightLeavesSum(root->r);
}

bool isCousin(struct node *root,struct node *a, struct node *b)
{
if(root==NULL) return false;

if(level(root,a,1)==level(root,b,1) && !isSibling(root,a,b))
	return true;

return false;
}

int level(struct node *root, struct node *a, int lvl)
{
if(root==NULL) return 0;

if(root==a) return lvl;

return max(level(root->l,a,lvl+1), level(root->r,a,lvl+1));
}

bool isSibling(struct node *root,struct node* a,struct node *b)
{
if(root==NULL) return false;

if((root->l==a && root->r==b) || (root->l==b && root->r==a) ||             isSibling(root->l,a,b) || isSibling(root->r,a,b))
	return true;
 
return false; 
}

void inorder(struct node *root)
{
if(root == NULL) return;

inorder(root->l);
cout<<root->data<<" ";
inorder(root->r);
}

void postOrder(struct node *root)
{
if(root == NULL) return;

postOrder(root->l);
postOrder(root->r);
cout<<root->data<<" ";
}

struct node* newNode(int val)
{
struct node *t = (struct node*)malloc(sizeof(struct node));
t->data = val;
t->l = t->r = NULL;
return t;
}

//Two nodes are cousins of each other if they are at same level and have different parents.
