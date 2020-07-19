def selection_sort(u):
   temp = 0
   for x in range(0,len(u)):
      mini = x
      for i in range(mini,len(u)):
         if u[i]<u[mini]:
            temp = u[i]
            u[i] = u[mini]
            u[mini] = temp
   return True

def heapify(u):
   if len(u)<=1:
      return u
   for x in range(0,len(u)):
      temp = u[0]
      u[0] = u[x]
      u[x] = temp
      reheapify(u,x)   
   return True

def reheapify(u,end):
   swapped = False
   child = 0
   parent = 0
   while True:
      swapped = False 
      for i in range(end-1,-1,-1):
         child = i
         parent = (i+1)//2 -1 
         if u[child] > u[parent]:
            temp = u[child]
            u[child] = u[parent]
            u[parent] = temp
            swapped = True 
      if swapped == False:
         break
   return True

def heap_sort(u):
   heapify(u)
   count = len(u)
   for i in range(len(u)-1,0,-1):
      temp = u[0]
      u[0] = u[i]
      u[i] = temp
      reheapify(u,i)
   return True 
      
      
def merge_sort(u):
   merged = list(helper_merge_sort(u))
   for i in range(0,len(u)):
      u[i] = merged[i]
   return True 

def helper_merge_sort(u):
   if len(u)<=1:
      return u
   UL = helper_merge_sort(u[len(u)//2:]) 
   LL = helper_merge_sort(u[:len(u)//2])
   u = helper_merge(UL, LL)
   return u

def helper_merge(L1, L2):
   merged = []
   while (len(L1)!=0 and len(L2)!=0):
      if L1[0]>L2[0]:
         merged = merged+[L2[0]]
         L2 = L2[1:]
      else:
         merged = merged + [L1[0]]
         L1 = L1[1:]
   while len(L1)!=0:
      merged = merged + [L1[0]]
      L1 = L1[1:]
   while len(L2)!=0:
      merged = merged + [L2[0]]
      L2 = L2[1:]
   return merged 

def quick_sort(u, ini, fin):
   if (fin-ini)>0:
      p = partition(u, ini, fin)
      quick_sort(u, ini, p-1)
      quick_sort(u, p+1, fin)
   return True 

def partition(u, ini,fin):
   p = fin
   pivot = ini
   for i in range(ini,fin):
      if u[i]<u[p]:
         temp = u[i]
         u[i] = u[pivot]
         u[pivot] = temp 
         pivot=pivot+1
   temp = u[p]
   u[p] = u[pivot]
   u[pivot] = temp
   return pivot 
