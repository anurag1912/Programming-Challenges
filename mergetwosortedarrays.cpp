/*
You are given two sorted arrays, A and B, where A has a large enough buffer at
the end to hold B. Write a method to merge B into A in sorted order.
*/

#include<iostream>

int main()
{
 int a[] = {1,1,1,1,65000,0,0,0,0,0};
 int b[] = {-1,-1,-1,-1,2};
int end = 9;
 int _b=4;
 int _a = 4;	
 while(_a>=0 && _b>=0)
 {
 	if(b[_b]>a[_a])
 	{
	 a[end] = b[_b];
	 _b--;

	}
 	else
 	{
	 a[end] = a[_a];
	 _a--;
	
 	}
	 end--;
}	
if(_b>=0)
{
	for(int i=0;i<=_b;i++)
	a[i] = b[i];	
}
for(int i=0;i<10;i++)
{
std::cout<<a[i]<<" ";	
}	

	return 0;
}
