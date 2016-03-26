/*
Given a positive integer, print the next smallest and the next largest number
that have the same number of 1 bits in their binary representation.
*/


#include<iostream>
#include<bitset>
void reverse(unsigned int *);
int main()
{
	unsigned int a=64;
	//std::cout<<sizeof(int)<<std::endl;
	std::cout<<"Enter number"<<std::endl;
	std::cin>>a;
	std::cout<<"a = \n"<<std::bitset<32>(a)<<std::endl;
	/*
	int i=0;
	
	while(a==temp)
	{
		temp |= (1<<i);
		i++;
		if(i==sizeof(unsigned int))
		{
			std::cout<<"Cannot find smallest or largest!";
			return 1;
		}
	}
	//std::cout<<std::bitset<32>(temp)<<std::endl;
	
	unsigned int k;
	i--;
	*/
	unsigned int temp=a;
	unsigned int j=31;
	unsigned int i=0;
	unsigned int h=33;
	while(j>0)
	{
		
		if(a & (1<<j))
		{
			h=j;
		}
		j--;
	}
	if(h==1 && (a & 1<<j)|| h==33)
	std::cout<<"Cannot find smallest!"<<std::endl;
	else{
	
	temp &= ~(1<<h);
	h--;
	temp |= (1<<h);
	std::cout<<"Next smallest = \n"<<std::bitset<32>(temp);
	}
	
	temp=a;
	reverse(&temp);
	a = temp;
	j=31;
	h=33;
	while(j>0)
	{
		
		if(a & (1<<j))
		{
			h=j;
		}
		j--;
	}
	if(h==1 && (a & 1<<j)|| h==33)
	std::cout<<"\nCannot find largest!"<<std::endl;
	else{
	
	temp &= ~(1<<h);
	h--;
	temp |= (1<<h);
	reverse(&temp);
	std::cout<<"\nNext largest = \n"<<std::bitset<32>(temp);
	}
	
	
	return 0;
}


void reverse(unsigned int *temp)
{
	
	
	unsigned int tmp = *temp;
	unsigned int i=0;
	unsigned int a=1;
	*temp=0;
	while(tmp)
	{
		
	if(tmp%2)
	{
	*temp |= 1<<(31-i);	
	}	
	i++;
	tmp/=2;	
	}
}
