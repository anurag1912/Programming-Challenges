import java.util.Scanner;
public class magicsquare{
	public static void main(String[] args){
System.out.println("Enter size of magic square");
Scanner in=new Scanner(System.in);
int n=in.nextInt();
int arr[]=new int[n*n];
for(int i=0;i<n*n;i++)
arr[i]= i+1;

int magic[][]=new int[n][n];
magic[0][n/2]=arr[0];
int count=(n*n)-1;
int prevr=0;
int prevc=0;
int r=0;
int c=n/2;
int index=1;

while(count>0){
prevr=r;
prevc=c;
r--; c++;
if(r<0&&c>(n-1))
{r=n-1;
c=0;
}
else if(r<0)
r=n-1;

else if(c>(n-1))
c=0;

else
{r=r;
c=c;
}
if(magic[r][c]==0)
{magic[r][c]=arr[index];
index++;
count--;

}
else
{prevr+=1;
magic[prevr][prevc]=arr[index];
index++;
count--;
r=prevr;
c=prevc;
}

}
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{System.out.print(magic[i][j]+"   ");}

System.out.println();
}
	}
}
