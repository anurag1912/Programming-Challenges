import java.util.Scanner;
class TicTac{
private boolean flag=false;
private final int rows=3;
private final int columns=3;
private String[][] a=new String[rows][columns];
public TicTac(){
	for(int i=0;i<rows;i++)
	{for(int j=0;j<columns;j++)
	a[i][j]=" ";
	}
}
public void dispboard(){
for(int i=0;i<rows;i++)
{
System.out.print("|");
for(int j=0;j<columns;j++)
{System.out.print(" "+a[i][j]+" "+"|");

}
System.out.println();


}
}
public void inputboard(int row,int column, String ch){
	a[row-1][column-1]=ch;
}
public boolean getwinner(){
String str1="x";
String str2="o";
for(int i=0;i<rows;i++)
{int j=0;
if(a[i][j].equalsIgnoreCase(str1)&&a[i][j+1].equalsIgnoreCase(str1)&&a[i][j+2].equalsIgnoreCase(str1)||a[i][j].equalsIgnoreCase(str2)&&a[i][j+1].equalsIgnoreCase(str2)&&a[i][j+2].equalsIgnoreCase(str2))
{flag=true;}
}

for(int j=0;j<columns;j++)
{int i=0;
if(a[i][j].equalsIgnoreCase(str1)&&a[i+1][j].equalsIgnoreCase(str1)&&a[i+2][j].equalsIgnoreCase(str1)||a[i][j].equalsIgnoreCase(str2)&&a[i+1][j].equalsIgnoreCase(str2)&&a[i+2][j].equalsIgnoreCase(str2))
{flag=true;}


}

int k=0;
if(a[k][k].equalsIgnoreCase(str1)&&a[k+1][k+1].equalsIgnoreCase(str1)&&a[k+2][k+2].equalsIgnoreCase(str1)||a[k][k].equalsIgnoreCase(str2)&&a[k+1][k+1].equalsIgnoreCase(str2)&&a[k+2][k+2].equalsIgnoreCase(str2))
{flag=true;}

int l=0;
int m=2;
if(a[l][m].equalsIgnoreCase(str1)&&a[l+1][m-1].equalsIgnoreCase(str1)&&a[l+2][m-2].equalsIgnoreCase(str1)||a[l][m].equalsIgnoreCase(str2)&&a[l+1][m-1].equalsIgnoreCase(str2)&&a[l+2][m-2].equalsIgnoreCase(str2))
{flag=true;}

if(flag==true)
return true;
else
return false;
}
public boolean noonewins(){
int flag1=0;
int c=0;
int b=0;
for(c=0;c<rows;c++)
{for(b=0;b<columns;b++)
{if(a[c][b]==" ")
{flag1=2;
 }
}
}

if(flag1==2)
return false;
else return true;
 }
}




public class tictactoe{
	public static void main(String[] args){
	TicTac game=new TicTac();
Scanner in=new Scanner(System.in);

		boolean done=false;
		while(!done){
			boolean noone1=false;
            noone1=game.noonewins();
            if(noone1==true)
            {System.out.println("NO ONE WINS!");
            	break;
            }

		System.out.println("Player 1!");
		 System.out.println("Enter row"+" "+"0 to exit!");
		   int row1=in.nextInt();
		   if(row1<=0) break;
		  System.out.println("Enter column!"+" "+"0 to exit!");
		 int column1=in.nextInt();
		 if(column1<=0) break;
		 String ch="X";
		game.inputboard(row1,column1,ch);
		game.dispboard();
		boolean bool=false;
		bool=game.getwinner();
		if(bool== true)
		{System.out.println("Player 1 WINS!!!");
		break;
		}
			boolean noone=false;
            noone= game.noonewins();
            if(noone==true)
            {System.out.println("NO ONE WINS!");
            break;
            }
			System.out.println("Player 2!");
		 System.out.println("Enter row!"+" "+"0 to exit!");
		  int row2=in.nextInt();
		  if(row2<=0) break;
		System.out.println("Enter column!"+" "+"0 to exit!");
		 int column2=in.nextInt();
		 if(column2<=0) break;
		 String ch2="O";
		game.inputboard(row2,column2,ch2);
		game.dispboard();
		boolean bool1=false;
		bool1=game.getwinner();
		if(bool1== true)
		{System.out.println("Player 2 WINS!!!");
		break;
		}

		}
	}
}
