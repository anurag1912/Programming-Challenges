/*
A common problem for compilers and text editors is determining whether the
parentheses in a string are balanced and properly nested. For example, the string
((())())() contains properly nested pairs of parentheses, which the strings )()( and
()) do not. Give an algorithm that returns true if a string contains properly nested
and balanced parentheses, and false if otherwise. For full credit, identify the position
of the first offending parenthesis if the string is not properly nested and balanced.
*/

#include<iostream>
#include<list>
#include<string>

int checkBalanced(std::string );
struct package{
	char ch;
	unsigned int pos;
};
	
int main()
{
	//char ch[] = {'(','(','(',')',')','(',')',')','(',')'};
	std::string s;
	std::getline(std::cin, s);
	std::cout<<checkBalanced(s)<<"\n";
	//std::cout<<s<<"\n";
	return 0;
}

int checkBalanced(std::string s){

	
	if(s.length()<=1)
	{
	return -1;
	
	}
	unsigned int count =0;
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i]=='('||s[i]==')')
		count++;
	}
	struct package p[count];
	count =0;
	for(unsigned int i=0;i<s.length();i++)
	{		
	if(s[i]=='('||s[i]==')')
		{
		p[count].ch=s[i];
		p[count++].pos=i;
		}
	}
	
	std::list<package> v;
	v.push_back(p[0]);
	for(int i=1;i<count;i++)
	{
	
	if(v.back().ch=='(' && p[i].ch==')')
	v.pop_back();
	else
	v.push_back(p[i]);
	
	}
	


if(v.empty())

return 0;

else
return v.front().pos+1;
}
