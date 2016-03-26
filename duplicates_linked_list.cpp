/*
Write a program to remove duplicates from an unsorted linked list. How would you solve this problem if a temporary
buffer is not allowed?
*/



#include<iostream>
#include<string>

int main()
{
	std::string arr;
	std::cin>>arr;
	struct list{
		char ch;
		struct list *ptr;
	};
	struct list *temp = new struct list;
	temp->ch=arr[0];
	struct list *start = temp;
	for(int i=1;i<arr.length();i++)
	{
		temp->ptr = new struct list;
		temp->ptr->ch=arr[i];
		temp = temp->ptr;		
	}
	temp->ptr='\0';
	temp=start;
	/*
	while(temp)
	{
		
		std::cout<<temp->ch;
		temp=temp->ptr;
		
	}
	std::cout<<std::endl;
	*/
	struct list *temp2=start;
	struct list *temp1;
	temp = temp2;
	int i=0;
	while(temp2)
	{	
		temp= temp2->ptr;
		temp1=temp2;
		while(temp){
			
		if((temp2->ch)==(temp->ch))
		{	
			temp1->ptr=temp->ptr;
			delete temp;
			temp=temp1->ptr;	
		}
		else	
		{temp1=temp;
		temp = temp->ptr;
		
		}
		}
		temp2 = temp2->ptr;
	}
	temp=start;
	while(temp)
	{
		
		std::cout<<temp->ch;
		temp=temp->ptr;
		
	}
	return 0;
}
