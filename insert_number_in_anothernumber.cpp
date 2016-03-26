/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write
a method to insert M into N such that M starts at bit j and ends at bit i. You can
assume that the bits j through i have enough space to fit all of M. That is, if
M = 10011, you can assume that there are at least 5 bits between j and i. You
would not, for example, have j = 3 and i = 2, because M could not fully fit
between bit 3 and bit 2.
EXAMPLE
Input: N = 10000000000, M = 10011, i = 2, j = 6
Output: N = 10001001100

*/

#include<iostream>

int main()
{
	
	unsigned long a,b;
	unsigned int i,j;
	i=j=0;
	std::cout<<"Enter a and b"<<std::endl;
	std::cin>>a>>b;
	std::cout<<"Enter i and j"<<std::endl;
	std::cin>>i>>j;
	if((j+i)>31 || j<i)
	{
	std::cout<<"Invalid input, exiting..."<<std::endl;
	return 1;
	}
	else{
	
	a = a | (b<<i);
	std::cout<<a<<std::endl;
	}
	return 0;
	
}
