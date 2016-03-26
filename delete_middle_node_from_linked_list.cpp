/*
Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
Input: the node c from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/


#include<iostream>
#include<string>
struct list{
	
	char ch;
	struct list *ptr;
};
void deletenode(struct list *ptr);
int main()
{
std::string str;
std::cout<<"Enter string: \n";	
std::cin>>str;
char arr[str.length()+1];
for(int i=0;i<str.length();i++)
arr[i] = str[i];
arr[str.length()+1] = '\0';	
int length=0;
while(arr[length++]);
length--;
length/=2;
struct list *start = new struct list;
struct list *temp	= start;
start->ch=arr[0];
int i=1;
struct list *del;
while(arr[i])
{
	temp->ptr=new struct list;
	temp->ptr->ch=arr[i];
	if(i==length)
	del=temp->ptr;
	temp=temp->ptr;
	i++;
	
	
}
	
temp->ptr='\0';	
	
deletenode(del);
temp=start;
while(temp){
	
	std::cout<<temp->ch;
	temp=temp->ptr;
	
}	
	return 0;
}
void deletenode(struct list *mid){
	
	while(mid)
	{

		mid->ch = mid->ptr->ch;
		
		if(mid->ptr->ptr=='\0')
		{
		struct list *temp= mid->ptr;
		delete temp;
		mid->ptr='\0';
		
		}
		mid=mid->ptr; 
	}

}
