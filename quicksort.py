import numpy 
#start_time = time.clock()
#sys.setrecursionlimit(4492)
count = 0
def median(lst,left,middle,right):

    temp =int( numpy.median(numpy.array(lst)))
    
    if temp == lst[0]:
        return left
    elif temp == lst[2]:
        return right
    elif temp == lst[1]:
        return middle
    

def quick_sort(a,left,right):
    global count
    if (((right-left) < 1) or (left < 0) or (right > (len(a)-1))):
        return 1
    middle = int((right+left)//2)
    pivot = median([a[left],a[middle],a[right]],left,middle,right)
   # pivot = right
    p_ele=a[pivot]
    a[left],a[pivot]= a[pivot],a[left]
    count = count + right - left 
    i = left + 1
    leng = len(a) 
    for j in range(left+1,right+1):
        if p_ele>a[j]:
            a[j],a[i]= a[i],a[j]
            i = i+1

    a[left],a[i-1]= a[i-1],a[left]
    quick_sort(a,left,i-2)
    quick_sort(a,i,right)
    return 1


f = open("C:\Users\saunair\Contacts\Desktop\dsa\QuickSort.txt","r")
input = [int(line.rstrip()) for line in f]
#input=[3,9,8,4,6,10,2,5,7,1]
quick_sort(input,0,len(input)-1)
#print input[:]
print count
