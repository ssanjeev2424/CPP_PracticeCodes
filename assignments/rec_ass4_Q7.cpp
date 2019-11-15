#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct tree{
	struct node *list;
	struct tree *left,*right;
};

struct node* addEnd(struct node*, int); void display(struct node*);
struct tree* build(int*,int);
void mergeTreeInorder(struct tree*);

int main()
{
int arr[] = {44,75,23,43,55,12,64,77,33};
int len = sizeof(arr)/sizeof(arr[0]);

struct tree *root = build(arr,len);
mergeTreeInorder(root);
return 0;
}

void mergeTreeInorder(struct tree* root)
{
if(root==NULL) return;

mergeTreeInorder(root->left);
display(root->list);
mergeTreeInorder(root->right);
}

struct tree* build(int *arr, int len)
{
if(len==0) return NULL;

struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
temp->list = NULL;

for(int i=0;i<len;i++)
	{
	temp->list = addEnd(temp->list,arr[i]);
	}
if(len==1)
	{
	temp->left = NULL; temp->right = NULL;
	return temp;
	}
int mid = len/2;
int left[mid],right[len-mid],idx=0;

for(int i=0;i<mid;i++)
	left[i] = arr[i];
for(int i=mid;i<len;i++)
	right[idx++] = arr[i];

temp->left = build(left,mid);
temp->right = build(right,len-mid);

return temp;
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

