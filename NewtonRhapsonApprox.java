import java.util.Scanner;
class Calculator{
private double a=0;
private double power=0;
private double epsilon=1E-14;
private double e1=0;
private double e=0;
	public Calculator()
	{System.out.println("Enter number whose roots are to be calculated:");
	Scanner in=new Scanner(System.in);
	a=in.nextDouble();
	System.out.println("Enter power");
	power=in.nextDouble();
	roots();
	}
public void roots()
{double x=1;
double x1=1;
double derivative=0;
double derivative1=0;
for(int i=0;;i++)
{x=x1;
derivative=power*(Math.pow(x,(power-1)));
x=x-((Math.pow(x,power)-a)/(derivative));
x1=x;
derivative1=power*(Math.pow(x1,(power-1)));
x1=x1-((Math.pow(x1,power)-a)/(derivative1));

e1=Math.abs(x1);
 e=Math.abs(x);
if(isapprox(e1,e)==true)
break;
}

System.out.println("Root of the equation is: "+Math.abs(x1));

}
public boolean isapprox(double c1,double c)
{return (Math.abs(c1-c)<=epsilon);
}

}

public class newtonraphsonapprox{
	public static void main(String[] args){
		Calculator c=new Calculator();

	}
}
