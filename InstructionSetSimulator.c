/* Simple instruction set simulator for RISC architectures. Basic instructions such as MOV, ADD, JMP ,JE, LD and ST implemented. The
simulator also counts executed instructions, number of hits to local memory, and number of load/store instructions.
*/

#include<stdio.h>
#include<stdlib.h>


FILE *fp;
char flag;
int r1, r2, r3, r4, r5, r6, memhitormiss;
void MOV(int *reg ,int no);
void ADD(int*reg, int*reg1);
void JMP(char ch);
void CMP(int *, int *);
void JE(char ch);
void LD(int*, int*, int[]);
void ST(int*, int*, int[]);
int totinstructions();
int clkcycles;

int main(int argc, char *argv[])
{if(argc!=2)
{printf("Incorrect number of arguments\n");
exit(9);
}
  fp = fopen(argv[1], "r");
if(fp==NULL)
{printf("Error opening file!\n");
exit(1);
}
clkcycles=0;
flag =0;
r1=r2=r3=r4=r5=r6=0;
memhitormiss=0;
int value=1;
int localmem[256];
int i=0;
for(i;i<256;i++)
localmem[i]=128;
int executedinstr=0;
int number=0;
int *addrreg, *addrreg2;
int ldstno=0;
char ch;
ch=fgetc(fp);

while(ch!=EOF)
{ 
	
	while(ch != 'M'&&ch!='A'&&ch!='J'&&ch!='L'&&ch!='S'&&ch!='C' && ch!=EOF)
	  ch=fgetc(fp);
	if(ch==EOF) break;
	switch(ch)
	{
		case 'M':
		
			executedinstr++;
		while(ch!='R')
		  ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg = &r1;
				break;
			case '2':
				addrreg = &r2;
				break;
			case '3':
				addrreg = &r3;
				break;
			case '4':
				addrreg = &r4;
				break;
			case '5':
				addrreg = &r5;
				break;
			case '6':
				addrreg = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(1);
				break;			
		}
		ch=fgetc(fp);
		
		while((ch<'0'||ch>'9')&&ch!='-')
		  ch=fgetc(fp);
		if(ch=='-')
		{value = -1;
		ch=fgetc(fp);
	}
	else value = 1;
		while(ch!='\n'&&ch!=EOF && ch!='\r' && ch!=' ')
		{number = (number * 10) + (ch - '0');
		ch = fgetc(fp);
		}
		number = number * value;
		MOV(addrreg,number);
		number=0;
		value=1;
		break;
		
		
		case 'A':{
			
		
			
			executedinstr++;
			while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg = &r1;
				break;
			case '2':
				addrreg = &r2;
				break;
			case '3':
				addrreg = &r3;
				break;
			case '4':
				addrreg = &r4;
				break;
			case '5':
				addrreg = &r5;
				break;
			case '6':
				addrreg = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		ch = fgetc(fp);
		
		while((ch<'0'||ch>'9')&&ch!='R'&& ch!='-')
		ch=fgetc(fp);
		
		if(ch=='R') {
		ch = fgetc(fp);
		switch(ch)
		{
			case '1':
				addrreg2 = &r1;
				break;
			case '2':
				addrreg2 = &r2;
				break;
			case '3':
				addrreg2 = &r3;
				break;
			case '4':
				addrreg2 = &r4;
				break;
			case '5':
				addrreg2 = &r5;
				break;
			case '6':
				addrreg2 = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(42);
				break;			
		}
		
		ADD(addrreg, addrreg2);
		
		}
		else if(ch=='-')
		{while(ch!='\n'&&ch!=EOF && ch!='\r')
		{number = (number * 10) + (ch - '0');
		ch=fgetc(fp);
		}	
		number*=-1;	
		*addrreg+=number;
		number=0;
		clkcycles++;	
		}	
		
		else if(ch>='0'&&ch<='9')
		{while(ch!='\n'&&ch!=EOF &&ch!='\r')
		{number = (number * 10) + (ch - '0');
		ch=fgetc(fp);
		}		
		*addrreg+=number;
		
		number=0;
		clkcycles++;
			
			
		}	
			break;
			
			
		case 'J':
		
			executedinstr++;
			ch = fgetc(fp);
			if(ch=='M')
			{
			JMP(ch);
			
			}
			else if(ch=='E')
			{
			JE(ch);}
			else {printf("Incorrect instruction..exiting!\n");
			exit(3);
			}
			break;
		case 'L': 
		
		ldstno++;
		executedinstr++;
		while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg = &r1;
				break;
			case '2':
				addrreg = &r2;
				break;
			case '3':
				addrreg = &r3;
				break;
			case '4':
				addrreg = &r4;
				break;
			case '5':
				addrreg = &r5;
				break;
			case '6':
				addrreg = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg2 = &r1;
				break;
			case '2':
				addrreg2 = &r2;
				break;
			case '3':
				addrreg2 = &r3;
				break;
			case '4':
				addrreg2 = &r4;
				break;
			case '5':
				addrreg2 = &r5;
				break;
			case '6':
				addrreg2 = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		
		LD(addrreg, addrreg2, localmem);
			break;
		case 'S':
			
			executedinstr++;
			ldstno++;
			while(ch!='R')
		ch=fgetc(fp);
		
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg = &r1;
				break;
			case '2':
				addrreg = &r2;
				break;
			case '3':
				addrreg = &r3;
				break;
			case '4':
				addrreg = &r4;
				break;
			case '5':
				addrreg = &r5;
				break;
			case '6':
				addrreg = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg2 = &r1;
				break;
			case '2':
				addrreg2 = &r2;
				break;
			case '3':
				addrreg2 = &r3;
				break;
			case '4':
				addrreg2 = &r4;
				break;
			case '5':
				addrreg2 = &r5;
				break;
			case '6':
				addrreg2 = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		
		ST(addrreg, addrreg2,localmem);
			 break;
		case 'C':
			
			executedinstr++;
			while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg = &r1;
				break;
			case '2':
				addrreg = &r2;
				break;
			case '3':
				addrreg = &r3;
				break;
			case '4':
				addrreg = &r4;
				break;
			case '5':
				addrreg = &r5;
				break;
			case '6':
				addrreg = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		while(ch!='R')
		ch=fgetc(fp);
	
		ch=fgetc(fp);
	
		switch(ch)
		{
			case '1':
				addrreg2 = &r1;
				break;
			case '2':
				addrreg2 = &r2;
				break;
			case '3':
				addrreg2 = &r3;
				break;
			case '4':
				addrreg2 = &r4;
				break;
			case '5':
				addrreg2 = &r5;
				break;
			case '6':
				addrreg2 = &r6;
				break;
			default: 
				printf("Incorrect arguments!\n");
				exit(2);
				break;			
		}
		
		CMP(addrreg, addrreg2);
			break;
		default:
			break;	
	}
	
	
	
	
}
ch = fgetc(fp);	
}
printf("Total number of instructions in the code: %d\n",totinstructions());
	printf("Total number of executed instructions: %d\n",executedinstr);
	printf("Total number of clock cycles: %d\n",clkcycles);
	printf("Number of hits to local memory: %d\n",memhitormiss);
	printf("Total number of executed LD/ST instructions: %d\n", ldstno);
	

