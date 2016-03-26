# Find the equilibrium index of an array

arr=[2,0,0,0,0,0,0,0,1,1]
i=0
equi=len(arr)/2
sumi=0
sumj=0
j=len(arr)-1
while(i!=equi or j!=equi):
    
    
    if i<equi:
        sumi+=arr[i]
        i+=1
    if j>equi:
        sumj+=arr[j]
        j-=1
prev=-1
i=equi-1
j=equi+1
while (sumi!=sumj and equi!=prev and equi>0 and equi<len(arr)-1):
    
    if (sumi<sumj):
        sumi+=arr[equi]
        i=equi
        sumj-=arr[j]
        equi=j
        j+=1
        prev=i
    elif (sumi>sumj):
        sumj+=arr[equi]
        j=equi
        sumi-=arr[i]
        equi=i
        i-=1
        prev=j
if sumi==sumj and equi>0 and equi<len(arr)-1:
    print equi
    

else:
    print "Cannot find an equilibrium index"
    
