#include <iostream>
using namespace std;

class node{
public:
int data;
node* next;
node* prev;
node()
{
next=NULL;
}

};

class dl{
	public:
	node* head;
	node* tail;	
	
	dl(){
		head=NULL;
		tail=NULL;}
	void insert(int d)
	{

		
		node *temp=new node;
		temp->data=d;
		if(head==NULL)
		{
			head=temp;
			
		}
		else 
		{	tail->next=temp;
			temp->prev=tail;
		}tail=temp;		
		
		tail->next=NULL;
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
				head->prev=temp;
				tail=head;
				head=temp;
				
				}
				else
				{while(i<pos-1)
				current=current->next;
				temp->next=current->next;
				temp->prev=current;
				current->next->prev=temp;
i++;}								
			}
			else if(pos>countItems()+1)
			cout<<"Linked list does not contain this many items"<<endl;
			else
			this->insert(d);
		}
void delet()
{
node * temp;

if(head==NULL)
cout<<"Linked list does not contain this many items"<<endl;
else
{tail->prev->next=NULL;
temp=tail;
tail=temp->prev;
delete temp;
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
head->next->prev=current->next->prev;
temp=current->next;
delete temp;
}
else if(pos>2){while(i<pos-1)
				{current=current->next;
				i++;
				}
temp=current->next;
temp->next->prev=current;
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
	while(current!=NULL)
	{c++;
	current=current->next;
	}return c;
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
dl obj;
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
