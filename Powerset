/*
 Powerset: -Implement a method that takes as input a set S of distinct elements, and prints the power set of S. 
 Print the subsets one per line, with elements separated by commas. 
 Definition of power set: https://en.wikipedia.org/wiki/Power_set
*/


#include<iostream>
#include<string>

void powerset(char *, std::string);


int main()
{	unsigned int length=0;
	char s[] = "ABCD";
	while(s[length]){
		length++;
	}
	
	char *ptr = s;
	std::cout<<"NULL"<<std::endl;
	for(unsigned int i=0;i<length-1;i++)
	{
	std::string s1;
	s1+=*(ptr+i);
	powerset(ptr+i+1,s1);
	}
	std::cout<<*(ptr+length-1);	
	return 0;
}



void powerset(char *ptr, std::string s)
{
std::cout<<s<<std::endl;
	while(*ptr!='\0')
	{	std::string s2;
		s2+=s;
		s2+=',';
		s2+=(*ptr);
		ptr+=1;
		powerset(ptr, s2);
		
	}
}
