#include<bits/stdc++.h>
using namespace std;
//12:22 -->> 65%
struct node
{
	int data;
	struct node *l=NULL,*r=NULL;
};

node* add(int); void inorder(node *); void insertLevelOrder(node *,int);
void levelOrderSpiral(node *);

node *root=NULL;
int main()
{
root = add(1);
root->l = add(2);
root->r = add(3);
root->l->l = add(4);
inorder(root); cout<<endl;
insertLevelOrder(root, 56);
insertLevelOrder(root, 100);
insertLevelOrder(root, 99);
inorder(root); cout<<endl;
levelOrderSpiral(root); cout<<endl;
return 0;
}

void levelOrderSpiral(node *root)
{
if(root == NULL) return;

int lToR=0,rToL=1; //direction

stack<node *> s1,s2;
int flag = 0;
s2.push(root);

while(flag==0)
	{
//cout<<"size is: "<<n<<endl;
	if(lToR==1)
		{
		int n = s1.size();
		while(n--)
			{
			node *temp = s1.top();
			cout<<temp->data<<" ";
			if(temp->l!=NULL) {s2.push(temp->l); flag=0;}
			else flag=1; 
			if(temp->r!=NULL) {s2.push(temp->r); flag=0;}
			else flag=1;
			s1.pop();
			}
		lToR = 0; rToL = 1;
		}
	else		
		{
		int n = s2.size();
		while(n--)
			{
			node *temp = s2.top();
			cout<<temp->data<<" ";
			if(temp->r!=NULL) {s1.push(temp->r); flag=0;}
			else flag=1; 
			if(temp->l!=NULL) {s1.push(temp->l); flag=0;}
			else flag=1;
			s2.pop();
			}
		lToR = 1; rToL = 0;
		}

	}

}

void insertLevelOrder(node *root1,int d)
{
if(root1==NULL)
	{
	root = add(d);
	return;
	}

queue<node *> q;
node *temp1,*temp2;
int flag1 = 0, flag2 = 0;
q.push(root);

while(!q.empty())
	{
	int n = q.size();
	while(n--)
		{
		if((temp1=q.front()->l) == NULL)
			{
			flag1 = 1; break;
			}
		if((temp2=q.front()->r) == NULL)
			{
			flag2 = 1; break;
			}
		q.push(temp1); q.push(temp2);
		q.pop();
		}

	if(flag1 == 1 || flag2 == 1) break;
	}
node *newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = d;

if(flag1 == 1)
	q.front()->l = newNode;
else
	q.front()->r = newNode;
}

void inorder(node *root)
{
if(root==NULL) return;

inorder(root->l);
cout<<root->data<<" ";
inorder(root->r);
}

node *add(int d)
{
node *temp = (struct node*)malloc(sizeof(struct node));
temp->data = d;
temp->l = NULL;
temp->r = NULL;

return temp;
}
