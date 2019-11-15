#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* addBeg(struct node*, int); struct node* addEnd(struct node*, int); struct node* reverseK(struct node*,int);
struct node* delBeg(struct node*); struct node* delEnd(struct node*);
void display(struct node*); int Nth(struct node*,int);
void middle(struct node*); void NthFromEnd(struct node*, int);
struct node* pairwiseSwap(struct node*);
void alternateSplit(struct node*, struct node**, struct node**);

bool isEmpty(struct node*);
void push(struct node**, int);
int pop(struct node**); void displayStack(struct node*);

void enQ(struct node**, int); int deQ(struct node**);
void displayQ(struct node*); struct node* reverse(struct node*);

int main()
{
struct node *root = NULL;

cout<<endl;
root = addBeg(root, 34);
root = addBeg(root, 11);
root = addEnd(root, 66);
root = addEnd(root, 100);
root = addEnd(root, 25);
root = addEnd(root, 44); //display(root);
root = delBeg(root);     //display(root);
root = delEnd(root);
root = addEnd(root, 50);    display(root);

struct node *stk = NULL;

cout<<endl;
//displayStack(stk);
//pop(&stk);
push(&stk, 900); push(&stk, 800);
push(&stk, 700); push(&stk, 600); 
//displayStack(stk);
//cout<<"Item popped: "<<pop(&stk)<<endl;
push(&stk, 100);
//displayStack(stk);

struct node *q = NULL;

cout<<endl;
//displayQ(q);
//deQ(&q);
enQ(&q, 444); enQ(&q, 555);
enQ(&q, 666); enQ(&q, 777); 
//displayQ(q);
//cout<<"Item DeQueued: "<<deQ(&q)<<endl;
enQ(&q, 1000);
//displayQ(q);

cout<<endl;
cout<<"Nth Fn: "<<Nth(root,3)<<endl;
middle(root); NthFromEnd(root, 4);
cout<<"Reversed: "; display(root=reverse(root));
cout<<"Now List Becomes: "; display(root); cout<<endl;

root = pairwiseSwap(root); cout<<"After pairwise swap: "; display(root);

struct node *root2 = NULL;
root2 = addBeg(root2,0); root2 = addBeg(root2,1); root2 = addBeg(root2,0);
root2 = addBeg(root2,2); root2 = addBeg(root2,0); root2 = addBeg(root2,3);
cout<<"New "; display(root2); struct node *split1=NULL, *split2=NULL;
alternateSplit(root2, &split1, &split2);
cout<<"Split1 "; display(split1); cout<<"Split2 "; display(split2);
root = reverseK(root, 3); display(root);

return 0;
}

struct node* reverseK(struct node* root, int k)
{
//function to reverse every k nodes 
int k2 = k;
struct node* temp = root, *prev = NULL;

while(k2 != 0 && temp)
	{
	prev = temp;
	temp = temp->next;
	k2--;
	}
prev->next = NULL;
root = reverse(root);

if(temp)
	{
	struct node* temp2 = root;
	while(temp2->next)
		temp2 = temp2->next;
	temp2->next = reverseK(temp, k);
	}
return root;
}

void alternateSplit(struct node *root, struct node **s1, struct node **s2)
{
if(root==NULL) return;
*s1 = addEnd(*s1, root->data);

if(root->next==NULL) return;
*s2 = addEnd(*s2, root->next->data);

alternateSplit(root->next->next, s1, s2);
}

struct node *pairwiseSwap(struct node *root)
{
if(root==NULL || root->next==NULL) return root;

struct node *temp = root->next;
root->next = root->next->next;
temp->next = root;

root->next = pairwiseSwap(root->next);

return temp;
}

struct node* reverse(struct node* root)
{
if(root==NULL || root->next == NULL)
	return root;

struct node *nextNode = root->next;
struct node *rest = reverse(root->next);

root->next = NULL;
nextNode->next = root;
return rest;
}

void NthFromEnd(struct node* head, int n)
{
struct node* temp = head;
int size = 0;

while(temp)
	{
	size++; temp = temp->next;
	}
if(n>size || n<=0)
	{
	cout<<"Invalid N"<<endl; return;
	}
int count = size-n+1; temp = head;

while(--count)
	temp = temp->next;
cout<<n<<"th from End: "<<temp->data<<endl;
}

void middle(struct node* head)
{
if(head == NULL)
	{
	cout<<"Empty List"<<endl; return;
	}
struct node *slow = head, *fast = head;

while(fast->next != NULL && fast->next->next != NULL)
	{
	slow = slow->next;
	fast = fast->next->next;
	}
cout<<"The middle is: "<<slow->data<<endl;
}

int Nth(struct node* head, int n)
{
struct node* temp = head;
int size = 0;

while(temp)
	{
	size++; temp = temp->next;
	}
if(n>size || n <= 0)
	{
	cout<<"Invalid value of N.."; return -1;
	}
temp = head;
while(temp)
	{
	n--;
	if(n == 0)
		{
		return temp->data;
		}
	temp = temp->next;
	}
return -1;
}

void displayStack(struct node *top)
{
cout<<"Stack(Top to Bottom): ";
struct node *temp = top;
while(temp)
	{
	cout<<temp->data<<" ";
	temp = temp->next;
	}
cout<<endl;
}

void displayQ(struct node *top)
{
cout<<"Queue(First to Last): ";
struct node *temp = top;
while(temp)
	{
	cout<<temp->data<<" ";
	temp = temp->next;
	}
cout<<endl;
}

int deQ(struct node** head)
{
if(isEmpty(*head))
	{
	cout<<"UnderFlow!!"<<endl;
	return -1;
	}
struct node *temp = *head;
*head = (*head)->next;

return temp->data;
}

void enQ(struct node **head, int val)
{
*head = addEnd(*head, val);
}

int pop(struct node** top)
{
if(isEmpty(*top))
	{
	cout<<"UnderFlow!!"<<endl;
	return -1;
	}
struct node *temp = *top;
*top = (*top)->next;

return temp->data;
}

void push(struct node** top, int val)
{
*top = addBeg(*top,val);
}

bool isEmpty(struct node* top)
{
if(top == NULL) return true;
return false;
}

struct node *delEnd(struct node *head)
{
if(head == NULL || head->next == NULL)
	return NULL;

struct node *temp = head;

while(temp->next->next != NULL)
	temp = temp->next;

struct node *temp2 = temp->next->next;
temp->next = NULL;
free(temp2);
return head;
}

struct node *delBeg(struct node *head)
{
if(head == NULL)
	return NULL;

struct node *temp = head;
head = head->next;
free(temp);
return head;
}

struct node* addEnd(struct node* head, int val)
{
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = val; newNode->next = NULL;

if(head == NULL)
	{
	head = newNode;
	return head;
	}
struct node *temp = head;

while(temp->next != NULL)
	temp = temp->next;

temp->next = newNode;
return head;
}

struct node* addBeg(struct node* head, int val)
{
struct node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = val;
newNode->next = head;
head = newNode;

return head;
}

void display(struct node *root)
{
struct node* temp = root;
cout<<"List: ";
while(temp!=NULL)
	{
	cout<<temp->data<<" ";
	temp = temp->next;
	}
cout<<endl;
}
