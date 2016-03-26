/*
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the Ts digit is at the
head of the list. Write a function that adds the two numbers and returns the sum
as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912.
*/


#include<iostream>
struct list{
	unsigned short digit;
	struct list *ptr;
	
};

struct list * add(struct list *, struct list *);
int main()
{
	int n1,n2;
	std::cout<<"Enter two numbers: "<<std::endl;
	std::cin>>n1>>n2;
	int temp1,temp2;
	temp1=n1%10;
	struct list *start = new struct list;
	start->digit = temp1;
	n1 = n1/10;
	struct list *temp=start;
	while(n1)
	{
		temp1 = n1%10;
		temp->ptr=new struct list;
		temp->ptr->digit = temp1;
		temp=temp->ptr;
		n1/=10;
					
	} 
	temp->ptr = '\0';
	
	temp2=n2%10;
	struct list *start1 = new struct list;
	start1->digit = temp2;
	n2 = n2/10;
	struct list *tmp=start1;
	while(n2)
	{
		temp2 = n2%10;
		tmp->ptr=new struct list;
		tmp->ptr->digit = temp2;
		tmp=tmp->ptr;
		n2/=10;
				
	} 
	tmp->ptr='\0';
	/*
	temp=start;
	while(temp)
	{
		std::cout<<temp->digit<<"->";
		temp=temp->ptr;
	}
	std::cout<<std::endl;
	temp=start1;
	while(temp)
	{
		std::cout<<temp->digit<<"->";
		temp=temp->ptr;
	}
*/
	
	
	temp = add(start,start1);

	while(temp)
	{
		std::cout<<temp->digit<<"->";
		temp=temp->ptr;
	}

	return 0;
}

struct list * add(struct list *tmp, struct list *tmp1)
{
	
	unsigned int temp = tmp->digit + tmp1->digit;
	struct list *start = new struct list;
	start->digit= temp%10;
	//std::cout<<start->digit<<"->";
	unsigned int carry=temp/10;
	tmp=tmp->ptr;
	tmp1=tmp1->ptr;
	struct list *t=start;
	
	while(tmp||tmp1)
	{	
		if(tmp=='\0')
		{	t->ptr = new struct list;
			t->ptr->digit = (tmp1->digit + carry)%10;
			//std::cout<<t->ptr->digit<<"->";
			carry = (tmp1->digit + carry)/10;
			tmp1 = tmp1->ptr;
		}
		else if(tmp1=='\0')
		{	t->ptr = new struct list;
			t->ptr->digit = (tmp->digit + carry)%10;
			//std::cout<<t->ptr->digit<<"->";
			carry = (tmp->digit + carry)/10;
			tmp=tmp->ptr;
		}
				
		else{
			t->ptr = new struct list;
			t->ptr->digit = (tmp->digit +tmp1->digit+carry)%10;
			//std::cout<<t->ptr->digit<<"->";
			carry = (tmp->digit + tmp1->digit +carry)/10;
			tmp1 = tmp1->ptr;
			tmp=tmp->ptr;
		}
		
		t= t->ptr;
	}
	if(carry!=0)
	{
		t->ptr = new struct list;
		t->ptr->digit = carry;
		//std::cout<<t->digit<<"->";
		t=t->ptr;
	}
	t->ptr='\0';
	

	return start;
	
}