return 0;
}


void MOV(int *addrreg, int no)
{    clkcycles+=1;
	*addrreg=no;
	
}

void ADD(int *reg, int *reg2)
	 {
	 clkcycles+=1;
*reg+=*reg2;
	
}
void JMP(char ch)
{
  int number =0;
  int number2=0;
  clkcycles+=1;
  while(ch<'0'||ch>'9')
    ch=fgetc(fp);
  while(ch!='\n'&&ch!=EOF && ch!='\r')
  {
    number = (number * 10) + (ch - '0');
    ch = fgetc(fp);
  }

	
  rewind(fp);
  while(number!=number2)
  {
    ch=fgetc(fp);
    while(ch>='0'&&ch<='9')
    {
      number2 = (number2 * 10) + (ch - '0');
      ch = fgetc(fp);
    }
    
    if(number==number2) 
      break;
    else
    {
    
      while(ch!='\n'){
	ch=fgetc(fp);
      }
      number2=0;	
    }

	  
  }

}

void CMP(int *reg, int *reg2)
{clkcycles+=2;
if(*reg==*reg2)
flag=1;
else flag=0;
}

void JE(char ch)
{clkcycles+=1;
if(flag==1)
{
int number =0;
int number2=0;

while(ch<'0'||ch>'9')
ch=fgetc(fp);
while(ch!='\n'&&ch!=EOF && ch!='\r')
		{number = (number * 10) + (ch - '0');
		ch = fgetc(fp);
		}
	
	rewind(fp);
	
	while(number!=number2)
	{ch=fgetc(fp);
	while(ch>='0'&&ch<='9')
	{number2 = (number2 * 10) + (ch - '0');
		ch = fgetc(fp);
	}
	
	if(number==number2) 
		break;

	else
	{while(ch!='\n')
	ch=fgetc(fp);
	number2=0;	
	}	
		
	}
}
flag=0;
}

void LD(int *reg1, int *reg2, int localmem[])
{*reg1=localmem[0+ (*reg2)];

if(localmem[0+ (*reg2)]!=128)
{
clkcycles+=3;
memhitormiss++;

}
else
{
clkcycles+=50;

}

	
}

void ST(int *reg1, int *reg2, int localmem[])
{
if(localmem[0 + *reg1] !=128)
{
clkcycles+=3;
memhitormiss++;
}
else

clkcycles+=50;

localmem[0 + *reg1] = *reg2;

	
	
}
int totinstructions()
{rewind(fp);
int count=0;
char ch;
ch=fgetc(fp);
while(ch!=EOF)
{while(ch!='\n'&&ch!=EOF)
	ch=fgetc(fp);


count++;
ch=fgetc(fp);
}
return count;
}
