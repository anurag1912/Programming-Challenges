import java.util.Scanner;
import java.util.Random;
class Pile{
private int inipilesize=0;
public Pile() {
Random generator=new Random();
inipilesize=10+generator.nextInt(91);
}

public int pilesize(){
	return inipilesize;
}
public void changepilesize(int x)
{inipilesize-=x;
}
}
class Game{
private int comp=0;
private int comp1=0;
private int half=0;
private int smartorstupid=0;
private int count=0;
public  Random generate;
public Pile pil;
public Game()
{generate=new Random();
pil=new Pile();

}

public void human()
{	Scanner in=new Scanner(System.in);
int input=0;
System.out.println("Enter number of marbles you want to take from the pile:");
System.out.println("Number of marbles should atleast be 1 or half the pile!");
input=in.nextInt();
if(input==0||input>(Math.round(pil.pilesize()/2)))
{System.out.println("Incorrect input!");
System.out.println("Current pile:"+pil.pilesize());
human();
}
else{System.out.println("YOU:"+input);
	 pil.changepilesize(input);
}
}

public void dumb()
{comp=1 + generate.nextInt((int)((pil.pilesize())/2));
pil.changepilesize(comp);
System.out.println("COMPUTER:"+comp);
}
public void smart()
{
comp1=pil.pilesize();
int n=1;
while(comp1!=((int)(Math.pow(2,n))-1)&&comp1>((int)(Math.pow(2,n))-1))
{n++;

}
if(comp1==((int)(Math.pow(2,n))-1))
{comp=1 + generate.nextInt((int)((pil.pilesize())/2));
pil.changepilesize(comp);
System.out.println("COMPUTER:"+comp);
}
else{
n=1;
int takepile=0;
while(comp1>=(int)(Math.pow(2,n)))
{n++;
}
takepile=comp1-((int)(Math.pow(2,(n-1))-1));
pil.changepilesize(takepile);
System.out.println("COMPUTER:"+takepile);

}

}






public int piles(){
return pil.pilesize();
}

}
public class Nim{
	public static void main(String[] args)
	{Random generate1=new Random();
Game g=new Game();
System.out.println("Pile Size="+g.piles());
int w=generate1.nextInt(2);
int w1=generate1.nextInt(2);
		if(w==0)

		{System.out.println("YOU START!");
			while(g.piles()>1)
		{g.human();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){System.out.println("YOU WIN!");
		break;}
		else{ if(w1==0)
		{g.dumb();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){System.out.println("COMPUTER WINS");
		break;}}
		else
		{	g.smart();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){System.out.println("COMPUTER WINS");
		break;}
		}
		}
		}
		}
		else
		{System.out.println("COMPUTER STARTS!");
		while(g.piles()>1)
		{if(w1==0)
		{	g.dumb();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){System.out.println("COMPUTER WINS");
		break;}}
		else
		{g.smart();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){System.out.println("COMPUTER WINS");
		break;}
		}
		g.human();
		System.out.println("Current pile:"+g.piles());
		if(g.piles()==1){ System.out.println("YOU WIN!");
		break;}
		}
		}

	   }
  }

