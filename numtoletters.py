# Program to convert number to letters


import string
def case(c):
    if c==9:
        return "nine"
    elif c==1:
        return "one"
    elif c==2:
        return "two"
    elif c==3:
        return "three"
    elif c==4:
        return "four"
    elif c==5:
        return "five"
    elif c==6:
        return "six"
    elif c==7:
        return "seven"
    elif c==8:
        return "eight"
    elif c==10:
        return "ten"
    elif c==11:
        return "eleven"
    elif c==12:
        return "twelve"
    elif c==13:
        return "thirteen"
    elif c==14:
        return "fourteen"
    elif c==15:
        return "fifteen"
    elif c==16:
        return "sixteen"
    elif c==17:
        return "seventeen"
    elif c==18:
        return "eighteen"
    elif c==19:
        return "nineteen"
    else:
        return ''
            
def hundreds(e):
    if e==0:
        return "\0"
    s=''
    q=''
    ad = ''
    flag=False
    flag2=False
    length = len(str(e))
    while length>0:
        if length==3:
            flag=True
            length-=1
            s = s + case(e/100) + ' hundred '
            e=e%100
            
        elif (e<20):
            
            if(flag==True):
                
                if (case(e)!=''):
                     
                    s= s + 'and ' + case(e)
                flag=False
            else:
                s = s + case(e)
            length=0
        elif e>=20 and e<=90:
            
            if e>=20 and e<30:
                if flag==True:
                    ad = 'and '
                    flag=False
                q='twenty '
            elif e>=30 and e<40:
                if flag==True:
                    ad = 'and '
                    flag=False
                q = 'thirty '
            elif e>=40 and e<50:
                if flag==True:
                    ad = 'and '
                    flag=False
                q ='forty '
            elif e>=50 and e<60:
                if flag==True:
                    ad = 'and '
                    flag=False
                q = 'fifty '
            elif e>=60 and e<70:
                if flag==True:
                    ad = 'and '
                    flag=False
                q= 'sixty '
            elif e>=70 and e<80:
                if flag==True:
                    ad = 'and '
                    flag=False
                q = 'seventy '
            elif e>=80 and e<90:
                if flag==True:
                    ad = 'and '
                    flag=False
                q ='eighty '
            elif e>=90 and e<=99:
                if flag==True:
                    ad = 'and '
                    flag=False
                q = 'ninety '
            length-=1
            e=e%10
            s =s + ad + q

        else:
            
            s = s + case(e)
    
    return s   
        
        
        
while True:
    try:
        num = raw_input("Enter integer ")
        num1=len(num)
        num = string.atoi(num)
        break
    except ValueError:
        print "Not an integer, please try again!!!"
alist=[]
i=0
while num>0:
    alist.append(num%1000)
    num = num/1000
    alist[i]=hundreds(alist[i])
    i+=1

i = len(alist)
i-=1
flag=False
j=0
while (alist[j]=='\0' and j<=i):
    j+=1
     
while i>=0:
    if (10**((i)*3)) == (10 ** 18):
        if alist[i]!='\0':
            flag=True
            print alist[i], 'quintillion',
        i-=1
    elif (10**((i)*3)) == (10 ** 15):
        if alist[i]!='\0':
            if flag == True and i!=j:
                print ',', alist[i], 'quadrillion',
            else:
                if i == j:
                    print 'and', 
                print alist[i], 'quadrillion',
            flag=True
        i-=1
    elif(10**((i)*3)) == (10 ** 12):
        if alist[i]!='\0':
        
            if flag == True and i!=j:
                print ',', alist[i], 'trillion',
            else:
                if i==j:
                    print 'and',
                print alist[i], 'trillion',
            flag=True
        i-=1
        
    elif(10**((i)*3)) == (10 ** 9):
        if alist[i]!='\0':
            if flag == True and i!=j:
                print ',', alist[i], 'billion',
            else:
                if i==j:
                    print 'and',
                print alist[i], 'billion',
            
            flag=True
        i-=1
        
    elif(10**((i)*3)) == (10 ** 6):
        if alist[i]!='\0':
            if flag==True and i!=j:
                print ',', alist[i], 'million',
            else:
                if i==j:
                    print 'and',
                print alist[i], 'million',
            flag=True
        i-=1
    elif(10**((i)*3)) == (10 ** 3):
        if alist[i]!='\0':
            if flag==True and i!=j:
                print ',', alist[i], 'thousand',
            else:
                if i==j:
                    print 'and',
                print alist[i], 'thousand',
            flag = True
        i-=1
    elif(10**((i)*3)) >= (10 ** 0):
        if alist[i]!='\0':
            if flag == True and i!=j:
                print ',' ,alist[i],
            else:
                if i==j:
                    print 'and',
                print alist[i]
        i-=1
    
