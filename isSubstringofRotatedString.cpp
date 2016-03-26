/*
Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check
if s2 is a rotation of s1 using only one call to isSubstring (eg. "waterbottle" is a rotation of "erbottlewat").
*/


#include<iostream>
#include<string>
int main(){
	std::string s1,s2;
	std::cout<<"Enter the strings: ";
	std::cin>>s1;
	std::cin>>s2;
	s1=s1+s1;
	std::cout<<s1<<std::endl;
	std::size_t found = s1.find(s2);
	if (found!=std::string::npos)
	std::cout<<"s2 is a rotation of s1";
	else
	std::cout<<"Not a rotation!";
	
	
	
	return 0;
}
