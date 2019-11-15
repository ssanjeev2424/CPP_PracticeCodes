#include<bits/stdc++.h> 
using namespace std;
void displayQ(); void enQ(struct Node*); struct Node* deQ(); bool isEmpty(); void buildTree();
void inorder(struct Node*); void sumInRange(struct Node*,int*,int,int);
//******************************************
struct Node{
	int data;
	struct Node *l=NULL,*r=NULL;
	   };	

struct List{
	struct Node *ref;
	struct List *next=NULL;
	   };

struct List *head=NULL;
struct Node *dummy=(struct Node*)malloc(sizeof(struct Node));
struct Node *root = (struct Node*)malloc(sizeof(struct Node));
int c = 0;

//***********************************************
int main()
{
int arr[] = {1,2,4,7,3,5,6},len;
len = sizeof(arr)/sizeof(arr[0]);

if(len==0)
	cout<<"Empty Array\n";
else 
{
	for(int i=0;i<len;i++)
	{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=arr[i];
	enQ(newNode);
	}
dummy->data = -1;

enQ(dummy);
displayQ();

buildTree();
cout<<"Inorder: "; inorder(root); cout<<endl;
int sum = 0;
int *p = &sum;
sumInRange(root,p,1,3);
cout<<"Sum is: "<<sum<<endl;
}
return 0;
}
//********************************************************
void inorder(struct Node *root)
{
if(root == NULL) return;
inorder(root->l);
cout<<root->data<<" ";
inorder(root->r);
}
//*************************************************
void sumInRange(struct Node *root,int *sum,int l,int r)  //Naive method
{
if(root == NULL) return;

sumInRange(root->l,sum,l,r);

if(root->l == NULL && root->r == NULL)
	{
	c++;
	if(l<=c && c<=r) *sum+=root->data;
	if(c == r) return;
	}

sumInRange(root->r,sum,l,r);
}
//*********************************************************
void buildTree()
{
	struct Node *deleted1 = deQ();
	if(deleted1->data == -1)
	{
	if(head->next == NULL) { root = head->ref; return;}  //only one node remaining. i.e root
	enQ(dummy);  //adding -1 at the end again
	}
	else
	{
		struct Node *deleted2 = deQ();
		if(deleted2->data == -1) { 
				if(head == NULL){ root = deleted1; return; }
				else {  struct Node *newNode1 = (struct Node*)malloc(sizeof(struct Node));
		        		newNode1->l = deleted1; newNode1->data = deleted1->data;
					enQ(newNode1); enQ(dummy); }
					 }
		else { 
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		        newNode->l = deleted1; newNode->r = deleted2;
			newNode->data = deleted1->data + deleted2->data;
		        enQ(newNode);
		     }
	}
	buildTree();
}
//*************************************************
bool isEmpty()  //for queue
{
if(head==NULL) return true;
return false;
}
//*************************************************
void displayQ()
{
struct List *temp=head;
while(temp!=NULL)
{
	cout<<temp->ref->data<<" ";
	temp = temp->next;
}
cout<<endl;
}
//***********************************************
struct Node* deQ()  //delete from BEG
{
if(head==NULL) return NULL;

struct List *temp = head;
head=head->next;
struct Node *item = temp->ref;
//free(temp);  //causing Infinite Loop
return item;
}
//*******************************************************
void enQ(struct Node *ref2)  //add at end
{
struct List *temp = head;
struct List *newNode = (struct List*)malloc(sizeof(struct List));
newNode->ref = ref2;
if(temp==NULL) { head = newNode; return; }

while(temp->next != NULL)
	temp = temp->next;

temp->next = newNode;
}
//*******************************************************
