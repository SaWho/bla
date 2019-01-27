#include <iostream>
using namespace std;

class node{
public:
int data;
node* next;

node()
{
next=NULL;
}

};

class cl{
	public:
	node* head;
	node* tail;	
	
	cl(){
		head=NULL;
		tail=NULL;}
	void insert(int d)
	{

		
		node *temp=new node;
		temp->data=d;
		if(head==NULL)
		{
			head=temp;
			temp->next=head;
		}
		else 
		{	tail->next=temp;
			temp->next=head;
		}tail=temp;		
		
	
	}
	void insertAt(int pos,int d)
		{

			
			node *temp=new node;
			temp->data=d;
			node *current;
			current=head;			
			if(countItems()+1>pos)
			{	
				int i=1;
				if(current->next==NULL)
				{temp->next=head;
				
				tail=head;
				head=temp;
				
				}
				else
				{while(i<pos-1)
				current=current->next;
				temp->next=current->next;
				i++;}								
			}
			else if(pos>countItems()+1)
			cout<<"Linked list does not contain this many items"<<endl;
			else
			this->insert(d);
			
		}
void delet()
{
node * current;
node* temp;
int i=1;
current=head;
if(head==NULL)
cout<<"Linked list does not contain this many items"<<endl;
else
{
while(i<countItems()-1)
{
current=current->next;
i++;
}
temp=tail;
tail=current;
delete temp;
if(i=1)
{
head=NULL;
tail=NULL;
}
tail->next=head;
}
}
void deleteAt(int pos)
{
int i=1;
node * temp;
node* current;
current=head;
if(head==NULL || countItems()<pos)
cout<<"Linked list does not contain this many items"<<endl;
else if(countItems()>pos)
{
if(pos==1)
{
head=current->next;
delete current;
}
else if(pos==2)
{
head->next=current->next->next;
temp=current->next;
delete temp;
}
else if(pos>2){while(i<pos-1)
				{current=current->next;
				i++;
				}
temp=current->next;
current->next=temp->next;
delete temp;
}}
else
this->delet();



}

int countItems(){
	int c=0;
	node *current;
	current =head;
	do
	{c++;
	current=current->next;
	}while(current!=head);
	return c;
}
void display(){
node *k=this->head;
for(int i=1;i<=this->countItems();i++)
{cout<<k->data<<"-> ";
k=k->next;}
cout<<"NULL";
cout <<endl;
}

};




int main(){
cl obj;
int n,m;
for(int i=1;i<=5;i++)
{cin>>n;
obj.insert(n);
}
cout<<"Pos to be inserted,Data to be inserted"<<endl;
cin>>n>>m;
obj.insertAt(n,m);
obj.display();
obj.delet();
obj.display();
cout<<"Pos to be deleted"<<endl;
cin>>n;
obj.deleteAt(n);
obj.display();
return 0;
}
