/*
Write a function to determine the number of bits required to convert integer A
to integer B.
EXAMPLE
Input: 31,14
Output: 2

*/

#include<iostream>
#include<bitset>
int main()
{
	unsigned int a,b;
	std::cout<<"Enter two numbers!";
	std::cin>>a>>b;
	a = a^b;
	int j=0, count =0;
//	std::cout<<std::bitset<32>(a)<<std::endl;
	while(a)
	{
		if(a & (1<<j)){
			a = a & ~(1<<j);
			count++;
			
		}
		j++;
//	std::cout<<std::bitset<32>(a)<<std::endl;
	}
	std::cout<<count<<std::endl;
	
	
	
	return 0;
}
