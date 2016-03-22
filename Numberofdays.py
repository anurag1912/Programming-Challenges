months= [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
def noofleapyears(year,year1):
    count=0
    while year<=year1:
        if leapyear(year):
            count+=1
        year+=1
    print count
    return count
def larger(abc,abc1):
    if abc[2]>abc1[2]:
        return 1
    elif abc[2]<abc1[2]:
        return 2
    else:
        if abc[1]>abc1[1]:
            return 1
        elif abc[1]<abc1[1]:
            return 2
        else:
            if abc[0]>abc1[0]:
                return 1
            elif abc[0]<abc1[0]:
                return 2
            else:
                return 0

def leapyear(year):
    if (year%400==0 or (year%100!=0 and year%4==0)):
        return True
    else:
        return False
def validinput(abc):
    i=0
    form=[]
    month=0
    day=0
    year=0
    flag=False
    while(i<len(abc) and abc[i]!='/'):
        if(abc[i]>='0' and abc[i]<='9'):
            month= (month *10) + (ord(abc[i])-ord('0'))
        else:
            return False
        i+=1
    i+=1
    while(i<len(abc) and abc[i]!='/'):
        if(abc[i]>='0' and abc[i]<='9'):
            day= (day * 10) + (ord(abc[i])-ord('0'))
        else:
            return False
        i+=1

    i+=1
    while(i<len(abc)):
        if(abc[i]>='0' and abc[i]<='9'):
            year= (year * 10) + (ord(abc[i])-ord('0'))
        else:
            return False
        i+=1

    if (month==0 or day==0 or year==0 or month>12):
        return False
    elif(day>months[month-1]and month!=2 or (month==2 and (leapyear(year) and day>29)) or (month==2 and not (leapyear(year)) and day>28)):
        return False
    else:
        form.append(month)
        form.append(day)
        form.append(year)
        return form

abc = raw_input("Enter date in MM/DD/YYYY format: ")
abc=validinput(abc)
while abc==False:
    abc=raw_input("Try entering the date in MM/DD/YYYY format once again: ")
    abc=validinput(abc)
abc1 = raw_input("Enter date in MM/DD/YYYY format: ")
abc1=validinput(abc1)
while abc1==False:
    abc1=raw_input("Try entering the date in MM/DD/YYYY format once again: ")
    abc1=validinput(abc1)

days=0
temp=abc[0]
abc[0]=abc[1]
abc[1]=temp
temp=abc1[0]
abc1[0]=abc1[1]
abc1[1]=temp
#print abc
#print abc1
#print larger(abc,abc1)
if (larger(abc,abc1)==0):
    print "0 days"
elif(larger(abc,abc1)==2):
  #  print "in elif"
    flag=False
    if (abc1[2]==abc[2]):
        flag=True
    if(abc1[2]!=abc[2]):
        days = ((abc1[2]-abc[2]-1)*365) + noofleapyears((abc[2]+1),(abc1[2]-1)) 
    days += (months[abc[1]-1] - abc[0])
    
    temp=abc[1]
    while (temp<12 and flag==False):
        days+=months[temp]
        temp+=1
    
    temp=0
    while (temp<(abc1[1]-1) and flag==False):
        days+=months[temp]
        temp+=1
    days+=(abc1[0]-1)
    
    if flag==True:
        temp=abc[1]-1
        while(temp<(abc1[1]-2)):
            days+=months[temp]
            temp+=1
            
    if (leapyear(abc[2]) and abc[1]<=2):
        days+=1
    if (leapyear(abc1[2]) and abc1[1]>2 and flag==False):
        days+=1
    if (flag==True and abc1[1]==abc[1]):
        days = days - months[abc[1]-1]
    print "%d day(s)" %(days)
else:
    flag=False
    if (abc[2]==abc1[2]):
        flag=True
    if(abc[2]!=abc1[2]):
        days = ((abc[2]-abc1[2]-1)*365) + noofleapyears((abc1[2]+1),(abc[2]-1)) 
    days += (months[abc1[1]-1] - abc1[0])
    temp=abc1[1]
    while (temp<12 and flag==False):
        days+=months[temp]
        temp+=1

    temp=0
    
    while (temp<(abc[1]-1) and flag==False):
        days+=months[temp]
        temp+=1
    days+=(abc[0]-1)
    
    if flag==True:
        temp=abc1[1]-1
        while(temp<(abc[1]-2)):
            days+=months[temp]
            temp+=1
    
    if (leapyear(abc1[2]) and abc1[1]<=2):
        days+=1
    if (leapyear(abc[2]) and abc[1]>2 and flag==False):
        days+=1
    if (flag==True and abc1[1]==abc[1]):
        days = days - months[abc[1]-1]
    print "%d day(s)" %(days)

