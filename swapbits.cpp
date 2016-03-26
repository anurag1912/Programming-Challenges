/*Write a program to swap odd and even bits in an integer with as few instructions
as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and
soon).

*/
#include <iostream>
#include<bitset>

int main()
{	unsigned int a = 73;
	std::cout<<std::bitset<32>(a)<<std::endl;
	unsigned int b = 0x5555;
	unsigned int c = b<<1;
	unsigned int temp=a;
	a=a>>1;
	temp = temp<<1;
	a = a & b | temp & c;
	
	std::cout<<std::bitset<32>(a)<<std::endl;
	
	
	
	return 0;
}
