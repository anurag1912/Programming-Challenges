#include<iostream>
#include<math.h>
#define ARR_LENGTH 512


/** Imagine you are reading in a stream of integers. Periodically, you wish to be able
* to look up the rank of a number x (the number of values less than or equal tox).
* Implement the data structures and algorithms to support these operations.That
* is, implement the method track(int x), which is called when each number
* is generated, and the method getRankOfNumber(int x), which returns the
* number of values less than or equal to x (not including x itself).
* EXAMPLE
* Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3
* getRankOfNumber(l) = 0
* getRankOfNumber(3) = 1
* getRankOfNumber(4) = 3

*/

struct s{
	int self;
	int less;
};
void track(int, int,struct s *);
int getRankofNumber(int x, int arr_len,struct s *arr);
int main()
{	struct s arr[ARR_LENGTH] = {0,0};
	int in[] = {5,1,4,4,5,9,7,13,3};
	//int in[] = {63};
	for(int i=0;i<9;i++)
	track(in[i], ARR_LENGTH-1, arr);
	for(int i=0;i<ARR_LENGTH;i++)	
	if(arr[i].self>=1||arr[i].less>=1)
	std::cout<<i<<": "<<arr[i].self<<"  "<<arr[i].less<<"\n";
	std::cout<<"\n";
	std::cout<<getRankofNumber(1, ARR_LENGTH-1, arr)<<"\n";
	std::cout<<getRankofNumber(3, ARR_LENGTH-1, arr)<<"\n";
	std::cout<<getRankofNumber(4, ARR_LENGTH-1, arr)<<"\n";
	std::cout<<getRankofNumber(13, ARR_LENGTH-1, arr)<<"\n";
	return 0;
}


void track(int x, int arr_len, struct s *arr){

		int result=0;
		int power=0;
		do
		{
			result = pow(2,power);
			power++;
		}
		while(result<=x);
		if(result<=(arr_len))
		{
		arr[result].less++;
		}
	
		result = result/2;
		x = x - result;
		arr_len = result*2-result-1;
		
		if(x!=0)
			
			track(x, arr_len, (arr+result));
			
		else
			arr[result].self++;
		}

int getRankofNumber(int x, int arr_len,struct s *arr){
		int result=0;
		int power=0;
		int sum=0;
		while(result<=x)
		{	
			result = pow(2,power);
			if(result>x)
			break;
			sum+=arr[result].less;
			//std::cout<<"Result = "<<result<<std::endl;
			//std::cout<<"Value = "<<arr[result].less<<std::endl;
			power++;
		}
		
		result = result/2;
		
		x = x - result;
		arr_len = result*2-result-1;
		if(x!=0)
			
			return (sum += getRankofNumber(x, arr_len, (arr+result)));
		
		
		
		else
			{
				if(arr[result].self>1)
				{ 	//std::cout<<"Result = "<<result<<std::endl;
					//std::cout<<"Value = "<<arr[result].self<<std::endl;
					 sum += arr[result].self-1;
					 return sum;
				}
				else
					return 0;
			}
