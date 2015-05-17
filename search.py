
import numpy
edges = numpy.zeros((201,201))
cost = numpy.zeros(201)
flags = numpy.zeros(201)
nodes = 1
def getKey(item):
    return item[1] 
def djikshtra(parent):
    checked = 1
    global edges
    global cost
    global flags
    global nodes
    kyu = [parent]
    perm =[0]
    while checked <=nodes:
       
        if flags[kyu[0]]== 0:
            
            smaller=[]
            flags[kyu[0]] = 1
            checked  = checked + 1
            for daughter in range(0, nodes):
                current = 0 
                if edges[kyu[0],daughter]!= 1000000 and edges[kyu[0],daughter]!= 0:
                    
                    current = perm[0] + edges[kyu[0],daughter]
                    smaller.append([daughter,current])
                    smaller = sorted(smaller, key = getKey)
                    if current < cost[daughter]:
                        cost[daughter] = current
                    
                        
            
            del(kyu[0])
            del(perm[0])
            for  j in range (0,len(kyu)):
                smaller.append([kyu[j],perm[j]])
                
            smaller = sorted(smaller, key = getKey)
            kyu = map(lambda x:x[0],smaller)
            perm = map(lambda x:x[1],smaller)
        else:
            
            del(kyu[0])
            del(perm[0])
            
            
        if len(kyu) == 0:
            checked = checked +1
            
        
        
            


with open('dijkstraData.txt','r') as f:
    for line in f:
        nodes = nodes + 1
        word =line.split()
        vertex = int(word[0])
        for word in line.split():
            
            a = word.split(",")
            if int(a[0])!= vertex:
                edges[vertex,int(a[0])] = int(a[1])
                edges[int(a[0]),vertex] = int(a[1])
#print nodes

start = 1
for i in range(0, nodes):
    if i!=start:
        cost[i]= 1000000
    for j in range(1 , nodes):
        if i != j:
            if edges[i,j] == 0:
                edges[i,j] = 1000000
            


djikshtra(start)



#print flags
lol = [7,37,59,82,99,115,133,165,188,197]
#lol = [10,30,50,80,90,110,130,160,180,190]
for i in lol:
    print int(cost[i])

print cost
