/*
Given a sorted array of strings which is interspersed with empty strings, write a
method to find the location of a given string.
EXAMPLE
Input: find "ball" in {"at", "", "", "", "ball", "", "", "car","","","dad","",""}

Output: 4
*/
#include<iostream>
#include<string>

int searchstring(std::string arr[],int low, int high, std::string search);

int main()
{
	
	std::string arr[13] = {"at", "", "", "", "ball", "", "", "car","","","dad","",""};
	std::string search = "ball";
	
	int index = searchstring(arr,0,12,search);
	std::cout<<index<<std::endl;
	
	return 0;
}

int searchstring(std::string arr[],int low, int high, std::string search){
	if(high<low)
	return -1;
	int mid = (high + low)/2;
	if(arr[mid]==""){
		
		int index = searchstring(arr,low,mid-1,search);
		if(index==-1)
		index=searchstring(arr,mid+1,high,search);
		return index;	
			
		
	}
	
	
	else{
		
	if(arr[mid]==search)	
		return mid;
	else if(search.compare(arr[mid])<0)			//search<arr[mid]
		return(searchstring(arr,low,mid-1,search));
	else
		return(searchstring(arr,mid+1,high,search));
		
		
	}
	
}
